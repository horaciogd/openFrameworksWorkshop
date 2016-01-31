#include "vhpParticula.h"

//----------------------------------------------------------------
vhpParticula::vhpParticula() {

}

//--------------------------------------------------------------
void vhpParticula::setup(float _x, float _y, float _z, float _radio){
    posicion.set(_x, _y, _z);
    radio = _radio;
    aceleracion.set(0, 0, 0);
    gravedade.set(0, 2.5, 0);
    absorcion = 0.99;
}

//--------------------------------------------------------------
void vhpParticula::setVelocidade(float _v_x, float _v_y, float _v_z) {
    velocidade.set(_v_x, _v_y, _v_z);
}

//--------------------------------------------------------------
void vhpParticula::update(){
    aceleracion = aceleracion + gravedade;
    velocidade = velocidade + aceleracion;
    aceleracion = 0 * aceleracion;
    posicion = posicion + velocidade;
    detectaChoque();
}

//--------------------------------------------------------------
void vhpParticula::detectaChoque(){
    if (posicion.x <= radio) {
        velocidade.x = (-1) * velocidade.x;
        velocidade = absorcion * velocidade;
        posicion.x = radio;
    } else if (posicion.x >= ofGetWindowWidth()-radio) {
        velocidade.x = (-1) * velocidade.x;
        velocidade = absorcion * velocidade;
        posicion.x = ofGetWindowWidth()-radio;
    }
    if (posicion.y <= radio) {
        velocidade.y = (-1) * velocidade.y;
        velocidade = absorcion * velocidade;
        posicion.y = radio;
    } else if (posicion.y >= ofGetWindowHeight()-radio) {
        velocidade.y = (-1) * velocidade.y;
        velocidade = absorcion * velocidade;
        posicion.y = ofGetWindowHeight()-radio;
    }
}

//--------------------------------------------------------------
void vhpParticula::draw(){
    ofPushStyle();
    ofSetColor(255,130,0,100);
    ofFill();
    ofCircle(posicion.x, posicion.y,radio);
    ofPopStyle();
}