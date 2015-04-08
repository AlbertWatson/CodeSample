//  Created by Albert Watson on 22/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.

#ifndef exercise_Scanning_for_Dots6_0_particle_structure_h
#define exercise_Scanning_for_Dots6_0_particle_structure_h

using namespace std;

struct particle
{
    double position[2] = {0,0};
    
    int cell[2] = {0,0};
    
    vector< int > neighbours;
};

#endif
