// PdcPoVerifyPowerState 
 
int __fastcall PdcPoVerifyPowerState(int *a1, int a2)
{
  PopAcquirePolicyLock();
  PopVerifySystemPowerState(a1, a2);
  return PopReleasePolicyLock();
}
