#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    vector<ofxJSONElement> drawDataJson;
    int vertexNum;
    int objNum;
    int strokeNum;
};
