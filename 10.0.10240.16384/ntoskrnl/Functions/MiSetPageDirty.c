// MiSetPageDirty 
 
int __fastcall MiSetPageDirty(int *a1, int a2)
{
  int result; // r0
  int v5; // r5
  int v6; // r2
  int v7; // r0

  result = *a1;
  if ( (result & 0x200) == 0 )
  {
    v5 = result | 0x10;
    if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
    {
      *a1 = v5;
    }
    else
    {
      __dmb(0xBu);
      *a1 = v5;
      if ( (result & 2) == 0 )
        return sub_5210B8();
      if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
      {
        v6 = result | 0x10;
        v7 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v7, v7 + 4 * ((unsigned __int16)a1 & 0xFFF), v6);
      }
    }
    if ( (MiFlags & 0x300) == 0 )
      result = KeFlushSingleCurrentTb(a2);
  }
  return result;
}
