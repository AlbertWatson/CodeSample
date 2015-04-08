//  Created by Albert Watson on 19/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.

//  Searches for neighbours of each particle.

#include <vector>
#include <iostream>

#include "search.h"
#include "constants.h"
#include "particle_structure.h"

using namespace std;

void search(vector< particle > &particles, vector< vector< vector<int> > > cells)
{
        //Temporary variables.
    double rTemp = 0.0;
    double referance[2] = {0.5, 0.5};
    
    for (int j=0; j<(dots*dots); j++)
    {
        referance[0] = particles[j].position[0];
        referance[1] = particles[j].position[1];
        
            //The following two loops run through the cells surrounding particle j,
            //and the third one runs through the particles stored in each cell.
        for (int x=0; x<3; x++)
        {
            int cell_x = particles[j].cell[0]+x-1;
            
            for (int y=0; y<3; y++)
            {
                int cell_y = particles[j].cell[1]+y-1;
                
                size_t counter_length = (cells[cell_x][cell_y].size());
                for (size_t z=0; z<counter_length; z++)
                {
                    int i = cells[cell_x][cell_y][z];
                    
                        //Finds distance between particle j and i.  (faster not to use pow())
                    rTemp = ((referance[0]-particles[i].position[0])*(referance[0]-particles[i].position[0]))+((referance[1]-particles[i].position[1])*(referance[1]-particles[i].position[1]));
                    
                        //Adds particle i to list if within r.
                    if (rTemp <= (r*r))
                    {
                        particles[j].neighbours.push_back(i);
                    }
                }
            }
        }
            //Reorders 'nieghbours' of point j.
        sort(particles[j].neighbours.begin(), particles[j].neighbours.end());
    }
    
    
        //Used to check accuracy of results.
    /*for (int j=0; j<(dots*dots); j++)
    {
        cout << "Particle " << j << ", " << particles[j].neighbours.size() << " = ";
        for (size_t i=0; i<particles[j].neighbours.size(); i++)
        {
            cout << particles[j].neighbours[i] << ", ";
        }
        cout << endl;
    }*/
}