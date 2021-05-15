// IopWarmEjectDevice 
 
int __fastcall IopWarmEjectDevice(int a1, int a2)
{
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int v7; // r4

  KeWaitForSingleObject((unsigned int)&IopWarmEjectLock, 0, 0, 0, 0);
  PpDevNodeLockTree(1, v4);
  IopWarmEjectPdo = a1;
  PpDevNodeUnlockTree(1);
  v7 = NtInitiatePowerAction(7, a2, 3, 0);
  if ( v7 == -1073741727 )
    PnpSetPowerVetoEvent(7, v5, v6, a1, 12, 0);
  PpDevNodeLockTree(1, v5);
  if ( IopWarmEjectPdo )
  {
    if ( v7 >= 0 )
      v7 = -1073741823;
    IopWarmEjectPdo = 0;
  }
  PpDevNodeUnlockTree(1);
  KeSetEvent((int)&IopWarmEjectLock, 0, 0);
  return v7;
}
