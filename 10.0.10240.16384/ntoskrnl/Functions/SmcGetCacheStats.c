// SmcGetCacheStats 
 
int __fastcall SmcGetCacheStats(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  int v5; // r0
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r7
  unsigned int *v10; // r8
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  _DWORD *v15; // r1
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  _DWORD *v21; // r0
  unsigned int v22; // r4
  unsigned int v23; // r1

  v2 = a2 + 2;
  memset((_BYTE *)a2 + 8, 0, 1120);
  v5 = SmcCacheReference(a1, a2[1]);
  v6 = v5;
  if ( !v5 )
    return -1073741672;
  v8 = v2[5] & 0xFFFFFFC0 | 1;
  v2[5] = v8;
  *v2 = *(_DWORD *)(v5 + 16);
  v2[1] = *(_DWORD *)(v5 + 20);
  v2[3] = *(_DWORD *)(v5 + 8);
  v2[4] = *(_DWORD *)(v5 + 24);
  v2[23] = *(_DWORD *)(v5 + 32);
  v2[5] = ((unsigned __int8)v8 ^ (unsigned __int8)(*(_BYTE *)(v5 + 28) << 6)) & 0x40 ^ v8;
  if ( (*a2 & 0x100) != 0 || (v7 = SmKmFileInfoGetPath(v5 + 40, v2 + 24, 1024), v7 >= 0) )
  {
    v2[22] = 0;
    v9 = 0;
    v10 = (unsigned int *)(v6 + 120);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire(v6 + 120, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v10);
    while ( !v14 && __strex(0x11u, v10) );
    __dmb(0xBu);
    if ( v14 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v6 + 120), v12, v6 + 120);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v15 = (_DWORD *)(v6 + 124);
    v16 = 16;
    do
    {
      if ( *v15 != -1 )
      {
        v2[v9 + 6] = *v15;
        if ( (v15[1] & 3) == 0 )
          v2[22] |= 1 << v9;
        ++v9;
      }
      v15 += 4;
      --v16;
    }
    while ( v16 );
    __dmb(0xBu);
    do
      v17 = __ldrex(v10);
    while ( v17 == 17 && __strex(0, v10) );
    if ( v17 != 17 )
      ExfReleasePushLockShared((_DWORD *)(v6 + 120));
    v18 = KeAbPostRelease(v6 + 120);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
    v2[2] = v9;
    v7 = 0;
  }
  v21 = (_DWORD *)(a1 + 16 * (a2[1] & 0xF) + 4);
  __pld(v21);
  v22 = *v21 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v23 = __ldrex(v21);
  while ( v23 == v22 && __strex(v22 - 2, v21) );
  if ( v23 != v22 )
    ExfReleaseRundownProtection((unsigned __int8 *)v21);
  return v7;
}
