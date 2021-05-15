// MmAllocateMappingAddress 
 
unsigned int __fastcall MmAllocateMappingAddress(int a1, int a2)
{
  int v2; // r7
  unsigned int v3; // r6
  unsigned int *v4; // r0
  unsigned int *v5; // r4
  unsigned int v6; // r1
  unsigned int *v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r4
  unsigned int v10; // r5
  unsigned int v11; // r8
  unsigned int v12; // r6
  unsigned int v13; // r9
  _DWORD v16[16]; // [sp+Ch] [bp-40h] BYREF

  v2 = a2;
  if ( !((unsigned int)(a1 + 4095) >> 12) )
    sub_8147DC();
  if ( !a2 )
    return 0;
  v3 = ((unsigned int)(a1 + 4095) >> 12) + 2;
  v4 = (unsigned int *)MiReservePtes(&dword_634D58, v3);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = v3 << 12;
  if ( (unsigned int)(v4 + 0x10000000) > 0x3FFFFF )
  {
    *v4 = v6;
  }
  else
  {
    __dmb(0xBu);
    *v4 = v6;
    if ( (unsigned int)v4 >= 0xC0300000 && (unsigned int)v4 <= 0xC0300FFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v6, (__int16)v4);
  }
  v7 = v5 + 1;
  v8 = v2 & 0xFFFFF01C;
  if ( (unsigned int)(v7 + 0x10000000) > 0x3FFFFF )
  {
    *v7 = v8;
  }
  else
  {
    __dmb(0xBu);
    *v7 = v8;
    if ( (unsigned int)v7 >= 0xC0300000 && (unsigned int)v7 <= 0xC0300FFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v8, (__int16)v7);
  }
  v9 = (unsigned int)(v7 + 1);
  v10 = v9 << 10;
  v11 = v3 - 2;
  if ( v3 != 2 )
  {
    v12 = v9 + 0x40000000;
    v13 = v11;
    do
    {
      if ( v12 > 0x3FFFFF )
      {
        *(_DWORD *)v9 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v9 = 0;
        if ( v9 >= 0xC0300000 && v9 <= 0xC0300FFF )
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, v9);
      }
      v9 += 4;
      v12 += 4;
      --v13;
    }
    while ( v13 );
    v2 = a2;
  }
  if ( (dword_681258 & 1) != 0 )
  {
    v16[6] = 0;
    v16[4] = v2;
    v16[5] = v11 << 12;
    v16[7] = 0;
    v16[3] = v10;
    MiInsertPteTracker(v16, 2, 0, 1);
  }
  return v10;
}
