// AlpcpDispatchConnectionRequest 
 
int __fastcall AlpcpDispatchConnectionRequest(int *a1)
{
  unsigned int v1; // r8
  int *v3; // r9
  unsigned int *v4; // r4
  int v5; // r0
  unsigned int v6; // r2
  _DWORD *v8; // r6
  unsigned int *v9; // r5
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  unsigned int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r4
  unsigned int v21; // r2
  unsigned int v22; // r2
  unsigned int v23; // r2
  unsigned int v24; // r2
  unsigned int v25; // r2
  unsigned int v26; // r2
  unsigned int v27; // r2
  int v28; // [sp+0h] [bp-28h]
  int v29; // [sp+4h] [bp-24h]

  v1 = a1[1];
  v28 = a1[6];
  v29 = *a1;
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  v3 = *(int **)(v29 + 8);
  v4 = (unsigned int *)(v3 - 1);
  v5 = KeAbPreAcquire((unsigned int)(v3 - 1), 0, 0);
  do
    v6 = __ldrex(v4);
  while ( !v6 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v6 )
    return sub_7F4024(v5, 17);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v8 = (_DWORD *)*v3;
  if ( !*v3 )
    goto LABEL_64;
  if ( !ObReferenceObjectSafe(*v3) )
    v8 = 0;
  if ( !v8 )
  {
LABEL_64:
    __dmb(0xBu);
    do
      v27 = __ldrex(v4);
    while ( v27 == 17 && __strex(0, v4) );
    if ( v27 != 17 )
      ExfReleasePushLockShared(v3 - 1);
    KeAbPostRelease((unsigned int)(v3 - 1));
    return -1073741769;
  }
  v9 = v8 + 52;
  v10 = KeAbPreAcquire((unsigned int)(v8 + 52), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v8 + 52, v10, (unsigned int)(v8 + 52));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( (v8[61] & 0x20) != 0 )
  {
    __dmb(0xBu);
    do
      v21 = __ldrex(v4);
    while ( v21 == 17 && __strex(0, v4) );
    if ( v21 != 17 )
      ExfReleasePushLockShared(v3 - 1);
    KeAbPostRelease((unsigned int)(v3 - 1));
    __dmb(0xBu);
    do
      v22 = __ldrex(v9);
    while ( v22 == 17 && __strex(0, v9) );
    if ( v22 != 17 )
      ExfReleasePushLockShared(v8 + 52);
    KeAbPostRelease((unsigned int)(v8 + 52));
    v20 = -1073741769;
  }
  else if ( (unsigned int)*(unsigned __int16 *)(v1 + 122) > v8[42] )
  {
    __dmb(0xBu);
    do
      v23 = __ldrex(v4);
    while ( v23 == 17 && __strex(0, v4) );
    if ( v23 != 17 )
      ExfReleasePushLockShared(v3 - 1);
    KeAbPostRelease((unsigned int)(v3 - 1));
    __dmb(0xBu);
    do
      v24 = __ldrex(v9);
    while ( v24 == 17 && __strex(0, v9) );
    if ( v24 != 17 )
      ExfReleasePushLockShared(v8 + 52);
    KeAbPostRelease((unsigned int)(v8 + 52));
    v20 = -1073741789;
  }
  else
  {
    if ( (v28 & 0x20000) == 0 )
    {
LABEL_26:
      *(_DWORD *)(v1 + 20) &= 0xFFFFFDFF;
      *(_WORD *)(v1 + 124) |= 0x2000u;
      __dmb(0xBu);
      v16 = v8 + 58;
      do
      {
        v17 = __ldrex(v16);
        v18 = v17 + 1;
      }
      while ( __strex(v18, v16) );
      __dmb(0xBu);
      *(_DWORD *)(v1 + 24) = v18;
      *(_DWORD *)(v1 + 64) = 0;
      *(_DWORD *)(v1 + 92) = v3;
      *(_DWORD *)(v1 + 96) = v8;
      ObfReferenceObject(v29);
      v19 = *(_DWORD *)(v1 + 20);
      *(_DWORD *)(v1 + 12) = v29;
      *(_DWORD *)(v1 + 20) = v19 | 0x1000;
      a1[4] = (int)v8;
      a1[2] = (int)v3;
      AlpcpCompleteDispatchMessage(a1);
      return 0;
    }
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (*(_DWORD *)(v13 + 0x3C4) & 8) == 0 )
    {
      ++*(_WORD *)(v1 - 14);
      __dmb(0xBu);
      v14 = (unsigned int *)(v13 + 976);
      do
        v15 = __ldrex(v14);
      while ( __strex(v1, v14) );
      __dmb(0xBu);
      ++*(_WORD *)(v1 - 14);
      *(_DWORD *)(v1 + 16) = v13;
      goto LABEL_26;
    }
    __dmb(0xBu);
    do
      v25 = __ldrex(v4);
    while ( v25 == 17 && __strex(0, v4) );
    if ( v25 != 17 )
      ExfReleasePushLockShared(v3 - 1);
    KeAbPostRelease((unsigned int)(v3 - 1));
    __dmb(0xBu);
    do
      v26 = __ldrex(v9);
    while ( v26 == 17 && __strex(0, v9) );
    if ( v26 != 17 )
      ExfReleasePushLockShared(v8 + 52);
    KeAbPostRelease((unsigned int)(v8 + 52));
    v20 = -1073741823;
  }
  ObfDereferenceObject((int)v8);
  return v20;
}
