#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxTextSuite.h"
#include "ofxUI.h"
#include "ofxDirList.h"
#include "threadedObject.h"
#include "Usert.h"
#include <sstream>



class testApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
    
    
    //SETTINGS
    int midiPort;
    int midiChannel;
    int midiNote;
    int noPlays;
    bool tapWithSpace;
    int itemDimGUI;
    string instrGUI1, instrGUI2;
    ofxTextBlock instructions1,instructions2;    
    bool toggleInstructions1,toggleInstructions2,toggleInstructions3;
    stringstream text;   
    
    void loadXmlSettings(string fileName);
	
    
    //MIDI
	void newMidiMessage(ofxMidiMessage& eventArgs);		
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
    
    
    //SOUNDS
    ofxDirList   DIR;    
    ofSoundPlayer  beats;
    int numSounds;
    string* songNames;
    int played;
    
    
    //GUI    
    ofxUICanvas *gui1,*gui2,*gui3, *gui4;
    
    void guiEvent1(ofxUIEventArgs &e);
    void guiEvent2(ofxUIEventArgs &e);
    void guiEvent3(ofxUIEventArgs &e); 
    void guiEvent4(ofxUIEventArgs &e); 
    void loadTapping(int stage);
    
    
    //USER
    Usert usert; 
    int* uIDs;
    string* uNames;
    int* uNameID;
    int* tempIDs;
    string* tempNames;
    int* tempNameID;
    bool newUser;
    int nrUsers;
    int maxID;
    
    void saveXmlUser(string fileName);        
    void loadXmlUser(string fileName);
    void saveXmlTap(string fileName);        
    void loadXmlTap(string fileName);  
    
    int checkUser(string initials);
    int getUserID(string uName);
    void array_union(int* arr, string* sarr, int n);
    void randomOrder(int uid);  
    
    //MATLAB
    threadedObject	matlabScript;
      

};
