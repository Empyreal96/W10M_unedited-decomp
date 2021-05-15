// MmSetPageProtection 
 
int __fastcall MmSetPageProtection(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v4; // r0
  unsigned int v5; // r1
  char v6; // r6
  unsigned int v8; // r5
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r1
  unsigned int v12; // r7
  int v13; // r6
  unsigned int v14; // r0
  int v15; // r9
  int v16; // r8
  int v17; // r3
  int v18; // r6
  int v19; // r0
  int v20; // [sp+0h] [bp-C0h]
  int v21; // [sp+4h] [bp-BCh]
  int v22; // [sp+8h] [bp-B8h] BYREF
  char v23; // [sp+Ch] [bp-B4h]
  char v24; // [sp+Dh] [bp-B3h]
  int v25; // [sp+10h] [bp-B0h]
  int v26; // [sp+14h] [bp-ACh]
  int v27; // [sp+18h] [bp-A8h]
  int v28; // [sp+1Ch] [bp-A4h]

  if ( (*(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026
    || (v4 = MiMakeProtectionMask(a3), v6 = v4, v4 == -1)
    || v4 >= 8
    || (v4 & 5) == 5 )
  {
    JUMPOUT(0x519DB0);
  }
  if ( (v4 & 2) != 0 )
    return sub_519DA4();
  v8 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = ((v5 & 0xFFF) != 0) + (v5 >> 12);
  v20 = v9;
  v10 = (MmProtectToPteMask[v4] | MiDetermineUserGlobalPteMask(v8)) & 0x3ED | 0xFFFFF012;
  v21 = v6 & 4;
  if ( (v6 & 4) != 0 )
    LOWORD(v10) = v10 & 0xFDFF;
  v26 = 0;
  v27 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 33;
  v28 = 0;
  MiInsertTbFlushEntry((int)&v22, a1, v9, 0);
  if ( v9 )
  {
    v12 = (a1 >> 10) & 0x3FFFFC;
    do
    {
      v13 = *(_DWORD *)v8;
      v14 = *(_DWORD *)v8 >> 12;
      v15 = MmPfnDatabase;
      v10 = v10 & 0xFFF | (v14 << 12);
      v16 = 3 * v14;
      if ( v21 )
      {
        if ( (v13 & 0x200) == 0 )
          v10 &= 0xFFFFFDFF;
      }
      else if ( MI_IS_PFN(v14) )
      {
        MiLockPageAndSetDirty(v15 + 8 * v16, 0);
      }
      if ( (v13 & 0x10) != 0 )
        v10 |= 0x10u;
      if ( v12 > 0x3FFFFF )
      {
        *(_DWORD *)v8 = v10;
      }
      else
      {
        v17 = *(_DWORD *)v8;
        v18 = 0;
        __dmb(0xBu);
        *(_DWORD *)v8 = v10;
        if ( (v17 & 2) == 0 && (v10 & 2) != 0 )
          v18 = 1;
        if ( v8 >= 0xC0300000 && v8 <= 0xC0300FFF )
        {
          v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * (v8 & 0xFFF)), v10);
        }
        if ( v18 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v8 += 4;
      v12 += 4;
      --v20;
    }
    while ( v20 );
  }
  MiFlushTbList((unsigned int)&v22, v11);
  return 1;
}
