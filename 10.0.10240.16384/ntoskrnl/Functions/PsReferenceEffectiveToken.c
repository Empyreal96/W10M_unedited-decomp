// PsReferenceEffectiveToken 
 
int __fastcall PsReferenceEffectiveToken(_DWORD *a1, _DWORD *a2, bool *a3, int *a4, _BYTE *a5)
{
  int v8; // r4
  unsigned int v9; // r8
  int v10; // r7
  unsigned int v11; // r4
  int result; // r0
  int v13; // r4
  unsigned int *v14; // r0
  unsigned int v15; // r2
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r0
  __int16 v19; // r3
  unsigned int *v20; // r6
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r2
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r3
  int v28; // [sp+4h] [bp-2Ch]
  unsigned int *v29; // [sp+8h] [bp-28h]
  unsigned int v30; // [sp+Ch] [bp-24h]

  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = v8 & 0xFFFFFFC0;
  if ( a1 == (_DWORD *)(v8 & 0xFFFFFFC0) )
    v10 = *(_DWORD *)((v8 & 0xFFFFFFC0) + 0x74);
  else
    v10 = a1[84];
  if ( (a1[240] & 8) == 0 )
    goto LABEL_4;
  v28 = a1[84];
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v30 + 308);
  v29 = a1 + 236;
  v13 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
  v14 = a1 + 236;
  do
    v15 = __ldrex(v14);
  while ( !v15 && __strex(0x11u, v14) );
  __dmb(0xBu);
  if ( v15 )
    return sub_7F9C6C();
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  if ( (a1[240] & 8) != 0 )
  {
    v16 = a1[226] & 0xFFFFFFF8;
    ObfReferenceObject(v16);
    *a4 = a1[226] & 3;
    *a3 = (a1[226] & 4) != 0;
    if ( a5 )
      *a5 = *(_BYTE *)(v28 + 734);
  }
  else
  {
    v16 = 0;
  }
  __dmb(0xBu);
  do
    v17 = __ldrex(v29);
  while ( v17 == 17 && __strex(0, v29) );
  if ( v17 != 17 )
    ExfReleasePushLockShared(v29);
  v18 = KeAbPostRelease((unsigned int)v29);
  v19 = *(_WORD *)(v30 + 308) + 1;
  *(_WORD *)(v30 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
    KiCheckForKernelApcDelivery(v18);
  if ( v16 )
  {
    *a2 = 2;
    result = v16;
  }
  else
  {
LABEL_4:
    v11 = ObFastReferenceObject((_DWORD *)(v10 + 244));
    if ( !v11 )
    {
      --*(_WORD *)(v9 + 308);
      v20 = (unsigned int *)(v10 + 168);
      v21 = KeAbPreAcquire(v10 + 168, 0, 0);
      v22 = v21;
      do
        v23 = __ldrex(v20);
      while ( !v23 && __strex(0x11u, v20) );
      __dmb(0xBu);
      if ( v23 )
        ExfAcquirePushLockSharedEx((_DWORD *)(v10 + 168), v21, v10 + 168);
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      v11 = ObFastReferenceObjectLocked((_DWORD *)(v10 + 244));
      __dmb(0xBu);
      do
        v24 = __ldrex(v20);
      while ( v24 == 17 && __strex(0, v20) );
      if ( v24 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v10 + 168));
      v25 = KeAbPostRelease(v10 + 168);
      v26 = (__int16)(*(_WORD *)(v9 + 308) + 1);
      *(_WORD *)(v9 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
        KiCheckForKernelApcDelivery(v25);
    }
    *a2 = 1;
    *a3 = 0;
    result = v11;
    if ( a5 )
      *a5 = *(_BYTE *)(v10 + 734);
  }
  return result;
}
