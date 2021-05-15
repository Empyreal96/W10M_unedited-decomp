// sub_7D1C70 
 
void __fastcall sub_7D1C70(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  unsigned int v12; // r5
  unsigned int *v13; // r7
  int v14; // r8
  int v15; // r4
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r6
  __int64 v19; // r2
  int v20; // r4
  unsigned int v21; // r1
  int v22; // r4
  int v23; // r4
  unsigned int v24; // r1

  while ( 1 )
  {
    v15 = KeAbPreAcquire(v12, 0, 0);
    v16 = KfRaiseIrql(1);
    do
      v17 = __ldrex((unsigned __int8 *)v12);
    while ( __strex(v17 & 0xFE, (unsigned __int8 *)v12) );
    __dmb(0xBu);
    if ( (v17 & v14) == 0 )
      ExpAcquireFastMutexContended(v12, v15);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= v14;
    *(_DWORD *)(v12 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v12 + 28) = v16;
    v18 = *v13;
    if ( (unsigned int *)*v13 == v13 )
    {
      __dmb(0xBu);
      CmpWorkerEngineWorkItemActive = 0;
      *(_DWORD *)(v12 + 4) = 0;
      v23 = *(_DWORD *)(v12 + 28);
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)v12);
      while ( !v24 && __strex(1u, (unsigned int *)v12) );
      if ( v24 )
        ExpReleaseFastMutexContended((unsigned int *)v12, v24);
      KfLowerIrql((unsigned __int8)v23);
      KeAbPostRelease(v12);
      __dmb(0xFu);
      if ( CmpWorkerEngineFinishedEvent )
        ExfUnblockPushLock((int)&CmpWorkerEngineFinishedEvent, 0);
      __asm { POP.W           {R3-R8,R11,PC} }
    }
    v19 = *(_QWORD *)v18;
    if ( *(unsigned int **)(v18 + 4) != v13 || *(_DWORD *)(v19 + 4) != v18 )
      __fastfail(3u);
    *v13 = v19;
    *(_DWORD *)(v19 + 4) = v13;
    *(_DWORD *)v18 = v18;
    *(_DWORD *)(v18 + 4) = v18;
    *(_DWORD *)(v12 + 4) = 0;
    v20 = *(_DWORD *)(v12 + 28);
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v12);
    while ( !v21 && __strex(1u, (unsigned int *)v12) );
    if ( v21 )
      ExpReleaseFastMutexContended((unsigned int *)v12, v21);
    KfLowerIrql((unsigned __int8)v20);
    KeAbPostRelease(v12);
    v22 = *(_DWORD *)(v18 + 8);
    (*(void (__fastcall **)(_DWORD))(v18 + 12))(*(_DWORD *)(v18 + 16));
    if ( !v22 )
      ExFreePoolWithTag(v18);
  }
}
