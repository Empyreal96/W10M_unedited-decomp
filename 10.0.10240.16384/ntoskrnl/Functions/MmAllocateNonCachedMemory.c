// MmAllocateNonCachedMemory 
 
int __fastcall MmAllocateNonCachedMemory(unsigned int a1)
{
  unsigned int v1; // r9
  int v2; // r5
  int v3; // r6
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int *v8; // r4
  int *v9; // r10
  unsigned int v10; // r7
  int v11; // t1
  int v12; // r3
  int v13; // r8

  v1 = ((a1 & 0xFFF) != 0) + (a1 >> 12);
  v2 = MiAllocatePagesForMdl(
         MiSystemPartition,
         0i64,
         -1i64,
         0i64,
         a1,
         0,
         *(_WORD *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C)) + 590)
                  + 266),
         4);
  if ( !v2 )
    return 0;
  v4 = MiReservePtes(&dword_634D58, v1);
  v8 = (int *)v4;
  if ( !v4 )
  {
    MmFreePagesFromMdl(v2, v5, v6, v7);
    ExFreePoolWithTag(v2);
    return 0;
  }
  v9 = (int *)(v2 + 28);
  v3 = v4 << 10;
  *(_DWORD *)(MmPfnDatabase + 24 * *(_DWORD *)(v2 + 28) + 8) = v2;
  LOWORD(v2) = (MiDetermineUserGlobalPteMask(v4) | dword_681140) & 0x1ED | 0xF012;
  v10 = (unsigned int)(v8 + 267649024);
  do
  {
    v11 = *v9++;
    v2 = v2 & 0xFFF | (v11 << 12);
    if ( v10 + 3145728 > 0x3FFFFF )
    {
      *v8 = v2;
    }
    else
    {
      v12 = *v8;
      v13 = 0;
      __dmb(0xBu);
      *v8 = v2;
      if ( (v12 & 2) == 0 && (v2 & 2) != 0 )
        v13 = 1;
      if ( v10 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v2, (__int16)v8);
      if ( v13 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    ++v8;
    v10 += 4;
    --v1;
  }
  while ( v1 );
  return v3;
}
