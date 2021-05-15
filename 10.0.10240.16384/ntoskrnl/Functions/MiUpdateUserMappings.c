// MiUpdateUserMappings 
 
unsigned int MiUpdateUserMappings()
{
  unsigned int v0; // r4
  int v1; // r1
  unsigned int v2; // r5
  unsigned int result; // r0
  int v4; // r2
  unsigned int v5; // r1
  int v6; // r6

  v0 = 0;
  v1 = 2;
  v2 = MmHighestUserAddress;
  result = 0x40000000;
  do
  {
    v0 = ((v0 >> 10) & 0x3FFFFC) - 0x40000000;
    v2 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
    --v1;
  }
  while ( v1 );
  for ( ; v0 <= v2; v0 += 4 )
  {
    v4 = *(_DWORD *)v0;
    if ( (*(_DWORD *)v0 & 2) != 0 )
    {
      v5 = v4 & 0xFFFFFFFC | 0x400;
      if ( v0 + 0x40000000 <= 0x3FFFFF )
      {
        __dmb(0xBu);
        *(_DWORD *)v0 = v5;
        if ( v0 + 1070596096 <= 0xFFF )
          result = MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v5, v0);
        continue;
      }
    }
    else
    {
      if ( (v4 & 0x400) == 0 )
        continue;
      result = v0 + 1070596096;
      v5 = v4 & 0xFFFFFBFF | 2;
      if ( v0 + 0x40000000 <= 0x3FFFFF )
      {
        v6 = 0;
        __dmb(0xBu);
        if ( (v4 & 2) == 0 )
          v6 = 1;
        *(_DWORD *)v0 = v5;
        if ( result <= 0xFFF )
          result = MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v5, v0);
        if ( v6 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
        continue;
      }
    }
    *(_DWORD *)v0 = v5;
  }
  return result;
}
