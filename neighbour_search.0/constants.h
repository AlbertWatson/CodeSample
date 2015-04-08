//  Created by Albert Watson on 19/11/2014.
//  Copyright (c) 2014 Albert Watson. All rights reserved.

#ifndef exercise_Scanning_for_Dots6_0_constants_h
#define exercise_Scanning_for_Dots6_0_constants_h

#include <math.h>   //floor

const int dots = 1000;                                  //Number of particles in each dimention.
const double start_of_grid = 0.0;                       //(again in each dimention)
const double end_of_grid = 1.0;                         //(again in each dimention)
const double size = end_of_grid - start_of_grid;        //Make sure it is precise: 1.0 not 1.
const double r = /*0.002*1.000001; */1.5*size/(dots-1); //Neighbour radius.

const size_t number_of_cells = floor(size/r);           //(again in each dimention)
const double cell_size = size / number_of_cells;        //Space between particles.

#endif
