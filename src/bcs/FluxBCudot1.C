// operate on C_O, coupled C_R

#include "FluxBCudot1.h"

registerMooseObject("SurfaceDepositApp", FluxBCudot1);

template <>
InputParameters
validParams<FluxBCudot1>()
{
  InputParameters params = validParams<IntegratedBC>();

  params.addCoupledVar("coupled_var", "	Choose the variable you want to couple");

  return params;
}

FluxBCudot1::FluxBCudot1(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _couple_var(coupledValue("coupled_var")),
    _couple_var_offjac(coupled("coupled_var")),
    _u_dot(dot()),
    _du_dot_du(dotDu())
{
}

Real
FluxBCudot1::computeQpResidual()
{
    return  _test[_i][_qp] * - (_u_dot[_qp]-(_couple_var[_qp]-_u[_qp]));
}

Real
FluxBCudot1::computeQpJacobian()
{
  return _test[_i][_qp] * - (_du_dot_du[_qp] + 1) * _phi[_j][_qp];
}

Real
FluxBCudot1::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _couple_var_offjac)
    return _test[_i][_qp] * _phi[_j][_qp];
  else
    return 0;
}
