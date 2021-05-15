// FsRtlLookupPerStreamContextInternal 
 
_DWORD *__fastcall FsRtlLookupPerStreamContextInternal(int a1, int a2, int a3)
{
  unsigned int *v6; // r8
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r4
  unsigned int v11; // r6
  int v12; // r4
  int v13; // r8
  unsigned int v14; // r2
  _DWORD *v15; // r6
  _DWORD *i; // r2
  unsigned int *v17; // r4
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int *v24; // r4
  unsigned int v25; // r5
  unsigned int v26; // r1

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
    v6 = (unsigned int *)(a1 + 52);
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(a1 + 52, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex(v6);
    while ( !v10 && __strex(0x11u, v6) );
    __dmb(0xBu);
    if ( v10 )
      ExfAcquirePushLockSharedEx(v6, v8, (unsigned int)v6);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
  }
  v15 = 0;
  if ( a3 )
  {
    for ( i = *(_DWORD **)(a1 + 44); i != (_DWORD *)(a1 + 44); i = (_DWORD *)*i )
    {
      if ( i[2] == a2 && i[3] == a3 )
        goto LABEL_29;
    }
  }
  else if ( a2 )
  {
    for ( i = *(_DWORD **)(a1 + 44); i != (_DWORD *)(a1 + 44); i = (_DWORD *)*i )
    {
      if ( i[2] == a2 )
      {
LABEL_29:
        v15 = i;
        break;
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 44) != a1 + 44 )
  {
    v15 = *(_DWORD **)(a1 + 44);
  }
  if ( (*(_BYTE *)(a1 + 7) & 0xF0u) < 0x10 )
  {
    v24 = *(unsigned int **)(a1 + 40);
    v25 = v24[7];
    v24[1] = 0;
    __dmb(0xBu);
    do
      v26 = __ldrex(v24);
    while ( !v26 && __strex(1u, v24) );
    if ( v26 )
      ExpReleaseFastMutexContended(v24, v26);
    KfLowerIrql((unsigned __int8)v25);
    KeAbPostRelease((unsigned int)v24);
  }
  else
  {
    v17 = (unsigned int *)(a1 + 52);
    __pld((void *)(a1 + 52));
    v18 = *(_DWORD *)(a1 + 52);
    v19 = v18 - 16;
    if ( (v18 & 0xFFFFFFF0) <= 0x10 )
      v19 = 0;
    if ( (v18 & 2) != 0 )
      goto LABEL_40;
    __dmb(0xBu);
    do
      v20 = __ldrex(v17);
    while ( v20 == v18 && __strex(v19, v17) );
    if ( v20 != v18 )
LABEL_40:
      ExfReleasePushLock((_DWORD *)(a1 + 52), v18);
    v21 = KeAbPostRelease(a1 + 52);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v21);
  }
  return v15;
}
