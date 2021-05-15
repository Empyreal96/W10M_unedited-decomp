// SepIsParentOfChildAppContainer 
 
int __fastcall SepIsParentOfChildAppContainer(unsigned int a1, int a2, int a3)
{
  int v3; // r7
  int v4; // r9
  int *v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r6
  unsigned int v16; // r2
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int *v27; // [sp+8h] [bp-28h] BYREF
  int v28; // [sp+Ch] [bp-24h] BYREF
  int v29[8]; // [sp+10h] [bp-20h] BYREF

  v3 = 0;
  v27 = 0;
  v28 = 0;
  v29[0] = 0;
  v4 = 0;
  if ( !a2 || !a3 )
    return 0;
  if ( a1 >= 5 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire((unsigned int)&LowboxSessionMapLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned int *)&LowboxSessionMapLock);
    while ( !v12 && __strex(0x11u, (unsigned int *)&LowboxSessionMapLock) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(&LowboxSessionMapLock, v10, (unsigned int)&LowboxSessionMapLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v4 = 1;
    if ( SepGetTokenSessionMapEntry(a1, 0, &v27) < 0 )
      goto LABEL_34;
    v8 = v27;
  }
  else
  {
    v8 = &g_SessionLowboxArray[5 * a1];
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  v14 = KeAbPreAcquire((unsigned int)v8, 0, 0);
  v15 = v14;
  do
    v16 = __ldrex((unsigned __int8 *)v8);
  while ( __strex(v16 | 1, (unsigned __int8 *)v8) );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v14, (unsigned int)v8);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  if ( SepFindMatchingLowBoxNumberEntries((_DWORD *)v8[3], a2, a3, v29, &v28) >= 0 )
  {
    v3 = RtlIsParentOfChildAppContainer(*(_DWORD *)(v29[0] + 16), *(_DWORD *)(v28 + 16), v17, v29[0]);
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v8);
    while ( __strex(v18 - 1, (unsigned int *)v8) );
  }
  else
  {
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v8);
    while ( __strex(v18 - 1, (unsigned int *)v8) );
  }
  if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v8);
  v19 = KeAbPostRelease((unsigned int)v8);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  if ( v4 )
  {
LABEL_34:
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&LowboxSessionMapLock);
    while ( v22 == 17 && __strex(0, (unsigned int *)&LowboxSessionMapLock) );
    if ( v22 != 17 )
      ExfReleasePushLockShared(&LowboxSessionMapLock);
    v23 = KeAbPostRelease((unsigned int)&LowboxSessionMapLock);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
  }
  return v3;
}
