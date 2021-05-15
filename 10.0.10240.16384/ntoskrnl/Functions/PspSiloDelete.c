// PspSiloDelete 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspSiloDelete(int a1)
{
  int v2; // r2
  int v3; // r3
  int *v4; // r4
  int *v5; // r1 OVERLAPPED
  int **v6; // r2 OVERLAPPED
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  int v10; // r6
  int v11; // r7
  unsigned int v12; // r2
  __int64 v13; // r0
  unsigned __int8 v14; // r6
  unsigned int v15; // r1
  _DWORD *v16; // r4
  int v17; // r2
  int v18; // r3
  __int64 v19; // kr00_8
  int v20; // r3
  int v21; // r0
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  unsigned int v25; // r2
  _DWORD *v26; // r0
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x136) - 1;
  *(_WORD *)(v2 + 310) = v3;
  ExAcquireResourceExclusiveLite(a1 + 28, 1, v2, v3);
  while ( *(_DWORD *)(a1 + 120) != a1 + 120 )
  {
    v4 = *(int **)(a1 + 120);
    ObfDereferenceObject(v4[3]);
    *(_QWORD *)&v5 = *(_QWORD *)v4;
    if ( *(int **)(*v4 + 4) != v4 || *v6 != v4 )
      __fastfail(3u);
    *v6 = v5;
    v5[1] = (int)v6;
    ExFreePoolWithTag((unsigned int)v4);
  }
  v7 = ExReleaseResourceLite(a1 + 28);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x136) + 1;
  *(_WORD *)(v8 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    KiCheckForKernelApcDelivery(v7);
  v10 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
  v11 = KfRaiseIrql(1);
  do
    v12 = __ldrex((unsigned __int8 *)&PspSiloListLock);
  while ( __strex(v12 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PspSiloListLock, v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61DA5C = v11;
  v13 = *(_QWORD *)(a1 + 20);
  if ( *(_DWORD *)(v13 + 4) != a1 + 20 || *(_DWORD *)HIDWORD(v13) != a1 + 20 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v13) = v13;
  *(_DWORD *)(v13 + 4) = HIDWORD(v13);
  dword_61DA44 = 0;
  v14 = dword_61DA5C;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&PspSiloListLock);
  while ( !v15 && __strex(1u, (unsigned int *)&PspSiloListLock) );
  if ( v15 )
    ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v15);
  KfLowerIrql(v14);
  KeAbPostRelease((unsigned int)&PspSiloListLock);
  v16 = *(_DWORD **)(a1 + 84);
  if ( v16 )
  {
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(__int16 *)(v17 + 0x136) - 1;
    *(_WORD *)(v17 + 310) = v18;
    ExAcquireResourceExclusiveLite((int)(v16 + 7), 1, v17, v18);
    v19 = *(_QWORD *)(a1 + 88);
    if ( *(_DWORD *)(v19 + 4) != a1 + 88 || *(_DWORD *)HIDWORD(v19) != a1 + 88 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v19) = v19;
    *(_DWORD *)(v19 + 4) = HIDWORD(v19);
    v20 = v16[24] - 1;
    v16[24] = v20;
    if ( !v20 && !v16[25] )
    {
      v21 = (int)(v16 + 32);
      if ( !v16[36] )
        v21 = (int)v16;
      KeSetEvent(v21, 0, 0);
    }
    v22 = ExReleaseResourceLite((int)(v16 + 7));
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x136) + 1;
    *(_WORD *)(v23 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 )
      KiCheckForKernelApcDelivery(v22);
    ObDereferenceObjectDeferDelete((int)v16);
  }
  if ( *(_DWORD *)(a1 + 144) )
    PspServerSiloDelete(a1);
  if ( *(_DWORD *)(a1 + 16) )
  {
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v25 + 308);
    v26 = ExMapHandleToPointer(PspSiloIdTable, *(_DWORD *)(a1 + 16));
    v27 = ExDestroyHandle(PspSiloIdTable, *(_DWORD *)(a1 + 16), v26);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  return ExDeleteResourceLite((_DWORD *)(a1 + 28));
}
