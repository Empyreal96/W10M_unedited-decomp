// MmInvalidateDumpAddresses 
 
unsigned int __fastcall MmInvalidateDumpAddresses(unsigned int result, int a2)
{
  _DWORD *v2; // r4
  int v4; // r1
  int v5; // r7
  int v6; // r2
  unsigned int v7; // r6
  int v8; // r8
  unsigned int v9; // r3
  int v10; // r6
  _DWORD *v11; // r4
  unsigned int v12; // r5

  v2 = (_DWORD *)(((result >> 10) & 0x3FFFFC) - 0x40000000);
  v4 = 0;
  v5 = result;
  v6 = 4095;
  if ( a2 )
  {
    v7 = ((result >> 10) & 0x3FFFFC) - 3145728;
    v8 = a2;
    do
    {
      v9 = v7 + 3145728;
      if ( v7 + 3145728 > 0x3FFFFF )
      {
        *v2 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v2 = 0;
        if ( v7 <= 0xFFF )
        {
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v2);
          v6 = 4095;
          v4 = 0;
        }
      }
      ++v2;
      v7 += 4;
      --v8;
    }
    while ( v8 );
    do
    {
      result = KeFlushSingleCurrentTb(v5, v4, v6, v9);
      v5 += 4096;
      --a2;
    }
    while ( a2 );
  }
  v10 = 32;
  v11 = (_DWORD *)dword_634390;
  v12 = dword_634390 + 1070596096;
  do
  {
    if ( v12 + 3145728 > 0x3FFFFF )
    {
      *v11 = 0;
    }
    else
    {
      __dmb(0xBu);
      *v11 = 0;
      if ( v12 <= 0xFFF )
        result = MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v11);
    }
    ++v11;
    v12 += 4;
    --v10;
  }
  while ( v10 );
  return result;
}
