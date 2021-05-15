// CmpIsSystemEntity 
 
int __fastcall CmpIsSystemEntity(int *a1, int a2, unsigned int *a3, unsigned int a4)
{
  int v4; // r6
  char v6; // r5
  _DWORD *v7; // r7
  int v8; // r3
  unsigned int v9; // r8
  int v10; // r9
  unsigned int v11; // r5
  int v12; // r3
  int v13; // r3
  int v15; // r2
  __int16 v16; // r3
  int v17; // r10
  unsigned int *v18; // r0
  unsigned int v19; // r2
  int v20; // r7
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r1
  __int16 v24; // r3
  unsigned int *v25; // r7
  int v26; // r0
  int v27; // r5
  unsigned int v28; // r2
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r3
  int v32; // [sp+0h] [bp-28h] BYREF
  unsigned int *v33; // [sp+4h] [bp-24h]
  unsigned int v34; // [sp+8h] [bp-20h]

  v32 = a2;
  v33 = a3;
  v34 = a4;
  v4 = 1;
  if ( !CmpVEEnabled )
    return 1;
  if ( a1 && (*a1 & 1) != 0 )
  {
    if ( (*a1 & 2) == 0 )
      return sub_7FC510();
    return 1;
  }
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v6 = 0;
    v32 = 0;
    v7 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v8 = __mrc(15, 0, 13, 0, 3);
    v9 = v8 & 0xFFFFFFC0;
    if ( v7 == (_DWORD *)(v8 & 0xFFFFFFC0) )
      v10 = *(_DWORD *)((v8 & 0xFFFFFFC0) + 0x74);
    else
      v10 = v7[84];
    if ( (v7[240] & 8) == 0 )
      goto LABEL_8;
    v15 = __mrc(15, 0, 13, 0, 3);
    v16 = *(_WORD *)((v15 & 0xFFFFFFC0) + 0x134);
    v34 = v15 & 0xFFFFFFC0;
    *(_WORD *)((v15 & 0xFFFFFFC0) + 0x134) = v16 - 1;
    v33 = v7 + 236;
    v17 = KeAbPreAcquire((unsigned int)(v7 + 236), 0, 0);
    v18 = v7 + 236;
    do
      v19 = __ldrex(v18);
    while ( !v19 && __strex(0x11u, v18) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(v18, v17, (unsigned int)(v7 + 236));
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    if ( (v7[240] & 8) != 0 )
    {
      v20 = v7[226] & 0xFFFFFFF8;
      ObfReferenceObject(v20);
    }
    else
    {
      v20 = 0;
    }
    __dmb(0xBu);
    do
      v21 = __ldrex(v33);
    while ( v21 == 17 && __strex(0, v33) );
    if ( v21 != 17 )
      ExfReleasePushLockShared(v33);
    v22 = KeAbPostRelease((unsigned int)v33);
    v23 = v34;
    v24 = *(_WORD *)(v34 + 308) + 1;
    *(_WORD *)(v34 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
    if ( v20 )
    {
      ObfDereferenceObject(v20);
    }
    else
    {
LABEL_8:
      v11 = ObFastReferenceObject((_DWORD *)(v10 + 244));
      if ( !v11 )
      {
        --*(_WORD *)(v9 + 308);
        v25 = (unsigned int *)(v10 + 168);
        v26 = KeAbPreAcquire(v10 + 168, 0, 0);
        v27 = v26;
        do
          v28 = __ldrex(v25);
        while ( !v28 && __strex(0x11u, v25) );
        __dmb(0xBu);
        if ( v28 )
          ExfAcquirePushLockSharedEx((_DWORD *)(v10 + 168), v26, v10 + 168);
        if ( v27 )
          *(_BYTE *)(v27 + 14) |= 1u;
        v11 = ObFastReferenceObjectLocked((_DWORD *)(v10 + 244));
        __dmb(0xBu);
        do
          v29 = __ldrex(v25);
        while ( v29 == 17 && __strex(0, v25) );
        if ( v29 != 17 )
          ExfReleasePushLockShared((_DWORD *)(v10 + 168));
        v30 = KeAbPostRelease(v10 + 168);
        v31 = (__int16)(*(_WORD *)(v9 + 308) + 1);
        *(_WORD *)(v9 + 308) = v31;
        if ( !v31 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
          KiCheckForKernelApcDelivery(v30);
      }
      SeQueryInformationToken(v11, 24, &v32);
      ObFastDereferenceObject((_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244), v11);
      v6 = v32;
    }
    if ( v6 )
      v4 = 0;
  }
  if ( a1 )
  {
    v12 = *a1 | 1;
    *a1 = v12;
    if ( v4 )
      v13 = v12 | 2;
    else
      v13 = v12 | 4;
    *a1 = v13;
  }
  return v4;
}
