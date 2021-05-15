// MiValidVirtualizationFault 
 
int __fastcall MiValidVirtualizationFault(int result, int *a2)
{
  int v2; // r2
  int v3; // r5
  int v4; // r3
  int v5; // r6
  int v6; // r0

  v2 = *a2;
  *(_DWORD *)(result + 20) = (unsigned int)*a2 >> 12;
  if ( (v2 & 0x10) == 0 )
  {
    v3 = v2 | 0x10;
    if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
    {
      *a2 = v3;
    }
    else
    {
      v4 = *a2;
      v5 = 0;
      __dmb(0xBu);
      *a2 = v3;
      if ( (v4 & 2) == 0 && (v3 & 2) != 0 )
        v5 = 1;
      if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
      {
        v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v6, (_DWORD *)(v6 + 4 * ((unsigned __int16)a2 & 0xFFF)), v3);
      }
      if ( v5 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  return result;
}
