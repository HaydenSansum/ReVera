#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    ofSetFrameRate(10);
    ofSetBackgroundAuto(false);
    ofBackground(255);
    ofSeedRandom(13);
    
    fbo.begin();
    ofClear(255,255,255, 255);
    fbo.end();
    
    box_x_size = 70;
    box_y_size = 70;
    direction = -1;

    keep_run = true;
    run_counter = 0;
    
    
    int x_end = window_x - buffer_x + ((window_x-(2*buffer_x)) / num_x_boxes) - box_x_size;
    int y_end = window_y - buffer_y + ((window_y-(2*buffer_y)) / num_y_boxes) - box_y_size;

    int draw_idx = 0;
    
    for (int i = 0; i < num_x_boxes; i += 1) {
        for (int j = 0; j < num_y_boxes; j += 1) {

            // Get starting positions of each line
            int x_current = ofMap(i, 0, num_x_boxes, buffer_x, x_end);
            int y_current = ofMap(j, 0, num_y_boxes, buffer_y, y_end);

            x_locations[draw_idx] = x_current;
            y_locations[draw_idx] = y_current;
            
            draw_idx = draw_idx + 1;
        }
    }
    
    ofSleepMillis(3000);
}

//--------------------------------------------------------------
void ofApp::update(){
    direction = direction + 1;
    if (direction > 3) {
        direction = 0;
    }
    if (run_counter > 70) {
        keep_run = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (keep_run) {
        int draw_idx = 0;
        fbo.begin();
        for (int i = 0; i < num_x_boxes; i += 1) {
            for (int j = 0; j < num_y_boxes; j += 1) {
                
                // Set colour based on index
                if (i == 0) {
                    ofSetColor(227, 82, 30);
                } else if (i == 1) {
                    ofSetColor(226, 76, 31);
                } else if (i == 2) {
                    ofSetColor(225, 70, 33);
                } else if (i == 3) {
                    ofSetColor(224, 63, 34);
                } else if (i == 4) {
                    ofSetColor(222, 59, 36);
                } else if (i == 5) {
                    ofSetColor(221, 54, 37);
                } else if (i == 6) {
                    ofSetColor(219, 47, 39);
                } else if (i == 7) {
                    ofSetColor(219, 47, 39);
                } else {
                    ofSetColor(219, 47, 39);
                }
                
                // Add a bit of randomness each time a bit differently
                float rand_amount = ofRandom(2 + (i*0.7));
                int x_random = ofRandom(-rand_amount, rand_amount);
                int y_random = ofRandom(-rand_amount, rand_amount);

                // Draw right
                if (direction == 0) {
                    ofDrawLine(x_locations[draw_idx], y_locations[draw_idx], x_locations[draw_idx] + box_x_size + x_random, y_locations[draw_idx] + y_random);
                    x_locations[draw_idx] = x_locations[draw_idx] + box_x_size + x_random;
                    y_locations[draw_idx] = y_locations[draw_idx] + y_random;
                    
                } else if (direction == 1) {
                    ofDrawLine(x_locations[draw_idx], y_locations[draw_idx], x_locations[draw_idx] + x_random, y_locations[draw_idx] + box_y_size +  y_random);
                    x_locations[draw_idx] = x_locations[draw_idx] + x_random;
                    y_locations[draw_idx] = y_locations[draw_idx] + box_y_size + y_random;
                    
                } else if (direction == 2) {
                    ofDrawLine(x_locations[draw_idx], y_locations[draw_idx], x_locations[draw_idx] - box_x_size + x_random, y_locations[draw_idx] + y_random);
                    x_locations[draw_idx] = x_locations[draw_idx] - box_x_size + x_random;
                    y_locations[draw_idx] = y_locations[draw_idx] + y_random;
                    
                } else {
                    ofDrawLine(x_locations[draw_idx], y_locations[draw_idx], x_locations[draw_idx] + x_random, y_locations[draw_idx] - box_y_size +  y_random);
                    x_locations[draw_idx] = x_locations[draw_idx] + x_random;
                    y_locations[draw_idx] = y_locations[draw_idx] - box_y_size + y_random;
                }
                draw_idx = draw_idx + 1;
            }
        }
        run_counter = run_counter + 1;
        fbo.end();
    }
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
