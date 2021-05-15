// VfCheckForLookaside 
 
int __fastcall VfCheckForLookaside(int a1, int a2)
{
  _DWORD *v5; // r1
  unsigned int v6; // r0
  int v7; // r2
  int *v8; // r0
  char v9[24]; // [sp+8h] [bp-18h] BYREF

  if ( !ViLookasideInitialized )
    return 0;
  v5 = &VfPoolDelayFreeData;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = 0;
  while ( v6 != v5[6] )
  {
    ++v7;
    v5 += 12;
    if ( v7 >= 2 )
    {
      VfAvlInitializeLockContext((int)v9, 1);
      v8 = (int *)VfAvlLookupTreeNode(ViLookasideAvl, (int)v9, a1, a2);
      if ( v8 )
        VerifierBugCheckIfAppropriate(196, 204, *v8, a1, a2);
      VfAvlCleanupLockContext((int)v9);
      return 1;
    }
  }
  return 1;
}
