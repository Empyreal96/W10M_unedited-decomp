// MiComputeZeroClusterMaximum 
 
int __fastcall MiComputeZeroClusterMaximum(int a1, int a2)
{
  __int64 v2; // kr00_8
  __int64 v3; // kr08_8
  unsigned int v4; // r6
  unsigned int v5; // r5
  int v6; // r1
  unsigned int v8; // r3
  unsigned int v9; // r0

  v2 = *(_QWORD *)(a1 + 12);
  v3 = *(_QWORD *)(*(_DWORD *)(a1 + 4) + 8 * v2);
  v4 = ((HIDWORD(v3) + (unsigned int)(v3 & 0xFFF) + 4095) >> 12) - HIDWORD(v2);
  v5 = v3 + (HIDWORD(v2) << 12);
  if ( v4 > *(_DWORD *)(a2 + 16) - (v5 >> 12) + 1 )
    v4 = *(_DWORD *)(a2 + 16) - (v5 >> 12) + 1;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (unsigned int)dword_640580 < 0x1388 )
    v4 = 1;
  if ( (*(_BYTE *)(v6 + 604) & 0x40) != 0 )
    return sub_521BD0();
  if ( *(_BYTE *)a1 == 1 )
  {
    v8 = *(_DWORD *)(a1 + 40);
    if ( (v8 & 0x4000) != 0 )
    {
      v9 = MiGetAvailablePagesBelowPriority(MiSystemPartition, ((v8 >> 3) & 7) + 1);
      if ( v4 > v9 )
        v4 = v9;
    }
  }
  if ( !v4 )
    v4 = 1;
  if ( v4 > 1024 - ((v5 >> 12) & 0x3FF) )
    v4 = 1024 - ((v5 >> 12) & 0x3FF);
  return v4;
}
