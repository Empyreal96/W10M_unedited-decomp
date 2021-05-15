// PopRegisterEnergyEstimation 
 
int (__fastcall *__fastcall PopRegisterEnergyEstimation(int (__fastcall *result)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD), int (__fastcall *a2)(_DWORD, _DWORD, _DWORD)))(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)
{
  PopComputeEnergy = result;
  PopSnapEnergyCounters = a2;
  return result;
}
