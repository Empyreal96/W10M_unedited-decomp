// MiInitializeDynamicBitmap 
 
int __fastcall MiInitializeDynamicBitmap(unsigned int *a1, unsigned int a2, unsigned int a3, char a4)
{
  int *v4; // r6
  unsigned int v5; // r5
  unsigned int v7; // r10
  unsigned int v8; // r9
  int v10; // r4
  int v11; // r4
  unsigned int v12; // r7
  int v13; // r3
  int v14; // r10
  int result; // r0
  unsigned int v16; // [sp+0h] [bp-28h]

  v4 = (int *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000);
  v5 = (a3 >> 15) + ((((a3 >> 3) & 0xFFF) + 4095) >> 12);
  v7 = a3;
  v16 = a2;
  v8 = a2;
  if ( (a4 & 2) != 0 )
    goto LABEL_2;
  if ( (a4 & 4) != 0 )
    return sub_80FA74();
  if ( !MiMakeZeroedPageTables((unsigned int)v4, (int)&v4[v5 - 1], 1) )
    return 0;
LABEL_2:
  if ( (a4 & 8) != 0 )
    v10 = dword_634900;
  else
    v10 = dword_6348F4;
  v11 = dword_681114 & 0xFEC | (v10 << 12) | MiDetermineUserGlobalPteMask((unsigned int)v4) | 0x13;
  if ( (a4 & 1) != 0 )
    v11 &= 0xFFFFF7FF;
  if ( v5 )
  {
    v12 = (unsigned int)(v4 + 0x10000000);
    do
    {
      if ( v12 > 0x3FFFFF )
      {
        *v4 = v11;
      }
      else
      {
        v13 = *v4;
        v14 = 0;
        __dmb(0xBu);
        *v4 = v11;
        if ( (v13 & 2) == 0 )
          v14 = 1;
        if ( (unsigned int)v4 >= 0xC0300000 && (unsigned int)v4 <= 0xC0300FFF )
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v11, (__int16)v4);
        if ( v14 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      ++v4;
      v12 += 4;
      --v5;
    }
    while ( v5 );
    v8 = v16;
    v7 = a3;
  }
  result = 1;
  *a1 = v7;
  a1[1] = v8;
  return result;
}
