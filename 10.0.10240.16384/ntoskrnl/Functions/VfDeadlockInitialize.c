// VfDeadlockInitialize 
 
_BYTE *__fastcall VfDeadlockInitialize(int a1, int a2)
{
  _BYTE *result; // r0
  int v5; // r0
  unsigned int v6; // r3
  int v7; // r0
  unsigned int v8; // r2
  _DWORD *v9; // r1
  _DWORD *v10; // r3
  _DWORD *v11; // r3
  int v12; // r2
  int (*v13)(); // r1
  int v14; // r2
  int (*v15)(); // r1
  int v16; // r3
  int (*v17)(); // r1
  int v18; // r0
  int v19; // r3
  unsigned int v20; // r0
  unsigned int v21; // r0

  result = (_BYTE *)ExAllocatePoolWithTag(512, 16624, 1801677892);
  ViDeadlockGlobals = (int)result;
  if ( result )
  {
    memset(result, 0, 16624);
    v5 = ExAllocatePoolWithTag(512, 8184, 1801677892);
    v6 = ViDeadlockGlobals;
    *(_DWORD *)(ViDeadlockGlobals + 16) = v5;
    if ( v5
      && (v7 = ExAllocatePoolWithTag(512, 8184, 1801677892),
          v6 = ViDeadlockGlobals,
          (*(_DWORD *)(ViDeadlockGlobals + 8208) = v7) != 0) )
    {
      __dmb(0xBu);
      v8 = 0;
      ViDeadlockDatabaseLock = 0;
      v9 = (_DWORD *)ViDeadlockGlobals;
      do
      {
        v10 = (_DWORD *)(v9[4] + v8);
        *v10 = v10;
        v10[1] = v10;
        v11 = (_DWORD *)(v9[2052] + v8);
        v8 += 8;
        *v11 = v11;
        v11[1] = v11;
      }
      while ( v8 < 0x1FF8 );
      if ( ViVerifyOnlySpinlocksFromRegistry )
      {
        __dmb(0xBu);
        ViDeadlockVerifyOnlySpinlocks = 1;
        v9 = (_DWORD *)ViDeadlockGlobals;
      }
      if ( ViRecursionDepthLimitFromRegistry )
        v9[4106] = ViRecursionDepthLimitFromRegistry;
      else
        v9[4106] = 4;
      if ( ViSearchedNodesLimitFromRegistry )
        v9[4107] = ViSearchedNodesLimitFromRegistry;
      else
        v9[4107] = 1000;
      if ( a2 )
        v12 = 512;
      else
        v12 = 32;
      if ( a2 )
        v13 = ViDeadlockKernelVerifierLookasideAllocate;
      else
        v13 = 0;
      pXdvExInitializeNPagedLookasideList(
        &ViDeadlockThreadLookaside,
        v13,
        VfUtilFreePoolCheckIRQL,
        512,
        32,
        1919439958,
        v12,
        VfInitializedWithoutReboot,
        ExInitializeNPagedLookasideListInternal);
      v14 = 0x2000;
      if ( a2 )
      {
        v15 = ViDeadlockKernelVerifierLookasideAllocate;
      }
      else
      {
        v14 = 64;
        v15 = 0;
      }
      pXdvExInitializeNPagedLookasideList(
        &ViDeadlockResourceLookaside,
        v15,
        VfUtilFreePoolCheckIRQL,
        512,
        128,
        1936020054,
        v14,
        VfInitializedWithoutReboot,
        ExInitializeNPagedLookasideListInternal);
      v16 = 0x4000;
      if ( a2 )
      {
        v17 = ViDeadlockKernelVerifierLookasideAllocate;
      }
      else
      {
        v16 = 64;
        v17 = 0;
      }
      v18 = pXdvExInitializeNPagedLookasideList(
              &ViDeadlockNodeLookaside,
              v17,
              VfUtilFreePoolCheckIRQL,
              512,
              108,
              1685016150,
              v16,
              VfInitializedWithoutReboot,
              ExInitializeNPagedLookasideListInternal);
      if ( a2 )
      {
        ViDeadlockPopulateLookasideCache(&ViDeadlockThreadLookaside, 512);
        ViDeadlockPopulateLookasideCache(&ViDeadlockNodeLookaside, 0x4000);
        v18 = ViDeadlockPopulateLookasideCache(&ViDeadlockResourceLookaside, 0x2000);
        v19 = ViDeadlockState | 2;
        ViDeadlockState |= 2u;
      }
      else
      {
        v19 = ViDeadlockState;
      }
      if ( a1 )
        ViDeadlockState = v19 | 4;
      result = (_BYTE *)ViDeadlockDetectionApplySettings(v18);
    }
    else
    {
      v20 = *(_DWORD *)(v6 + 16);
      if ( v20 )
      {
        ExFreePoolWithTag(v20);
        v6 = ViDeadlockGlobals;
      }
      v21 = *(_DWORD *)(v6 + 8208);
      if ( v21 )
      {
        ExFreePoolWithTag(v21);
        v6 = ViDeadlockGlobals;
      }
      result = (_BYTE *)ExFreePoolWithTag(v6);
      ViDeadlockGlobals = 0;
    }
  }
  return result;
}
