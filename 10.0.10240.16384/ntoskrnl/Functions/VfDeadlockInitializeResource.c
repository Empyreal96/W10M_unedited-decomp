// VfDeadlockInitializeResource 
 
int __fastcall VfDeadlockInitializeResource(int a1, int a2, int a3)
{
  int v5; // r3
  int v6; // r1
  _DWORD *v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r4
  int v10; // r5
  _DWORD *v11; // r0
  _DWORD *v12; // r4
  _DWORD *v14; // [sp+8h] [bp-38h] BYREF
  _DWORD *v15; // [sp+Ch] [bp-34h] BYREF
  int v16[12]; // [sp+10h] [bp-30h] BYREF

  v14 = 0;
  v15 = 0;
  if ( !ViDeadlockCanProceed(a1, 1) )
    return 0;
  v5 = *(_DWORD *)(ViDeadlockGlobals + 16400);
  __dmb(0xBu);
  if ( v5 )
    return 0;
  v6 = ViDeadlockChildrenCountMaximum;
  __dmb(0xBu);
  if ( *(_DWORD *)(ViDeadlockGlobals + 16604) > v6 )
    return 0;
  v7 = (_DWORD *)ViDeadlockAllocate(1);
  if ( !v7 )
    return 0;
  v8 = RtlCaptureStackBackTrace(2u, 8u, (int)v16, 0);
  if ( !v8 )
  {
    v16[0] = a3;
    v8 = 1;
  }
  if ( v8 < 8 )
    v16[v8] = 0;
  v9 = ViRaiseIrqlToDpcLevel(v8);
  ViDeadlockDetectionLock(1);
  v10 = ViDeadlockAddResource(a1, 1, v7, v16, &v15, &v14);
  ViDeadlockDetectionUnlock(1);
  ViLowerIrql(v9);
  if ( !v10 )
    ExFreeToNPagedLookasideList((int)&ViDeadlockResourceLookaside, v7);
  if ( v15 )
    ExFreeToNPagedLookasideList((int)&ViDeadlockResourceLookaside, v15);
  v11 = v14;
  if ( v14 )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      ViDeadlockFree(v11, 2);
      v11 = v12;
    }
    while ( v12 );
  }
  return v10;
}
