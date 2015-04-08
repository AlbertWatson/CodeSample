//  Created by Albert Watson on 19/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.

//  Matches particles and cells.

#include <vector>
#include <math.h>

#include "match_cells_and_particles.h"
#include "constants.h"
#include "particle_structure.h"

using namespace std;

void match_cells_and_particles(vector< particle > &particles, vector< vector< vector<int> > > &cells)
{
    for (int i=0; i<dots*dots; i++)
    {
            //Gives particle i a cell.
        particles[i].cell[0] = floor((particles[i].position[0]-start_of_grid) / cell_size)+1;
        particles[i].cell[1] = floor((particles[i].position[1]-start_of_grid) / cell_size)+1;
        
            //Adds particle i to its cell.
        cells[particles[i].cell[0]][particles[i].cell[1]].push_back(i);
    }
}