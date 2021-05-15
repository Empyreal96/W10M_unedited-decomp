// CmpBecomeActiveFlusherAndReconciler 
 
void __fastcall CmpBecomeActiveFlusherAndReconciler(int *a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r0

  CmpLockRegistryFreezeAware(0);
  v4 = ExAcquireResourceExclusiveLite(a1[468], 1, v2, v3);
  v5 = a1[828];
  if ( (v5 & 2) != 0 )
  {
    sub_80B304(v4);
  }
  else
  {
    if ( (v5 & 1) != 0 )
      JUMPOUT(0x80B30A);
    a1[828] = v5 | 3;
    a1[822] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = __mrc(15, 0, 13, 0, 3);
    v7 = a1[468];
    a1[825] = v6 & 0xFFFFFFC0;
    ExReleaseResourceLite(v7);
    CmpUnlockRegistry();
  }
}
