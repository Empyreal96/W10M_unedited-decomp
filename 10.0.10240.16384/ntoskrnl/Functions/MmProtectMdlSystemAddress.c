// MmProtectMdlSystemAddress 
 
int __fastcall MmProtectMdlSystemAddress(int a1, int a2)
{
  int v2; // r8
  unsigned int v4; // r6
  unsigned int v5; // r0
  unsigned int v6; // r7
  unsigned int v7; // r3
  unsigned int v8; // r4
  unsigned int v9; // r10
  unsigned int v10; // r6
  unsigned int v11; // r5
  int v12; // r8
  unsigned int v13; // r9
  unsigned int v14; // r2
  unsigned int v15; // r3
  int v16; // r5
  int v17; // r0
  unsigned int v18; // r3
  int v19; // r0
  int v21; // [sp+18h] [bp-B8h] BYREF
  char v22; // [sp+1Ch] [bp-B4h]
  char v23; // [sp+1Dh] [bp-B3h]
  int v24; // [sp+20h] [bp-B0h]
  int v25; // [sp+24h] [bp-ACh]
  int v26; // [sp+28h] [bp-A8h]
  int v27; // [sp+2Ch] [bp-A4h]

  v2 = a1;
  if ( (*(_WORD *)(a1 + 6) & 1) == 0 )
    return sub_51F290();
  v4 = *(_DWORD *)(a1 + 12);
  if ( (*(_DWORD *)(((v4 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return -1073741637;
  v5 = MiMakeProtectionMask(a2);
  v6 = v5;
  if ( v5 == -1 )
    return -1073741755;
  v7 = v5 >> 3;
  if ( v5 >> 3 == 2 || v7 == 1 || v7 == 3 && (v5 & 7) != 0 )
    return -1073741755;
  if ( (v5 & 5) == 5 )
    return -1073741755;
  v8 = ((v4 >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = ((v4 & 0xFFF) + *(_DWORD *)(v2 + 20) + 4095) >> 12;
  v24 = 33;
  v25 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v26 = 0;
  v27 = 0;
  v10 = v4 & 0xFFFFF000;
  while ( v9 )
  {
    v11 = *(_DWORD *)v8;
    if ( (*(_DWORD *)v8 & 2) != 0 )
    {
      v12 = 1;
      v13 = v11 >> 12;
      MiInsertTbFlushEntry(&v21, v10, 1);
    }
    else
    {
      if ( (v11 & 0x800) == 0 || (*(_DWORD *)v8 & 0x3E0) != 768 )
        KeBugCheck2(26, 4661, a1, v8, v11, 0);
      v13 = v11 >> 12;
      v12 = 0;
    }
    if ( v6 == 24 )
    {
      v14 = v11 & 0xFFFFFB1C | 0xB00;
      if ( v8 + 0x40000000 <= 0x3FFFFF )
      {
        __dmb(0xBu);
        *(_DWORD *)v8 = v14;
        if ( v8 + 1070596096 <= 0xFFF )
        {
          v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v17, v17 + 4 * (v8 & 0xFFF), v14);
        }
        goto LABEL_22;
      }
    }
    else
    {
      v14 = (MmProtectToPteMask[v6] & 0x3ED | (v13 << 12) | MiDetermineUserGlobalPteMask(v8)) & 0xFFFFF3FF | 0x12;
      if ( (v6 & 4) != 0 )
        v14 &= 0xFFFFFDFF;
      if ( v12 == 1 )
      {
        v14 ^= ((unsigned __int8)v11 ^ (unsigned __int8)v14) & 0xC;
        if ( v8 + 0x40000000 <= 0x3FFFFF )
        {
          v15 = *(_DWORD *)v8;
          v16 = 0;
          __dmb(0xBu);
          *(_DWORD *)v8 = v14;
          if ( (v15 & 2) == 0 )
            v16 = 1;
          if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
            goto LABEL_41;
          goto LABEL_20;
        }
      }
      else if ( v8 + 0x40000000 <= 0x3FFFFF )
      {
        v18 = *(_DWORD *)v8;
        v16 = 0;
        __dmb(0xBu);
        *(_DWORD *)v8 = v14;
        if ( (v18 & 2) == 0 )
          v16 = 1;
        if ( v8 + 1070596096 <= 0xFFF )
        {
LABEL_41:
          v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v19, v19 + 4 * (v8 & 0xFFF), v14);
        }
LABEL_20:
        if ( v16 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
        goto LABEL_22;
      }
    }
    *(_DWORD *)v8 = v14;
LABEL_22:
    v8 += 4;
    --v9;
    v10 += 4096;
  }
  MiFlushTbList(&v21);
  return 0;
}
