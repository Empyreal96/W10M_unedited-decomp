// IoReserveDependency 
 
int __fastcall IoReserveDependency(int a1, _WORD *a2, int a3)
{
  int v3; // r4
  _DWORD v5[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v6[4]; // [sp+8h] [bp-10h] BYREF

  if ( !a1 || !a2 || !*a2 || (a3 & 3) == 0 || (a3 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  v5[0] = 0;
  v5[1] = a1;
  v6[0] = 1;
  v6[1] = a2;
  v6[2] = a3;
  PnpAcquireDependencyRelationsLock(1, (int)a2);
  v3 = PipSetDependency(v5, v6);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  return v3;
}
