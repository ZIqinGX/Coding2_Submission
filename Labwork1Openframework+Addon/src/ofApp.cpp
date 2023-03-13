#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
       
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth(); ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    // Maximilian audio stuff
    int sampleRate = 44100; /* Sampling Rate */
    int bufferSize= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    // Setup ofSound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /////////////// waveform
    ofTranslate(ofGetWidth()/3-160, ofGetHeight() / 10);
    ofColor colorOne(177, 252, 3);
    ofColor colorTwo(252, 223, 3);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    //ofSetColor(10, 25, 0);
    //ofFill();
    //ofDrawLine(0, 0, 1, waveform[1] * ofGetHeight()/2.); //first line
    //for(int i = 1; i < (ofGetWidth() - 1); ++i) {
        //ofDrawLine(i, waveform[i] * ofGetHeight()/2., i + 1, waveform[i+1] * ofGetHeight()/2.);
    //ofSetHexColor(0xCC0000);
    

    // we specify control points that shape each part of the shape
    output.setColor(3,177,252);
    output.beginShape();

    int numSteps = ((float)mouseX / ofGetWidth()) * 10.0;

    //set number of sides based on mouse position
    numSteps = ((float)mouseX / ofGetWidth()) * 10.0;

    //make sure we don't go bellow 3 sides
    numSteps = MAX(3, numSteps);

    float step = TWO_PI / (numSteps);
    float angle = 0.0;
    float cenX = 900;
    float cenY = 700.0;
    float radius = 200.0;
    float scale = 2.0 + 0.2 * sin(ofGetElapsedTimef());

    for (int i = 0; i < numSteps; i++) {
        float rx = cenX+ cos(angle) * radius;
        float ry = cenY+ sin(angle) * radius;

        if (i == 0) {
            output.polyVertex(rx, ry);
        }

        float rx2 = cenX + cos(angle + step) * radius*0.4;
        float ry2 = cenY + sin(angle + step) * radius*0.4;

        //lets make our control points in between each side and out a little way
        //float cx = waveform[1] + cos(angle + step * 0.5) * radius * scale;
        //float cy = waveform[1] + sin(angle + step * 0.5) * radius * scale;

        float cx = waveform[1] + cos(angle + step * 0.5) * radius * scale;
        float cy = waveform[1] + sin(angle + step * 0.5) * radius * scale;
        output.bezierVertex(cx, cy, cx, cy, rx2, ry2);

        angle += step;
    }

    output.endShape(true);
    }




//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t nChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
        // handle input here
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){
        // return[osc1.saw(200 + 6 * osc2.saw(45)), osc3.saw(300 + osc4.saw(90))]
        output[i * outChannels] = osc1.saw(1000 + 6 * osc2.saw(45))*0.4, osc3.saw(300 + osc4.saw(900))*0.6;
        //output[i * outChannels] = (osc1.sinewave(100 * osc2.coswave(130.0))*0.3 + (osc3.saw(1000) * 2.0)*0.7);
        
        // scale down the sound or 2.clamp the value to make does not more than 1; or less than -1;cliping sound;ofclamp
        //1.multipal less than one to make sure it doen't more than 1

       output[i * outChannels + 1] = osc1.saw(mouseX/20), osc2.saw(mouseY/20);

        
        //Hold the values so the draw method can draw them
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
