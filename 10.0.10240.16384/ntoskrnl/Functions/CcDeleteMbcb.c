// CcDeleteMbcb 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall CcDeleteMbcb(_DWORD *a1)
{
  unsigned int v1; // r4
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  unsigned int result; // r0
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int *v11; // r5
  int *v12; // r1 OVERLAPPED
  int **v13; // r2 OVERLAPPED
  int v14; // r1
  int v15; // r5
  unsigned int v16; // r1
  int *v17; // r0
  int **v18; // r1
  int *v19; // r1 OVERLAPPED
  int v20; // r5
  unsigned int v21; // r1
  int *v22; // [sp+8h] [bp-28h] BYREF
  int **v23; // [sp+Ch] [bp-24h]

  v23 = &v22;
  v1 = (unsigned int)(a1 + 45);
  v22 = (int *)&v22;
  v3 = KeAbPreAcquire((unsigned int)(a1 + 45), 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_54A278(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v1 + 28) = v4;
  v7 = a1[26];
  if ( v7 )
  {
    v8 = KeAcquireQueuedSpinLock(5);
    v9 = *(_DWORD *)(v7 + 8);
    CcGlobalDirtyPageStatistics -= v9;
    if ( v9 == -1 )
      KeBugCheckEx(52, 4194, -1073740768);
    v10 = a1[89];
    a1[19] -= v9;
    *(_DWORD *)(v10 + 20) -= v9;
    if ( (a1[24] & 0x1000000) != 0 )
      *(_DWORD *)(a1[38] + 12) -= v9;
    KeReleaseQueuedSpinLock(5, v8);
    while ( *(_DWORD *)(v7 + 16) != v7 + 16 )
    {
      v11 = *(int **)(v7 + 16);
      *(_QWORD *)&v12 = *(_QWORD *)v11;
      if ( *(int **)(*v11 + 4) != v11 || *v13 != v11 )
        __fastfail(3u);
      *v13 = v12;
      v12[1] = (int)v13;
      v14 = v11[7];
      if ( v14 != v7 + 72 && v14 )
        ExFreeToNPagedLookasideList(&CcBitmapLookasideList, v14);
      if ( (unsigned int)v11 < v7 || (unsigned int)v11 >= v7 + 136 )
      {
        v18 = v23;
        *v11 = (int)&v22;
        v11[1] = (int)v18;
        if ( *v18 != (int *)&v22 )
          __fastfail(3u);
        *v18 = v11;
        v23 = (int **)v11;
      }
    }
    a1[26] = 0;
    v15 = *(_DWORD *)(v1 + 28);
    *(_DWORD *)(v1 + 4) = 0;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v1);
    while ( !v16 && __strex(1u, (unsigned int *)v1) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)v1, v16);
    KfLowerIrql((unsigned __int8)v15);
    KeAbPostRelease(v1);
    while ( 1 )
    {
      v17 = v22;
      if ( v22 == (int *)&v22 )
        break;
      *(_QWORD *)&v19 = *(_QWORD *)v22;
      if ( (int **)v22[1] != &v22 || (int *)v19[1] != v22 )
        __fastfail(3u);
      v22 = v19;
      v19[1] = (int)&v22;
      ExFreePoolWithTag(v17, 0);
    }
    result = CcDeallocateBcb(v7);
  }
  else
  {
    v20 = *(_DWORD *)(v1 + 28);
    *(_DWORD *)(v1 + 4) = 0;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v1);
    while ( !v21 && __strex(1u, (unsigned int *)v1) );
    if ( v21 )
      ExpReleaseFastMutexContended((unsigned int *)v1, v21);
    KfLowerIrql((unsigned __int8)v20);
    result = KeAbPostRelease(v1);
  }
  return result;
}
