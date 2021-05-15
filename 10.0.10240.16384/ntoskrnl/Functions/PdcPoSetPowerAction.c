// PdcPoSetPowerAction 
 
int __fastcall PdcPoSetPowerAction(_DWORD *a1, int a2, int *a3, int a4, int a5)
{
  PopAcquirePolicyLock();
  PopExecutePowerAction(a1, a2, a3, a4, a5);
  return PopReleasePolicyLock();
}
