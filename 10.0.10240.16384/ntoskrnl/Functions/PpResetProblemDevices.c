// PpResetProblemDevices 
 
int __fastcall PpResetProblemDevices(int a1, int a2)
{
  int v3; // r3
  int v5[6]; // [sp+0h] [bp-18h] BYREF

  v5[0] = 49;
  v5[1] = 0;
  v5[2] = 0;
  PpDevNodeLockTree(1, a2);
  PipForDeviceNodeSubtree(a1, (int)PiResetProblemDevicesWorker, (int)v5, v3);
  return PpDevNodeUnlockTree(1);
}
