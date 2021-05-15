// FsRtlRemovePerFileContext 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall FsRtlRemovePerFileContext(unsigned int *a1, int a2, int a3)
{
  unsigned int v5; // r5
  _DWORD *v6; // r4
  _DWORD *v7; // r6
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  _DWORD *i; // r2
  int v13; // r1
  unsigned int v14; // r0
  int v15; // r1 OVERLAPPED
  _DWORD *v16; // r2 OVERLAPPED
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3

  __dmb(0xBu);
  do
    v5 = __ldrex(a1);
  while ( !v5 && __strex(0, a1) );
  __dmb(0xBu);
  if ( !v5 )
    return 0;
  v7 = (_DWORD *)(v5 + 4);
  if ( *(_DWORD *)(v5 + 4) == v5 + 4 )
    return 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(v5, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v11 | 1, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v5, v9, v5);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v6 = 0;
  if ( a3 )
  {
    for ( i = *(_DWORD **)(v5 + 4); i != v7; i = (_DWORD *)*i )
    {
      if ( i[2] == a2 && i[3] == a3 )
        goto LABEL_27;
    }
  }
  else if ( a2 )
  {
    for ( i = *(_DWORD **)(v5 + 4); i != v7; i = (_DWORD *)*i )
    {
      if ( i[2] == a2 )
      {
LABEL_27:
        v6 = i;
        goto LABEL_30;
      }
    }
  }
  else if ( (_DWORD *)*v7 != v7 )
  {
    v6 = *(_DWORD **)(v5 + 4);
LABEL_30:
    if ( v6 )
    {
      *(_QWORD *)&v15 = *(_QWORD *)v6;
      if ( *(_DWORD **)(*v6 + 4) != v6 || (_DWORD *)*v16 != v6 )
        __fastfail(3u);
      *v16 = v15;
      *(_DWORD *)(v15 + 4) = v16;
    }
  }
  __pld((void *)v5);
  v13 = *(_DWORD *)v5;
  if ( (*(_DWORD *)v5 & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  else
    v14 = v13 - 16;
  if ( (v13 & 2) != 0 )
    goto LABEL_41;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v5);
  while ( v17 == v13 && __strex(v14, (unsigned int *)v5) );
  if ( v17 != v13 )
LABEL_41:
    ExfReleasePushLock((_DWORD *)v5, v13);
  v18 = KeAbPostRelease(v5);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return v6;
}
