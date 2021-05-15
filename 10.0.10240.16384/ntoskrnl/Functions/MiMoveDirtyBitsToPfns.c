// MiMoveDirtyBitsToPfns 
 
unsigned int __fastcall MiMoveDirtyBitsToPfns(unsigned int a1, unsigned int a2)
{
  int v3; // r1
  unsigned int v4; // r4
  unsigned int v5; // lr
  int v6; // r0
  int v7; // r2
  unsigned int v9; // r1
  int v10; // r6
  int v11; // r7
  int v12; // r2
  int v13; // r0
  _DWORD v14[3]; // [sp+8h] [bp-D0h]
  int v15; // [sp+14h] [bp-C4h]
  unsigned int v16; // [sp+18h] [bp-C0h]
  int v17; // [sp+20h] [bp-B8h] BYREF
  char v18; // [sp+24h] [bp-B4h]
  char v19; // [sp+25h] [bp-B3h]
  int v20; // [sp+28h] [bp-B0h]
  int v21; // [sp+2Ch] [bp-ACh]
  int v22; // [sp+30h] [bp-A8h]
  int v23; // [sp+34h] [bp-A4h]

  v18 = 0;
  v17 = 1;
  v3 = 33;
  v4 = a1;
  v20 = 33;
  v21 = 0;
  v19 = 0;
  v22 = 0;
  v23 = 0;
  if ( a1 <= a2 )
  {
    v3 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
    v5 = 0x3FFFFF;
    v15 = v3;
    v16 = 0x3FFFFF;
    do
    {
      v6 = 0;
      v14[0] = ((v4 >> 10) & 0x3FFFFC) - 0x40000000;
      v14[1] = v3;
      v7 = 0;
      do
      {
        v3 = v14[2 * v7];
        if ( !*(_DWORD *)v3 || (*(_DWORD *)v3 & 2) == 0 )
          return sub_52734C(v6);
        if ( (v6 & 1) != 0 )
          v6 &= 0xFFFFFFFE;
        ++v7;
      }
      while ( !v7 );
      if ( (v6 & 2) != 0 || (*(_DWORD *)v3 & 0x400) != 0 )
        v4 = v3 << 10;
      if ( !v4 )
        break;
      v9 = *(_DWORD *)v4;
      if ( (*(_DWORD *)v4 & 2) != 0 && (v9 & 0x200) == 0 )
      {
        v10 = 3 * (v9 >> 12);
        v11 = MmPfnDatabase;
        v12 = v9 | 0x200;
        if ( v4 + 0x40000000 > v5 )
        {
          *(_DWORD *)v4 = v12;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v4 = v12;
          if ( v4 >= 0xC0300000 && v4 <= 0xC0300FFF )
          {
            v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v13, (_DWORD *)(v13 + 4 * (v4 & 0xFFF)), v12);
          }
        }
        MiInsertTbFlushEntry((int)&v17, v4 << 10, 1, 0);
        MiLockPageAndSetDirty(v11 + 8 * v10, 1);
        v5 = v16;
      }
      v4 += 4;
      v3 = v15;
    }
    while ( v4 <= a2 );
  }
  return MiFlushTbList((unsigned int)&v17, v3);
}
