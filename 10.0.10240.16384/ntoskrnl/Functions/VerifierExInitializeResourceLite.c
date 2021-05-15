// VerifierExInitializeResourceLite 
 
int __fastcall VerifierExInitializeResourceLite(unsigned int a1)
{
  int v2; // r4
  int v3; // r3
  unsigned int v4; // r2
  int v5; // r3
  _DWORD *v6; // r8
  unsigned int v7; // r2
  _DWORD *v8; // r7
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r1
  int v12; // r0
  BOOL v13; // r1
  char v15[32]; // [sp+8h] [bp-20h] BYREF

  VfUtilSynchronizationObjectSanityChecks(a1, 56);
  v2 = pXdvExInitializeResourceLite(a1);
  if ( v2 >= 0 )
  {
    if ( (MmVerifierData & 0x800) != 0 )
    {
      v5 = ViResourceInitialized;
      __dmb(0xBu);
      if ( !v5 )
        return v2;
      v6 = VfAvlReserveNode(ViResourceAvl, a1, 0);
      if ( !v6 )
      {
        __dmb(0xBu);
        do
          v7 = __ldrex((unsigned int *)&ViResourceNotTracked);
        while ( __strex(1u, (unsigned int *)&ViResourceNotTracked) );
        goto LABEL_6;
      }
      v8 = 0;
      VfAvlInitializeLockContext((int)v15, 0);
      if ( VfAvlLookupTreeNode(ViResourceAvl, (int)v15, a1, 0) )
      {
        v10 = ViResourcesAlreadyLoadedDrivers;
        __dmb(0xBu);
        if ( !v10 )
          VerifierBugCheckIfAppropriate(196, 208, a1, 0, 0);
        __dmb(0xBu);
        do
          v11 = __ldrex(&ViResourceStaleNodes);
        while ( __strex(v11 + 1, &ViResourceStaleNodes) );
        __dmb(0xBu);
        v8 = (_DWORD *)VfAvlDeleteTreeNode(ViResourceAvl, (int)v15, a1, 0);
      }
      VfAvlInsertReservedTreeNode((int)ViResourceAvl, (int)v15, v6, v9);
      v12 = VfAvlCleanupLockContext((int)v15);
      if ( v8 )
      {
        if ( dword_9085C0 == 1 )
        {
          ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v8);
        }
        else
        {
          v13 = KeGetCurrentIrql(v12) != 2;
          VfPoolDelayFreeIfPossible((int)v8, v13);
        }
      }
    }
    else
    {
      v3 = ViResourceNotTracked;
      __dmb(0xBu);
      if ( !v3 )
      {
        __dmb(0xBu);
        do
          v4 = __ldrex((unsigned int *)&ViResourceNotTracked);
        while ( __strex(1u, (unsigned int *)&ViResourceNotTracked) );
LABEL_6:
        __dmb(0xBu);
        return v2;
      }
    }
  }
  return v2;
}
