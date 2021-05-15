// MiInitializeZeroPagePtes 
 
int __fastcall MiInitializeZeroPagePtes(int a1)
{
  int v1; // r5
  int v3; // r0
  _DWORD *v4; // r4
  unsigned int v5; // r6
  _DWORD *v7; // r2

  v1 = 256;
  v3 = MiReservePtes(&dword_634D58, 0x100u);
  v4 = (_DWORD *)v3;
  if ( !v3 )
    return 0;
  *(_DWORD *)(a1 + 3256) = v3;
  v5 = v3 + 0x40000000;
  do
  {
    if ( v5 > 0x3FFFFF )
    {
      *v4 = 0;
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
      if ( (unsigned int)v4 >= 0xC0300000 )
        return sub_80FB7C();
    }
    ++v4;
    v5 += 4;
    --v1;
  }
  while ( v1 );
  v7 = *(_DWORD **)(a1 + 3256);
  if ( (unsigned int)(v7 + 0x10000000) > 0x3FFFFF )
  {
    *v7 = 0x200000;
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0x200000;
    if ( (unsigned int)v7 >= 0xC0300000 && (unsigned int)v7 <= 0xC0300FFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v7);
  }
  return 1;
}
