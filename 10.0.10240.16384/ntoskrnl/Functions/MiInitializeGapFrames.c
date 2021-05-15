// MiInitializeGapFrames 
 
int __fastcall MiInitializeGapFrames(int a1, _DWORD *a2)
{
  unsigned int v3; // r0
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r8
  int v8; // r4
  unsigned int v9; // r4
  unsigned int v10; // r2
  int v12; // r2

  if ( MiChargeResident(MiSystemPartition, 2u, 0) )
  {
    do
      v3 = __ldrex(&dword_634A2C[22]);
    while ( __strex(v3 + 2, &dword_634A2C[22]) );
    if ( MiChargeCommit((int)MiSystemPartition, 2u, 1) )
    {
      v4 = MiReservePtes(&dword_634D58, 2u);
      if ( v4 )
      {
        v5 = 0;
        while ( 1 )
        {
          v6 = MiGetPage((int)MiSystemPartition, v5, 8);
          v7 = v6;
          if ( v6 == -1 )
            break;
          v8 = MmPfnDatabase + 24 * v6;
          *(_DWORD *)v8 = 0;
          *(_WORD *)(v8 + 16) = 1;
          *(_DWORD *)(v8 + 20) &= 0xF7FFFFFF;
          MiFinalizePageAttribute(v8, 1, 0);
          *(_DWORD *)(v8 + 12) = *(_DWORD *)(v8 + 12) & 0xC0000000 | 1;
          v9 = v4 + 4 * v5;
          v10 = (dword_681120 & 0x1ED | (v7 << 12) | MiDetermineUserGlobalPteMask(v9)) & 0xFFFFF1FF | 0x12;
          if ( v9 >= 0xC0000000 )
            return sub_96E930();
          *(_DWORD *)v9 = v10;
          if ( v5 )
            v12 = (dword_681114 & 0x3ED | (*a2 << 12) | MiDetermineUserGlobalPteMask(v4 + 4)) & 0xFFFFF3FF | 0x12;
          else
            v12 = a1;
          RtlFillMemoryUlong((_DWORD *)(v9 << 10), 0x1000u, v12);
          a2[v5++] = v7;
          if ( v5 >= 2 )
          {
            MiReleasePtes(&dword_634D58, v4, 2u);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
