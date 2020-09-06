#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        float calcAngle(ofVec2f A, ofVec2f B, ofVec2f C);
    
    int N;
    int width;
    float corner_angle_next;
    float corner_angle_prev;
    float l1_angle_pos;
    float l2_angle_pos;
    int seed_val;
    
    ofFbo fbo;
    ofImage img;
    ofEasyCam cam;
    
    vector <ofVec3f> centers;
		
};
