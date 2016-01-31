#include "vhpSistema.h"

//--------------------------------------------------------------
vhpSistema::vhpSistema(){
    
}

//--------------------------------------------------------------
void vhpSistema::setup(int _total){
    total = _total;
    pelotas.assign(total, vhpParticula());
    for (int i = 0; i<total; i++) {
        pelotas[i].setup(ofRandom(0,ofGetWindowWidth()), ofRandom(0,ofGetWindowHeight()), 0, ofRandom(5, 50));
        pelotas[i].setVelocidade(ofRandom(-10, 10), ofRandom(-10,10), 0);
    }
}

//--------------------------------------------------------------
void vhpSistema::update(){
    for (int i = 0; i<total; i++) {
        pelotas[i].update();
    }
}

//--------------------------------------------------------------
void vhpSistema::draw(){
    for (int i = 0; i<total; i++) {
        pelotas[i].draw();
    }
}