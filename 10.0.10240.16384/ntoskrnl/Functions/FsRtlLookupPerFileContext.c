// FsRtlLookupPerFileContext 
 
_DWORD *__fastcall FsRtlLookupPerFileContext(unsigned int **a1, int a2, int a3)
{
  unsigned int *v3; // r5
  _DWORD *v6; // r6
  unsigned int v7; // r0
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r4
  _DWORD *v11; // r4
  _DWORD *i; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  v3 = *a1;
  if ( !*a1 )
    return 0;
  v6 = v3 + 1;
  if ( (unsigned int *)v3[1] == v3 + 1 )
    return 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)v3, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v3);
  while ( !v10 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v3, v8, (unsigned int)v3);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = 0;
  if ( a3 )
  {
    for ( i = (_DWORD *)v3[1]; i != v6; i = (_DWORD *)*i )
    {
      if ( i[2] == a2 && i[3] == a3 )
        goto LABEL_23;
    }
  }
  else if ( a2 )
  {
    for ( i = (_DWORD *)v3[1]; i != v6; i = (_DWORD *)*i )
    {
      if ( i[2] == a2 )
      {
LABEL_23:
        v11 = i;
        break;
      }
    }
  }
  else if ( (_DWORD *)*v6 != v6 )
  {
    v11 = (_DWORD *)v3[1];
  }
  __pld(v3);
  v13 = *v3;
  v14 = *v3 - 16;
  if ( (*v3 & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  if ( (v13 & 2) != 0 )
    goto LABEL_33;
  __dmb(0xBu);
  do
    v15 = __ldrex(v3);
  while ( v15 == v13 && __strex(v14, v3) );
  if ( v15 != v13 )
LABEL_33:
    ExfReleasePushLock(v3, v13);
  v16 = KeAbPostRelease((unsigned int)v3);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return v11;
}
