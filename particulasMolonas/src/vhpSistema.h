#pragma once
#include "ofMain.h"
#include "vhpParticula.h"

class vhpSistema {

    public:
        //constructor
        vhpSistema();
    
		void setup(int _total);
		void update();
        void draw();
        void reset();
    
        vector<vhpParticula> pelotas;
        int total;
		
};
