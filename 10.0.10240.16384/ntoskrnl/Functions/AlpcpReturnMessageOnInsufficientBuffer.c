// AlpcpReturnMessageOnInsufficientBuffer 
 
int __fastcall AlpcpReturnMessageOnInsufficientBuffer(_DWORD *a1, int a2)
{
  unsigned int *v2; // r4
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r2
  int v9; // r9
  unsigned __int8 *v10; // r6
  int v11; // r0
  int v12; // r8
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned __int8 *v15; // r6
  int v16; // r0
  int v17; // r8
  unsigned int v18; // r2
  __int64 v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r2

  v2 = a1 + 52;
  v5 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v2);
  while ( !v7 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(v2, v5, (unsigned int)v2);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( *(_DWORD **)(a2 + 36) == a1 )
    return sub_7E5B94();
  v9 = *(_DWORD *)(a2 + 8);
  if ( v9 )
  {
    v10 = (unsigned __int8 *)(v9 + 112);
    v11 = KeAbPreAcquire(v9 + 112, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( __strex(v13 | 1, v10) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 112), v11, v9 + 112);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    --*(_DWORD *)(v9 + 268);
    *(_DWORD *)(a2 + 20) &= 0xFFFFFFF8;
    *(_DWORD *)(a2 + 8) = 0;
    **(_DWORD **)(a2 + 4) = *(_DWORD *)a2;
    *(_DWORD *)(*(_DWORD *)a2 + 4) = *(_DWORD *)(a2 + 4);
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v10);
    while ( __strex(v14 - 1, (unsigned int *)v10) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v10);
    KeAbPostRelease((unsigned int)v10);
    --*(_WORD *)(a2 - 14);
    goto LABEL_21;
  }
  if ( (a1[61] & 0x40) == 0 )
  {
LABEL_21:
    v15 = (unsigned __int8 *)(a1 + 23);
    ++*(_WORD *)(a2 - 14);
    v16 = KeAbPreAcquire((unsigned int)(a1 + 23), 0, 0);
    v17 = v16;
    do
      v18 = __ldrex(v15);
    while ( __strex(v18 | 1, v15) );
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 23, v16, (unsigned int)(a1 + 23));
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    *(_DWORD *)(a2 + 8) = a1;
    LODWORD(v19) = a1 + 26;
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(a2 + 20) & 0xFFFFFF82 | (4 * (a1[61] & 6)) | 2;
    HIDWORD(v19) = a1[27];
    *(_QWORD *)a2 = v19;
    *(_DWORD *)a1[27] = a2;
    a1[27] = a2;
    ++a1[66];
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v15);
    while ( __strex(v20 - 1, (unsigned int *)v15) );
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 23);
    KeAbPostRelease((unsigned int)(a1 + 23));
    __dmb(0xBu);
    do
      v21 = __ldrex(v2);
    while ( v21 == 17 && __strex(0, v2) );
    if ( v21 != 17 )
      ExfReleasePushLockShared(v2);
    KeAbPostRelease((unsigned int)v2);
    return -1073741789;
  }
  __dmb(0xBu);
  do
    v22 = __ldrex(v2);
  while ( v22 == 17 && __strex(0, v2) );
  if ( v22 != 17 )
    ExfReleasePushLockShared(v2);
  KeAbPostRelease((unsigned int)v2);
  return -1073740032;
}
