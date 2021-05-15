// CmpDoQueueLateUnloadWorker 
 
unsigned int __fastcall CmpDoQueueLateUnloadWorker(int a1)
{
  unsigned int v1; // r6
  _DWORD *v3; // r7
  unsigned int v4; // r8
  int v5; // r0
  unsigned int v6; // r2
  unsigned int *v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int *v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r2

  v1 = *(_DWORD *)(a1 + 1864);
  v3 = (_DWORD *)(a1 + 2540);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = KeAbPreAcquire(v1, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    return sub_7D3DE4(v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = v4;
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 3324);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 + 1;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4 * (((_BYTE)v10 - 1) & 0x7F) + 3328) = 19;
  if ( **(_DWORD **)(a1 + 2528) == 2 && !*(_DWORD *)(a1 + 2536) )
  {
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(v8);
      v14 = v13 + 1;
    }
    while ( __strex(v14, v8) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 4 * (((_BYTE)v14 - 1) & 0x7F) + 3328) = 20;
    __dmb(0xBu);
    v15 = (unsigned int *)(a1 + 2536);
    do
      v16 = __ldrex(v15);
    while ( !v16 && __strex((unsigned int)v3, v15) );
    __dmb(0xBu);
    if ( !v16 )
    {
      __dmb(0xBu);
      do
      {
        v17 = __ldrex(v8);
        v18 = v17 + 1;
      }
      while ( __strex(v18, v8) );
      __dmb(0xBu);
      *(_DWORD *)(a1 + 4 * (((_BYTE)v18 - 1) & 0x7F) + 3328) = 21;
      v3[2] = 1;
      v3[3] = CmpLateUnloadHiveWorker;
      v3[4] = a1;
      CmpReferenceHive(a1);
      CmWorkerEngineQueueWorkItem(v3);
    }
  }
  v11 = *(unsigned int **)(a1 + 1864);
  v11[1] = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex(v11);
  while ( !v12 && __strex(1u, v11) );
  if ( v12 )
    ExpReleaseFastMutexContended(v11, v12);
  return KeAbPostRelease((unsigned int)v11);
}
