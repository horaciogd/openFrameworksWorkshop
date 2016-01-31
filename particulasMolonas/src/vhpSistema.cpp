#include "vhpSistema.h"

//--------------------------------------------------------------
vhpSistema::vhpSistema(){
    
}

//--------------------------------------------------------------
void vhpSistema::setup(int _total){
    total = _total;
    pelotas.assign(total, vhpParticula());
    for (int i = 0; i<total; i++) {
        pelotas[i].setup(ofRandom(-20,20), ofRandom(-20,20), ofRandom(0,80), ofRandom(1, 5));
        pelotas[i].setVelocidade(ofRandom(-1, 1), ofRandom(-1,1), ofRandom(-1,1));
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

//--------------------------------------------------------------
void vhpSistema::reset(){
    for (int i = 0; i<total; i++) {
        pelotas[i].setup(ofRandom(-20,20), ofRandom(-20,20), ofRandom(0,80), ofRandom(0.2, 5));
        pelotas[i].setVelocidade(ofRandom(-1, 1), ofRandom(-1,1), ofRandom(-1,1));
    }
}