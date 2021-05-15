// AlpcpQueryRemoteView 
 
int __fastcall AlpcpQueryRemoteView(int a1, int a2, _DWORD *a3)
{
  int *v3; // r7
  unsigned int *v6; // r5
  int v7; // r0
  unsigned int v8; // r4
  int v10; // r6
  int v11; // r0
  unsigned int v12; // r2
  int v13; // r8
  unsigned __int8 *v14; // r7
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r2
  unsigned int *v18; // r1
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r5
  int v23; // r9
  unsigned int *v24; // r7
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  unsigned int v29; // r2

  v3 = *(int **)(a1 + 8);
  v6 = (unsigned int *)(v3 - 1);
  v7 = KeAbPreAcquire((unsigned int)(v3 - 1), 0, 0);
  do
    v8 = __ldrex(v6);
  while ( !v8 && __strex(0x11u, v6) );
  __dmb(0xBu);
  if ( v8 )
    return sub_7E860C(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v10 = *v3;
  if ( !*v3 || !v3[1] )
  {
    __dmb(0xBu);
    do
      v29 = __ldrex(v6);
    while ( v29 == 17 && __strex(0, v6) );
    goto LABEL_52;
  }
  if ( (*(_DWORD *)(v10 + 244) & 0x1000) != 0 )
    v10 = v3[1];
  v11 = ObReferenceObjectSafe(v10);
  __dmb(0xBu);
  if ( !v11 )
  {
    do
      v29 = __ldrex(v6);
    while ( v29 == 17 && __strex(0, v6) );
LABEL_52:
    if ( v29 != 17 )
      ExfReleasePushLockShared(v3 - 1);
    KeAbPostRelease((unsigned int)(v3 - 1));
    return -1073741769;
  }
  do
    v12 = __ldrex(v6);
  while ( v12 == 17 && __strex(0, v6) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(v3 - 1);
  KeAbPostRelease((unsigned int)(v3 - 1));
  v13 = *(_DWORD *)(a2 + 8);
  v14 = (unsigned __int8 *)(v13 - 4);
  v15 = KeAbPreAcquire(v13 - 4, 0, 0);
  v16 = v15;
  do
    v17 = __ldrex(v14);
  while ( __strex(v17 | 1, v14) );
  __dmb(0xBu);
  if ( (v17 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 - 4), v15, v13 - 4);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  *(_BYTE *)(v13 - 16) |= 1u;
  __dmb(0xBu);
  v18 = (unsigned int *)(v13 - 12);
  do
  {
    v19 = __ldrex(v18);
    v20 = v19 + 0x10000;
  }
  while ( __strex(v20, v18) );
  __dmb(0xBu);
  if ( v20 <= 0 )
    KeBugCheckEx(24, 0, v13, 38, v20);
  v21 = AlpcpLocateView(v13, v10);
  if ( v21 )
  {
    *a3 = 12;
    v22 = 0;
    a3[2] = *(_DWORD *)(v21 + 20);
    a3[1] = *(_DWORD *)(v21 + 24);
  }
  else
  {
    v22 = -1073741670;
  }
  v23 = 0;
  if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
  {
    v23 = 0x10000 - *(__int16 *)(v13 - 14);
    *(_BYTE *)(v13 - 16) &= 0xFEu;
    *(_WORD *)(v13 - 14) = 0;
  }
  v24 = (unsigned int *)(v13 - 4);
  __dmb(0xBu);
  do
    v25 = __ldrex(v24);
  while ( __strex(v25 - 1, v24) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v13 - 4));
  KeAbPostRelease(v13 - 4);
  if ( v23 > 0 )
  {
    __dmb(0xBu);
    v26 = (unsigned int *)(v13 - 12);
    do
    {
      v27 = __ldrex(v26);
      v28 = v27 - v23;
    }
    while ( __strex(v28, v26) );
    __dmb(0xBu);
    if ( v28 <= 0 )
    {
      if ( v28 )
        KeBugCheckEx(24, 0, v13, 40, v28);
      AlpcpDestroyBlob(v13);
    }
  }
  ObfDereferenceObject(v10);
  return v22;
}
