#pragma once
#include "ofMain.h"

class vhpParticula {

	public:
    
        //constructor
        vhpParticula();
    
		void setup(float _x, float _y, float _z, float _radio);
        void setVelocidade(float _v_x, float _v_y, float _v_z);
		void update();
        void detectaChoque();
		void draw();
    
        ofVec3f posicion;
        ofVec3f velocidade;
        ofVec3f aceleracion;
        ofVec3f gravedade;
    
        float absorcion;
        float radio;
		
};
