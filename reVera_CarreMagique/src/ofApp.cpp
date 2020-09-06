#include "ofApp.h"


// USER FUNCTIONS
//--------------------------------------------------------------
float ofApp::calcAngle(ofVec2f A, ofVec2f B, ofVec2f C){
    
    // Test angles
    ofVec2f first_line = A - B;
    ofVec2f second_line = C - B;
    float l1_angle = atan2(first_line.y, first_line.x);
    float l2_angle = atan2(second_line.y, second_line.x);
    
    // Convert angles to be positive only
    if (l1_angle < 0) {
        l1_angle_pos = PI + l1_angle;
    } else {
        l1_angle_pos = l1_angle;
    }
    
    if (l2_angle < 0) {
        l2_angle_pos = PI + l2_angle;
    } else {
        l2_angle_pos = l2_angle;
    }
    
    // Calculate the halfway angle
    float final_angle = ((l1_angle + l2_angle) / 2) + PI;
    
    return (final_angle);
}


// OF FUNCTIONS
//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    N = 18; // Number of vertices for the path
    width = 100;
    seed_val = 26;
    
    // Set up canvas
    fbo.allocate(700,700);
    
    // Initialize angles
    corner_angle_prev = 0;
    corner_angle_next = 0;

    
    // Test Angles
    ofVec2f first_line = ofVec2f(0,0) - ofVec2f(100,0);
    ofVec2f second_line = ofVec2f(200,100) - ofVec2f(100,0);
    
    float l1_angle = atan2(first_line.y, first_line.x);
    float l2_angle = atan2(second_line.y, second_line.x);
    
    // Convert angles to be positive only
    if (l1_angle < 0) {
        l1_angle_pos = PI + l1_angle;
    } else {
        l1_angle_pos = l1_angle;
    }
    
    if (l2_angle < 0) {
        l2_angle_pos = PI + l2_angle;
    } else {
        l2_angle_pos = l2_angle;
    }
    
    // Calculate the halfway angle
    float final_angle = ((l1_angle + l2_angle) / 2);
    cout << final_angle << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Clear vector each time
    centers.clear();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSeedRandom(seed_val);
    
    cam.begin();
    ofEnableDepthTest();
    
    ofFill();
    ofBackground(214,85,10);
    
    ofSetColor(0);
    
    // Create a vector of centers of N vertices using noise
    centers.push_back(ofVec3f(-400, 200, 0)); // Create the starting vertex
    
    for (float i = 0; i < N-2; i++) {
        centers.push_back(ofVec3f(ofRandom(-200 - (i*190), 200 + (i*190)), ofRandom(-200 - (i*190), 200 + (i*190)), -250*(i+1)));
    }
    centers.push_back(ofVec3f(15000, 200, -250*N));// Create the final exit point

    // For each pair of points (except final point) - draw a rectangle
    for (int i = 0; i < centers.size()-1; i++) {
        ofVec3f cur_point = centers[i];
        ofVec3f next_point = centers[i+1];
    
        
        // For simplicity just add on in the vertical direction
        float h_width = width/2;
        ofVec3f vertex_1 = cur_point + ofVec3f(-sin(corner_angle_prev)*h_width, -cos(corner_angle_prev)*h_width, 0);
        ofVec3f vertex_2 = next_point + ofVec3f(-sin(corner_angle_next)*h_width, -cos(corner_angle_next)*h_width, 0);
        ofVec3f vertex_3 = next_point + ofVec3f(sin(corner_angle_next)*h_width, cos(corner_angle_next)*h_width, 0);
        ofVec3f vertex_4 = cur_point + ofVec3f(sin(corner_angle_prev)*h_width, cos(corner_angle_prev)*h_width, 0);
        
        ofBeginShape();
        ofVertex(vertex_1);
        ofVertex(vertex_2);
        ofVertex(vertex_3);
        ofVertex(vertex_4);
        ofEndShape(true);
        
    }
    
    ofDisableDepthTest();
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + "screenshot.png");
    }
    
    if (key == 'r') {
        seed_val = ofRandom(0, 1000);
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

