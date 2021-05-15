// EtwpRealtimeUpdateConsumers 
 
int __fastcall EtwpRealtimeUpdateConsumers(int result)
{
  unsigned int *v1; // r7
  int v2; // r3
  _DWORD *v3; // r6
  unsigned int v4; // r3
  unsigned __int8 *v5; // r4
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r8
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r3
  _DWORD *v13; // r5
  int v14; // r1
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned __int8 *v20; // r4
  int v21; // r8
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  int v25; // r5
  int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r2
  _DWORD *i; // r0
  unsigned int v30; // r1
  unsigned int v31; // r1

  v1 = (unsigned int *)(result + 612);
  v2 = *(_DWORD *)(result + 612);
  v3 = (_DWORD *)result;
  __dmb(0xBu);
  if ( (v2 & 0x20) != 0 )
  {
    v5 = (unsigned __int8 *)(result + 504);
    v6 = KeAbPreAcquire(result + 504, 0, 0);
    do
      v7 = __ldrex(v5);
    while ( __strex(v7 | 1, v5) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
      return sub_809DE4(v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v8 = v3[67];
    __pld(v5);
    v3[67] = 0;
    v9 = *(_DWORD *)v5;
    if ( (*(_DWORD *)v5 & 0xFFFFFFF0) > 0x10 )
      v10 = v9 - 16;
    else
      v10 = 0;
    if ( (v9 & 2) != 0 )
      goto LABEL_48;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)v5);
    while ( v11 == v9 && __strex(v10, (unsigned int *)v5) );
    if ( v11 != v9 )
LABEL_48:
      ExfReleasePushLock(v3 + 126, v9);
    KeAbPostRelease((unsigned int)(v3 + 126));
    v12 = *(_DWORD *)(v8 + 20);
    *(_DWORD *)(v8 + 20) = 0;
    v13 = (_DWORD *)(v12 + 80);
    v14 = v3[85];
    v15 = v3[86];
    v16 = v3[87];
    *v13 = v3[84];
    v13[1] = v14;
    v13[2] = v15;
    v13[3] = v16;
    v17 = (_DWORD *)v3[65];
    *(_DWORD *)v8 = v3 + 64;
    *(_DWORD *)(v8 + 4) = v17;
    if ( (_DWORD *)*v17 != v3 + 64 )
      __fastfail(3u);
    *v17 = v8;
    v3[65] = v8;
    ++v3[66];
    *(_BYTE *)(v8 + 50) &= 0xF7u;
    __dmb(0xBu);
    do
      v18 = __ldrex(v1);
    while ( __strex(v18 | 0x40, v1) );
    __dmb(0xBu);
    v3[10] = 0;
    __dmb(0xBu);
    do
      v19 = __ldrex(v1);
    while ( __strex(v19 & 0xFFFFFFDF, v1) );
    __dmb(0xBu);
    result = KeSetEvent((int)(v3 + 89), 0, 0);
  }
  v4 = *v1;
  __dmb(0xBu);
  if ( (v4 & 0x10) != 0 )
  {
    v20 = (unsigned __int8 *)(v3 + 126);
    v21 = -1073741162;
    v22 = KeAbPreAcquire((unsigned int)(v3 + 126), 0, 0);
    v23 = v22;
    do
      v24 = __ldrex(v20);
    while ( __strex(v24 | 1, v20) );
    __dmb(0xBu);
    if ( (v24 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v3 + 126, v22, (unsigned int)(v3 + 126));
    if ( v23 )
      *(_BYTE *)(v23 + 14) |= 1u;
    v25 = v3[67];
    __pld(v20);
    v3[67] = 0;
    v26 = *(_DWORD *)v20;
    if ( (*(_DWORD *)v20 & 0xFFFFFFF0) > 0x10 )
      v27 = v26 - 16;
    else
      v27 = 0;
    if ( (v26 & 2) != 0 )
      goto LABEL_51;
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)v20);
    while ( v28 == v26 && __strex(v27, (unsigned int *)v20) );
    if ( v28 != v26 )
LABEL_51:
      ExfReleasePushLock(v3 + 126, v26);
    KeAbPostRelease((unsigned int)(v3 + 126));
    for ( i = (_DWORD *)v3[64]; i != v3 + 64; i = (_DWORD *)*i )
    {
      if ( (_DWORD *)v25 == i && (*(_BYTE *)(v25 + 50) & 1) == 0 )
      {
        __dmb(0xBu);
        do
          v30 = __ldrex(v1);
        while ( __strex(v30 | 4, v1) );
        __dmb(0xBu);
        v21 = 0;
        *(_BYTE *)(v25 + 50) |= 1u;
      }
    }
    v3[10] = v21;
    __dmb(0xBu);
    do
      v31 = __ldrex(v1);
    while ( __strex(v31 & 0xFFFFFFEF, v1) );
    __dmb(0xBu);
    result = KeSetEvent((int)(v3 + 89), 0, 0);
  }
  return result;
}
