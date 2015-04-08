//  Created by Albert Watson on 19/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.
//  _________________________________________________________________
//
//  Codeplay, documentation is intended to give a rough idea of what
//  is going on, for more info please don't hesitate to contact me.
//  _________________________________________________________________
//
//  Purpose of code:
//  -For an 'area' of 'particles', code must find 'neighbour list' of
//   each 'particle'; this is any particles within a given radius r
//   of the particle in question.
//  -Key is speed since code is to be used repetitively by bigger
//   program.
//  _________________________________________________________________
//
//  Method:
//  Makes use of 'cell search' method:
//  -The area is divide into cells of dimensions r.
//  -Each particle is assigned to a cell.
//  -For each particle, code only needs to search particles in the 9
//   cells surrounding its own.

#include <iostream>
#include <vector>
//#include <chrono>

#include "constants.h"
#include "define_particles.h"
#include "match_cells_and_particles.h"
#include "search.h"
#include "particle_structure.h"

using namespace std;


int main(int argc, const char * argv[])
{
        //Declaring main variables.
    vector< particle > particles (dots*dots);
    vector< vector< vector<int> > > cells ((number_of_cells+3), vector< vector<int> > (number_of_cells+3));
    
    
        //Initialising particle positions.
    define_particles(particles);
    
    
        //Assigning each particle to a cell then particles to each cell.
    match_cells_and_particles(particles, cells);
    
    
        //Finding 'neighbours' of each particle.
    search(particles, cells);
    
    
    return 0;
}