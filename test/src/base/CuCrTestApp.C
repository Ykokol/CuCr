//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "CuCrTestApp.h"
#include "CuCrApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
CuCrTestApp::validParams()
{
  InputParameters params = CuCrApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

CuCrTestApp::CuCrTestApp(InputParameters parameters) : MooseApp(parameters)
{
  CuCrTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

CuCrTestApp::~CuCrTestApp() {}

void
CuCrTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  CuCrApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"CuCrTestApp"});
    Registry::registerActionsTo(af, {"CuCrTestApp"});
  }
}

void
CuCrTestApp::registerApps()
{
  registerApp(CuCrApp);
  registerApp(CuCrTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
CuCrTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  CuCrTestApp::registerAll(f, af, s);
}
extern "C" void
CuCrTestApp__registerApps()
{
  CuCrTestApp::registerApps();
}
