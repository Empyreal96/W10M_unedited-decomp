// MiProtectAweRegion 
 
int __fastcall MiProtectAweRegion(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // r7
  unsigned int v4; // r5
  unsigned int v5; // r8
  int v6; // lr
  unsigned int v7; // r6
  int v8; // r1
  int v9; // r2
  unsigned int v10; // r4
  _DWORD *v11; // r10
  int v12; // r3
  unsigned int v13; // r8
  int v14; // r3
  int v15; // r9
  int v16; // r0
  int v17; // r0
  int v18; // r1
  __int16 v19; // r3
  unsigned int v21; // [sp+4h] [bp-BCh]
  int v22; // [sp+8h] [bp-B8h] BYREF
  char v23; // [sp+Ch] [bp-B4h]
  char v24; // [sp+Dh] [bp-B3h]
  int v25; // [sp+10h] [bp-B0h]
  int v26; // [sp+14h] [bp-ACh]
  int v27; // [sp+18h] [bp-A8h]
  int v28; // [sp+1Ch] [bp-A4h]

  v3 = 1;
  v4 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v21 = v5;
  v6 = a3;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a3 == 24 )
    a3 = 1;
  v8 = *(_DWORD *)(v7 + 116);
  v9 = MmProtectToPteMask[a3] & 0x3CD;
  LOWORD(v10) = v9 | 0xF832;
  if ( v6 == 24 )
  {
    LOWORD(v10) = v10 & 0xFFDF;
  }
  else if ( v6 == 4 )
  {
    LOWORD(v10) = v10 & 0xFDFF;
  }
  v26 = 0;
  v22 = 1;
  v23 = 0;
  v24 = 0;
  v27 = 0;
  v25 = 33;
  v28 = 0;
  v11 = *(_DWORD **)(v8 + 328);
  if ( !*v11 )
    return 1;
  --*(_WORD *)(v7 + 310);
  ExAcquireAutoExpandPushLockExclusive((int)(v11 + 1), 0, v9);
  v12 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 2) != 0 && (v12 & 0x20) != 0 )
  {
    if ( (v12 & 0x80) != 0 )
      v3 = 4;
    else
      v3 = 2;
  }
  if ( v4 <= v5 )
  {
    v13 = v4 + 1070596096;
    do
    {
      if ( (*(_DWORD *)v4 & 2) != 0 )
      {
        v10 = *(_DWORD *)v4 & 0xFFFFF000 | v10 & 0xFFF;
        MiInsertTbFlushEntry((int)&v22, v4 << 10, 1, 0);
        if ( v13 + 3145728 > 0x3FFFFF )
        {
          *(_DWORD *)v4 = v10;
        }
        else
        {
          v14 = *(_DWORD *)v4;
          v15 = 0;
          __dmb(0xBu);
          *(_DWORD *)v4 = v10;
          if ( (v14 & 2) == 0 && (v10 & 2) != 0 )
            v15 = 1;
          if ( v13 <= 0xFFF )
          {
            v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v4 & 0xFFF)), v10);
          }
          if ( v15 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
      v4 += 4;
      v13 += 4;
    }
    while ( v4 <= v21 );
  }
  v17 = ExReleaseAutoExpandPushLockExclusive(v11 + 1, 0, 2);
  v19 = *(_WORD *)(v7 + 310) + 1;
  *(_WORD *)(v7 + 310) = v19;
  if ( !v19 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v17);
  MiFlushTbList((unsigned int)&v22, v18);
  return v3;
}
