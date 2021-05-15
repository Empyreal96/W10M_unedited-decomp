// IoSetDependency 
 
int __fastcall IoSetDependency(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  _DWORD v9[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v10[4]; // [sp+8h] [bp-10h] BYREF

  if ( !a1 || !a2 || (a3 & 3) == 0 || (a3 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  if ( a1 == a2 )
    return -1073741823;
  v9[0] = 0;
  v9[1] = a1;
  v10[0] = 0;
  v10[1] = a2;
  v10[2] = a3;
  PnpAcquireDependencyRelationsLock(1, a2);
  v3 = PipSetDependency((int)v9, (int)v10);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  if ( v3 >= 0 )
  {
    v4 = PpDevNodeUnlockTree(0);
    PipProcessRebuildPowerRelationsQueue(v4, v5, v6, v7);
  }
  else
  {
    PpDevNodeUnlockTree(0);
  }
  return v3;
}
