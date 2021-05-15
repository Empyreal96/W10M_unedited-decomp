// MiCopyKstack 
 
int __fastcall MiCopyKstack(int a1, int a2, int a3)
{
  int v4; // r4
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r1
  int v8; // r4
  int result; // r0
  int v10; // r0

  v4 = (a1 - MmPfnDatabase) / 24;
  v5 = *(_DWORD *)(a2 + 4) | 0x80000000;
  v6 = memmove(a3 << 10, v5 << 10, 0x1000u);
  v7 = *(_DWORD *)v5;
  v8 = *(_DWORD *)v5 & 0xFFF | (v4 << 12);
  if ( v5 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v5 = v8;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v5 = v8;
    if ( (v7 & 2) == 0 )
      return sub_514338(v6);
    if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
    {
      v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v10, v10 + 4 * (v5 & 0xFFF), v8);
    }
  }
  result = v5 << 10;
  *(_BYTE *)(a2 + 18) = *(_BYTE *)(a2 + 18) & 0xF8 | 5;
  *(_DWORD *)(a2 + 20) &= 0xF8FFFFFF;
  return result;
}
