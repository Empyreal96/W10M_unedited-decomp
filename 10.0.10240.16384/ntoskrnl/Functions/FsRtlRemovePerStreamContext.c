// FsRtlRemovePerStreamContext 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall FsRtlRemovePerStreamContext(int a1, int a2, int a3)
{
  unsigned __int8 *v6; // r6
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r6
  int v12; // r4
  int v13; // r10
  unsigned int v14; // r2
  _DWORD *v15; // r4
  _DWORD *i; // r2
  int *v17; // r5
  int v18; // r1
  unsigned int v19; // r0
  int v20; // r1 OVERLAPPED
  _DWORD *v21; // r2 OVERLAPPED
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int *v26; // r5
  unsigned int v27; // r6
  unsigned int v28; // r1

  if ( !a1 || (*(_BYTE *)(a1 + 6) & 2) == 0 )
    return 0;
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x10 )
  {
    v11 = *(_DWORD *)(a1 + 40);
    v12 = KeAbPreAcquire(v11, 0, 0);
    v13 = KfRaiseIrql(1);
    do
      v14 = __ldrex((unsigned __int8 *)v11);
    while ( __strex(v14 & 0xFE, (unsigned __int8 *)v11) );
    __dmb(0xBu);
    if ( (v14 & 1) == 0 )
      ExpAcquireFastMutexContended(v11, v12);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    *(_DWORD *)(v11 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v11 + 28) = v13;
  }
  else
  {
    v6 = (unsigned __int8 *)(a1 + 52);
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(a1 + 52, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex(v6);
    while ( __strex(v10 | 1, v6) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v6, v8, (unsigned int)v6);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
  }
  v15 = 0;
  if ( a3 )
  {
    for ( i = *(_DWORD **)(a1 + 44); i != (_DWORD *)(a1 + 44); i = (_DWORD *)*i )
    {
      if ( i[2] == a2 && i[3] == a3 )
        goto LABEL_32;
    }
  }
  else if ( a2 )
  {
    for ( i = *(_DWORD **)(a1 + 44); i != (_DWORD *)(a1 + 44); i = (_DWORD *)*i )
    {
      if ( i[2] == a2 )
      {
LABEL_32:
        v15 = i;
        goto LABEL_35;
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 44) != a1 + 44 )
  {
    v15 = *(_DWORD **)(a1 + 44);
LABEL_35:
    if ( v15 )
    {
      *(_QWORD *)&v20 = *(_QWORD *)v15;
      if ( *(_DWORD **)(*v15 + 4) != v15 || (_DWORD *)*v21 != v15 )
        __fastfail(3u);
      *v21 = v20;
      *(_DWORD *)(v20 + 4) = v21;
    }
  }
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x10 )
  {
    v26 = *(unsigned int **)(a1 + 40);
    v27 = v26[7];
    v26[1] = 0;
    __dmb(0xBu);
    do
      v28 = __ldrex(v26);
    while ( !v28 && __strex(1u, v26) );
    if ( v28 )
      ExpReleaseFastMutexContended(v26, v28);
    KfLowerIrql((unsigned __int8)v27);
    KeAbPostRelease((unsigned int)v26);
  }
  else
  {
    v17 = (int *)(a1 + 52);
    __pld(v17);
    v18 = *v17;
    if ( (*v17 & 0xFFFFFFF0) <= 0x10 )
      v19 = 0;
    else
      v19 = v18 - 16;
    if ( (v18 & 2) != 0 )
      goto LABEL_46;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v17);
    while ( v22 == v18 && __strex(v19, (unsigned int *)v17) );
    if ( v22 != v18 )
LABEL_46:
      ExfReleasePushLock(v17, v18);
    v23 = KeAbPostRelease((unsigned int)v17);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
  }
  return v15;
}
