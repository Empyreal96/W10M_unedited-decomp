// MiAssignNonPagedPoolPtes 
 
int __fastcall MiAssignNonPagedPoolPtes(unsigned int a1, unsigned int a2, __int16 a3, int a4)
{
  unsigned int v4; // r9
  unsigned int v5; // r4
  int v7; // r6
  unsigned int v8; // r6
  int result; // r0
  unsigned int v10; // r8
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r9
  int v15; // r7
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  int v18; // r3
  unsigned int *v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r5
  int v23; // r0
  int v24; // r0
  unsigned int v25; // [sp+Ch] [bp-2Ch]

  v4 = a2;
  v5 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( (a3 & 0x200) != 0 )
    v7 = 4;
  else
    v7 = 6;
  v8 = (MiDetermineUserGlobalPteMask(((a1 >> 10) & 0x3FFFFC) - 0x40000000) | MmProtectToPteMask[v7]) & 0x1ED | 0xFFFFF012;
  result = 0;
  if ( v4 )
  {
    do
    {
      v10 = (4096 - (v5 & 0xFFF)) >> 2;
      if ( v10 > v4 - result )
        v10 = v4 - result;
      v25 = result + v10;
      do
      {
        v8 = v8 & 0xFFF | (((a4 - MmPfnDatabase) / 24) << 12);
        if ( (*(_BYTE *)(a4 + 19) & 0x10) == 0 )
        {
          *(_DWORD *)(a4 + 8) = 128;
          v11 = *(_DWORD *)(a4 + 20);
          *(_WORD *)(a4 + 16) = 1;
          *(_DWORD *)(a4 + 20) = v11 & 0xF7FFFFFF;
        }
        v12 = *(_DWORD *)(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
        v13 = *(_DWORD *)(a4 + 20);
        v14 = *(_DWORD *)a4;
        *(_DWORD *)a4 = 0;
        *(_DWORD *)(a4 + 20) = v13 & 0xFFF00000 | (v12 >> 12);
        v15 = KfRaiseIrql(2);
        v16 = (unsigned __int8 *)(a4 + 15);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 | 0x80, v16) );
        __dmb(0xBu);
        if ( v17 >> 7 )
          return sub_51DCA4();
        if ( (*(_DWORD *)(a4 + 20) & 0xFFFFF) == 1048574 )
          *(_DWORD *)(a4 + 20) &= 0xFFF00000;
        if ( (*(_BYTE *)(a4 + 18) & 0xC0) != 64 )
          MiChangePageAttribute(a4, 1, 1);
        v18 = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(a4 + 4) = v5;
        *(_DWORD *)(a4 + 12) = v18 & 0xC0000000 | 1;
        *(_WORD *)(a4 + 16) = 1;
        *(_BYTE *)(a4 + 18) = *(_BYTE *)(a4 + 18) & 0xF8 | 6;
        __dmb(0xBu);
        v19 = (unsigned int *)(a4 + 12);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 & 0x7FFFFFFF, v19) );
        KfLowerIrql(v15);
        if ( v5 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v5 = v8;
        }
        else
        {
          v21 = *(_DWORD *)v5;
          v22 = 0;
          __dmb(0xBu);
          *(_DWORD *)v5 = v8;
          if ( (v21 & 2) == 0 && (v8 & 2) != 0 )
            v22 = 1;
          if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
          {
            v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v23, v23 + 4 * (v5 & 0xFFF), v8);
          }
          if ( v22 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        v5 += 4;
        --v10;
        a4 = v14;
      }
      while ( v10 );
      result = v25;
      v4 = a2;
    }
    while ( v25 < a2 );
  }
  if ( (dword_682604 & 1) != 0 )
  {
    v24 = MiInitPerfMemoryFlags(1, 5);
    result = MiLogPerfMemoryRangeEvent(a1, 0, v24, v4);
  }
  return result;
}
