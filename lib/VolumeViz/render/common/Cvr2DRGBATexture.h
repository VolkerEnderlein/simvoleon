#ifndef COIN_CVR2DRGBATEXTURE_H
#define COIN_CVR2DRGBATEXTURE_H

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
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include <Inventor/SbVec2s.h>
#include <VolumeViz/render/common/CvrRGBATexture.h>


class Cvr2DRGBATexture : public CvrRGBATexture {
public:
  static void initClass(void);

  Cvr2DRGBATexture(const SbVec2s & size);
  virtual ~Cvr2DRGBATexture();

  virtual SoType getTypeId(void) const;
  static SoType getClassTypeId(void);

  SbVec2s dimensions;

  virtual uint32_t * getRGBABuffer(void) const;
  void blankUnused(const SbVec2s & texsize) const;

private:
  static SoType classTypeId;

};

#endif // !COIN_CVR2DRGBATEXTURE_H
