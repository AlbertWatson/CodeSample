//  Created by Albert Watson on 19/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.

//  Gives particles their positions.

#include <vector>

#include "define_particles.h"
#include "constants.h"
#include "particle_structure.h"

using namespace std;

void define_particles(vector< particle >& particles)
{
    for (int y=0; y<dots; y++)
    {
        for (int x=0; x<dots; x++)
        {
            particles[(dots*y)+x].position[0] = ((size/dots)*(x+1))+start_of_grid;
            particles[(dots*y)+x].position[1] = ((size/dots)*(y+1))+start_of_grid;
            //consider puting (dots*y) and (size/(dots-1)) outside loop so that they are only computed once.
        }
    }
}