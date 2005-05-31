#ifndef SIMVOLEON_CVR3DPALETTEGRADIENTTEXTURE_H
#define SIMVOLEON_CVR3DPALETTEGRADIENTTEXTURE_H

/**************************************************************************\
 *
 *  This file is part of the SIM Voleon visualization library.
 *  Copyright (C) 2003-2004 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using SIM Voleon with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits
 *  of our support services, please contact Systems in Motion about
 *  acquiring a SIM Voleon Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include <Inventor/SbVec3s.h>
#include <VolumeViz/render/common/Cvr3DPaletteTexture.h>

class CvrCLUT;


class Cvr3DPaletteGradientTexture : public Cvr3DPaletteTexture {
  typedef Cvr3DPaletteTexture inherited;

public:
  static void initClass(void);

  virtual SoType getTypeId(void) const;
  static SoType getClassTypeId(void);

  virtual uint8_t * getIndex8Buffer(void) const;
  virtual void blankUnused(const SbVec3s & texsize) const;

protected:
  Cvr3DPaletteGradientTexture(void);
  virtual ~Cvr3DPaletteGradientTexture();

private:
  static SoType classTypeId;
  static void * createInstance(void);
};

#endif // !SIMVOLEON_CVR3DPALETTEGRADIENTTEXTURE_H