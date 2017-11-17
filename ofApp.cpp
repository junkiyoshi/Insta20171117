#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofSetDepthTest(true);

	this->lenna.loadImage("Lenna.png");
}

//--------------------------------------------------------------
void ofApp::update(){ }

//--------------------------------------------------------------
void ofApp::draw() {
	
	this->cam.begin();
	ofRotateZ(180);

	ofPixels pixels = this->lenna.getPixelsRef();
	ofColor pixel_color;
	float noise_value;
	float height;
	int size = 3;

	for (int x = 0; x < pixels.getWidth(); x += size) {
		for (int y = 0; y < pixels.getHeight(); y += size) {
			pixel_color = pixels.getColor(x, y);
			ofSetColor(pixel_color);

			noise_value = ofNoise(pixel_color.r * 0.005, pixel_color.g * 0.005, pixel_color.b * 0.005, ofGetFrameNum() * 0.05);
			height = 300 * noise_value;

			ofDrawBox(ofVec3f(x - ofGetWidth() / 2, y - ofGetHeight() / 2, height / 2), size, size, height);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(512, 512, OF_WINDOW);
	ofRunApp(new ofApp());
}