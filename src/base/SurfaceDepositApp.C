#include "SurfaceDepositApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<SurfaceDepositApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

SurfaceDepositApp::SurfaceDepositApp(InputParameters parameters) : MooseApp(parameters)
{
  SurfaceDepositApp::registerAll(_factory, _action_factory, _syntax);
}

SurfaceDepositApp::~SurfaceDepositApp() {}

void
SurfaceDepositApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"SurfaceDepositApp"});
  Registry::registerActionsTo(af, {"SurfaceDepositApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SurfaceDepositApp::registerApps()
{
  registerApp(SurfaceDepositApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SurfaceDepositApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SurfaceDepositApp::registerAll(f, af, s);
}
extern "C" void
SurfaceDepositApp__registerApps()
{
  SurfaceDepositApp::registerApps();
}
