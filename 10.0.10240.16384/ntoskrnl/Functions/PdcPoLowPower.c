// PdcPoLowPower 
 
int __fastcall PdcPoLowPower(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v6[2]; // [sp+0h] [bp-8h] BYREF

  v6[1] = a4;
  v6[0] = a1;
  PopAcquirePolicyLock(a1, a2);
  v4 = PopSetPowerSettingValueAcDc(&GUID_LOW_POWER_EPOCH, 4, v6);
  PopReleasePolicyLock(v4);
  return 0;
}
