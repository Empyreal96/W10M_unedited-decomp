// MiDbgReleaseAddress 
 
unsigned int __fastcall MiDbgReleaseAddress(unsigned int result, int *a2, char a3)
{
  int v4; // r2
  int v5; // r6
  unsigned int v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r0

  v4 = *a2;
  v5 = result;
  if ( *a2 )
  {
    v6 = ((result >> 10) & 0x3FFFFC) - 0x40000000;
    do
      v7 = __ldrex((unsigned int *)algn_63458C);
    while ( __strex(v7 + 1, (unsigned int *)algn_63458C) );
    __dmb(0xBu);
    v8 = *(_DWORD *)v6;
    __dmb(0xBu);
    *(_DWORD *)v6 = v4;
    if ( (v8 & 2) != 0 )
    {
      if ( v6 >= 0xC0300000 && v6 <= 0xC0300FFF )
      {
        v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * (v6 & 0xFFF)), v4);
      }
      __dmb(0xBu);
      do
      {
        v9 = __ldrex((unsigned int *)algn_63458C);
        v10 = v9 - 1;
      }
      while ( __strex(v10, (unsigned int *)algn_63458C) );
      if ( (a3 & 4) != 0 )
        result = KeFlushSingleCurrentTb(v5, v10, (int)algn_63458C, 0);
      else
        result = KeFlushSingleTb(v5, 2);
    }
    else
    {
      result = sub_5534D0();
    }
  }
  return result;
}
