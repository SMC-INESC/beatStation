beatStation
===========

beatStation - an openFrameworks tapping recorder

This work is licensed under the Creative Commons Attribution-NonCommercial 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/3.0/.

This work is partly-funded by the ERDF - European Regional Development Fund through the COMPETE Programme (operational program for competitiveness) and by National Funds through the FCT-  Fundacao para a Ciencia e a Tecnologia (Portuguese Foundation for Science and Technology) within project "PTDC/EAT-MMU/112255/2009-(FCOM-01-0124-FEDER-014732)"

========================
USAGE
========================

The already build binaries can be download from http://github.com/SMC-INESC/beatStation/releases

Download the archive and extract/copy the directory on your local hard drive. 

Before starting the app you need to copy 2 or more sound files to annotate in the data/sounds/ subdirectory. 

You can also adjust different settings from the settings file. Take a look at the wiki page for more info. For instance, you can choose to tap with a midi interface or just use the keyboard. 

beatStation was designed as a game with a purpose application in which users can compete against each other in tapping various songs. In this setup, you need to have Octave or Matlab installed in order to compute the score for each user.

beatStation can be used by researchers to annotate audio, conduct experiments, or as an inspiration for future apps.

Contact me at miron.marius [at] gmail [dot] com for future questions


========================
BUILDING 
========================

These are the MAC OSX and Windows versions. for the Linux version go at https://github.com/nkundiushuti/beatStationLinux

========================
MACOS BUILD
========================

You will need Mac Os version minimum 10.6 and XCode if you want to build the project again on your machine. You will also need the version 0.7.1 of openFrameworks. It is not likely that the latest version of openFrameworks will work with this app.
The .app that you can find in the bin directory was built on Mac OS Lion and I suggest rebuilding it on your system. 
You need to download openFrameworks and copy the beatStation directory into the /apps/myapps directory and then build it with Xcode (open and build beatStation.xcodeproj) and run it.

========================
WINDOWS BUILD
========================

You will need to have Codeblocks 10 installed.
Download and install openframeworks 0.7.1 for Linux and Codeblocks as specified on the website.
Building DOES NOT work with later versions of Openframeworks or Codeblocks 
Unpack addons.zip or download from GitHub and copy in the openframeworks addons directory(not the project addons!), the following addons:
- ofxUI
- ofxXMLSettings
- ofxDirList
- ofxTextSuite
- ofxNetwork

Copy the beatStation directory in the apps/myapps directory, open the code blocks project(beatStation.cbp) and CLEAN then BUILD.


IMPORTANT - you must copy some audio files in the sounds directory before starting the app


========================
FUNCTIONALITIES
========================

The app has a user management system and a tapping recording system, as well as an ability to run tests on different machines connected in a client-server architecture. 

USER MANAGEMENT
- recorded in the data/users.xml folder
- each new user is required to enter the name, then a new ID is generated based on the name(ex: john doe - jd1 - the first user with the jd initials), plus a unique index id for each user. 
- an existing user can log-in using the ID 
- all the tappings will be stored in the data directory, in filenames corresponding to the user id, e.g. jd1.xml

TAP RECORDING
- once logged an user can listen to a song with PLAY, move to the next song with NEXT
- tappings are recorded in a vector for each song
- a user can always quit pressing QUIT button
- tappings are saved in an XML named with the user's ID each time a user hits quit or he finishes the tapping
- instructions are displayed with the INSTRUCTIONS button
- volume can be adjusted with the VOL slider
- the percentage played from a song can be seen in the rotary slider POS

CLIENT - SERVER ARCHITECTURE
- a user can log-in with the same id on the server and all clients machines
- by default, an app runs as a server if not changed from the settings.xml (isClient=1)
- if the server, all users are stored on the users.xml file
- if client, the authentication happens on the server machine
- the server must be started in order for the clients to connect and authentication to take place
- tappings are stored locally on clients and server

THE SETTINGS FILE
Several parameters can be modified using the settings.xml file
<settings>

    <passToExit>exit</passToExit> the password used to exit the app

    <verbose>1</verbose> more output on the connectivity between clients and server

    <fullscreen>1</fullscreen> the app runs fullscreen

    <fps>1000</fps> frames per second to run: more fps less delay but more computationally expensive

    <midiPort>0</midiPort> - the midi port to run

    <midiChannel>0</midiChannel> - the midi channel to listen to

    <midiNote>0</midiNote> - the midi note which will trigger a tap

    <noPlays>2</noPlays> - maximum number of times you can listen a song

    <minTaps>1</minTaps> - minimum number of song tapped after which the score is displayed
    
    <randomFiles>1</randomFiles> - play the file in an unique random order for each user

    <tapWithSpace>1</tapWithSpace>

    <tapWithTab>1</tapWithTab>

    <canQuit>1</canQuit> - set this to 0 if you don't want to allow quitting during the test

    <itemDimGUI>24</itemDimGUI> - item dimension - e.g. button size 

    <launchScript>0</launchScript> - this option calls an octave script and computes some scores

    <scriptDirectory>XML4MAT</scriptDirectory> - the directory in which the octave script resides

    <appToLaunchPath>/Applications/Octave.app/Contents/Resources/bin/octave -qf --quiet --eval "clear all; cd path; tapping2('xmlin','xmlout');exit;"</appToLaunchPath> - the path to octave, matlab or whatever script you want to call. you must preserve the xmlin and xmlout structure, xmlin being the file with the tapping and xmlout the results file

    <isClient>0</isClient> - this app is a server and listening to a port, taking care of user management, or is a client, just storing the taps for each user and not their data

    <tcpPort>9001</tcpPort> - the tcp port used for client-server communication 

    <ipServer>127.0.0.1</ipServer> - the ip of the server to connect to
</settings>

INSTRUCTIONS
- the app description from the first page can be changed from description.txt
- the instructions can be changed from instructions.txt
- the <> sequence is used for a new line
