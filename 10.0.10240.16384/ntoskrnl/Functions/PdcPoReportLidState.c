// PdcPoReportLidState 
 
int __fastcall PdcPoReportLidState(int a1)
{
  int v3; // [sp+0h] [bp-8h] BYREF

  PopAcquirePolicyLock();
  v3 = a1 != 0;
  ExNotifyCallback(ExCbPowerState, 4, v3);
  PopSetPowerSettingValueAcDc((int *)&GUID_LIDSWITCH_STATE_CHANGE, 4u, (int)&v3);
  return PopReleasePolicyLock();
}
