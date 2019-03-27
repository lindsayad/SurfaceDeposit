//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef SURFACE_DEPOSITAPP_H
#define SURFACE_DEPOSITAPP_H

#include "MooseApp.h"

class SurfaceDepositApp;

template <>
InputParameters validParams<SurfaceDepositApp>();

class SurfaceDepositApp : public MooseApp
{
public:
  SurfaceDepositApp(InputParameters parameters);
  virtual ~SurfaceDepositApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* SURFACE_DEPOSITAPP_H */
