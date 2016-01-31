#include "vhpParticula.h"

//----------------------------------------------------------------
vhpParticula::vhpParticula() {

}

//--------------------------------------------------------------
void vhpParticula::setup(float _x, float _y, float _z, float _radio){
    posicion.set(_x, _y, _z);
    radio = _radio;
    aceleracion.set(0, 0, 0);
    gravedade.set(0, 0, -0.5);
    absorcion = 1;
    color.set(ofRandom(255), ofRandom(255), ofRandom(255), 150);
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
    if (posicion.z <= radio) {
        velocidade.z = (-1) * velocidade.z;
        velocidade = absorcion * velocidade;
        posicion.z = radio;
    } else if (posicion.z >= 100) {
        velocidade.z = (-1) * velocidade.z;
        velocidade = absorcion * velocidade;
        posicion.z = 100;
    }
    if (posicion.x <= -25 + radio) {
        velocidade.x = (-1) * velocidade.x;
        velocidade = absorcion * velocidade;
        posicion.x = -25 + radio;
    } else if (posicion.x >= 25-radio) {
        velocidade.x = (-1) * velocidade.x;
        velocidade = absorcion * velocidade;
        posicion.x = 25-radio;
    }
    if (posicion.y <= -25 + radio) {
        velocidade.y = (-1) * velocidade.y;
        velocidade = absorcion * velocidade;
        posicion.y = -25 + radio;
    } else if (posicion.y >= 25-radio) {
        velocidade.y = (-1) * velocidade.y;
        velocidade = absorcion * velocidade;
        posicion.y = 25-radio;
    }
}

//--------------------------------------------------------------
void vhpParticula::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    ofPushMatrix();
    ofTranslate(0, 0, posicion.z);
    ofDrawSphere(posicion.x, posicion.y,radio);
    //ofCircle(posicion.x, posicion.y,radio);
    ofPopMatrix();
    ofPopStyle();
}