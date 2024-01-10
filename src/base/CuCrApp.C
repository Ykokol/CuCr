#include "CuCrApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
CuCrApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

CuCrApp::CuCrApp(InputParameters parameters) : MooseApp(parameters)
{
  CuCrApp::registerAll(_factory, _action_factory, _syntax);
}

CuCrApp::~CuCrApp() {}

void 
CuCrApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<CuCrApp>(f, af, s);
  Registry::registerObjectsTo(f, {"CuCrApp"});
  Registry::registerActionsTo(af, {"CuCrApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
CuCrApp::registerApps()
{
  registerApp(CuCrApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
CuCrApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  CuCrApp::registerAll(f, af, s);
}
extern "C" void
CuCrApp__registerApps()
{
  CuCrApp::registerApps();
}
