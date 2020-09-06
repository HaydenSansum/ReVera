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
    
    ofFbo fbo;
    
    int window_x = 1000;
    int window_y = 670;

    int num_x_boxes = 9;
    int num_y_boxes = 6;
    int x_locations [9*6];
    int y_locations [9*6];

    int buffer_x = 200;
    int buffer_y = 134;

    float box_x_size;
    float box_y_size;

    int direction;
    
    bool keep_run;
    int run_counter;
    
    ofImage img;
};
