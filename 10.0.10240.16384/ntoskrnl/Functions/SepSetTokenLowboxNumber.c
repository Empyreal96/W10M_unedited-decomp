// SepSetTokenLowboxNumber 
 
int __fastcall SepSetTokenLowboxNumber(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r7
  int v5; // r6
  unsigned __int8 *v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r6
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r7
  unsigned int v21; // r2
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r3
  int v26; // [sp+4h] [bp-24h] BYREF
  int v27; // [sp+8h] [bp-20h]

  v26 = a3;
  v27 = a4;
  v4 = *(_DWORD *)(a1 + 120);
  v5 = 0;
  v26 = 0;
  v27 = a2;
  if ( v4 >= 5 )
    return sub_7D654C();
  v8 = (unsigned __int8 *)&g_SessionLowboxArray[5 * v4];
  if ( !v8[16] )
  {
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v18 + 308);
    v19 = KeAbPreAcquire((unsigned int)&g_SessionLowboxArray[5 * v4], 0, 0);
    v20 = v19;
    do
      v21 = __ldrex(v8);
    while ( __strex(v21 | 1, v8) );
    __dmb(0xBu);
    if ( (v21 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v8, v19, (unsigned int)v8);
    if ( v20 )
      *(_BYTE *)(v20 + 14) |= 1u;
    if ( !v8[16] )
      v5 = SepInitializeLowBoxNumberTable(v8);
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v8);
    while ( __strex(v22 - 1, (unsigned int *)v8) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v8);
    v23 = KeAbPostRelease((unsigned int)v8);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = (__int16)(*(_WORD *)(v24 + 0x134) + 1);
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
  }
  if ( v5 )
    JUMPOUT(0x7D6668);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = KeAbPreAcquire((unsigned int)v8, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v8);
  while ( __strex(v12 | 1, v8) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v10, (unsigned int)v8);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = SepGetLowBoxNumberEntry(v8, v27, &v26);
  if ( v13 )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v8);
    while ( __strex(v14 - 1, (unsigned int *)v8) );
  }
  else
  {
    *(_DWORD *)(a1 + 628) = v26;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v8);
    while ( __strex(v14 - 1, (unsigned int *)v8) );
  }
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v8);
  v15 = KeAbPostRelease((unsigned int)v8);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v13;
}
