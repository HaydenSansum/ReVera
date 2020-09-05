#include "ofApp.h"


// USER FUNCTIONS
//--------------------------------------------------------------
float ofApp::calcAngle(ofVec2f A, ofVec2f B, ofVec2f C){
    
    // Test angles
    ofVec2f first_line = B - A;
    ofVec2f second_line = C - B;
    float l1_angle = atan2(first_line.x, first_line.y) - (PI/2);
    float l2_angle = atan2(second_line.x, second_line.y)-(PI/2);
    
    // Calculate the halfway angle
    float final_angle = ((l1_angle + l2_angle) / 2) + PI;
    
    return (final_angle);
}


// OF FUNCTIONS
//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    N = 18; // Number of vertices for the path
    width = 40;
    
    // Set up canvas
    fbo.allocate(700,700);
    
    // Initialize angles
    corner_angle_prev = PI/2;
    corner_angle_next = PI/2;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Clear vector each time
    centers.clear();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSeedRandom(mouseX * 1000);
    
    // Begin drawing canvas (fbo)
    fbo.begin();
    
    ofFill();
    ofBackground(214,85,10);
    
    ofSetColor(0);
    
    // Create a vector of centers of N vertices using noise
    centers.push_back(ofVec2f(0, 120)); // Create the starting vertex
    
    for (int i = 0; i < N-2; i++) {
        centers.push_back(ofVec2f(ofRandom(60, 640), ofRandom(60, 640)));
    }
    centers.push_back(ofVec2f(700, 200));// Create the final exit point

    // For each pair of points (except final point) - draw a rectangle
    for (int i = 0; i < centers.size()-2; i++) {
        ofVec2f cur_point = centers[i];
        ofVec2f next_point = centers[i+1];
        ofVec2f future_point = centers[i+2];
        
        corner_angle_next = calcAngle(cur_point, next_point, future_point);
        
        // For simplicity just add on in the vertical direction
        float h_width = width/2;
        ofVec2f vertex_1 = cur_point + ofVec2f(-cos(corner_angle_prev)*h_width, -sin(corner_angle_prev)*h_width);
        ofVec2f vertex_2 = next_point + ofVec2f(-cos(corner_angle_next)*h_width, -sin(corner_angle_next)*h_width);
        ofVec2f vertex_3 = next_point + ofVec2f(cos(corner_angle_prev)*h_width, sin(corner_angle_prev)*h_width);
        ofVec2f vertex_4 = cur_point + ofVec2f(cos(corner_angle_next)*h_width, sin(corner_angle_next)*h_width);
        
        ofBeginShape();
        ofVertex(vertex_1);
        ofVertex(vertex_2);
        ofVertex(vertex_3);
        ofVertex(vertex_4);
        ofEndShape(true);
        
        corner_angle_prev = corner_angle_next;
    }
    
    fbo.end();
    
    fbo.draw(20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + "screenshot.png");
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

