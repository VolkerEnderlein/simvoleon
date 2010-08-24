#ifndef CVR_RAYCASTCUBE_H
#define CVR_RAYCASTCUBE_H

/**************************************************************************\
 *
 *  This file is part of the SIM Voleon visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using SIM Voleon with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits
 *  of our support services, please contact Kongsberg Oil & Gas
 *  Technologies about acquiring a SIM Voleon Professional Edition
 *  License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#ifndef SIMVOLEON_INTERNAL
#error this is a private header file
#endif // !SIMVOLEON_INTERNAL

#include <Inventor/SbVec3s.h>
#include <Inventor/SbVec3ui32.h>
#include <Inventor/SbVec3f.h>

class SoGLRenderAction;
class SoState;

class CvrRaycastCube {
public:
  CvrRaycastCube(const SoGLRenderAction * action);
  ~CvrRaycastCube();

  void render(const SoGLRenderAction * action);

private:
  SbVec3s dimensions;
  SbVec3s subcubesize;
  SbVec3f origo;
  SbVec3ui32 nrsubcubes; // Number of subcubes in x-y-z direction
  class SubCube ** subcubes;
  
  class SubCube * getSubCube(SoState * state, 
                             unsigned int row, 
                             unsigned int col, 
                             unsigned int depth);
  class SubCube * buildSubCube(const SoGLRenderAction * action,
                               const SbVec3f & origo,
                               unsigned int row,
                               unsigned int col,
                               unsigned int depth);   
  unsigned int getSubCubeIdx(unsigned int row, unsigned int col, unsigned int depth) const;
  void releaseSubCube(unsigned int row, unsigned int col, unsigned int depth);
  void releaseAllSubCubes();
};

#endif // !CVR_RAYCASTCUBE_H
