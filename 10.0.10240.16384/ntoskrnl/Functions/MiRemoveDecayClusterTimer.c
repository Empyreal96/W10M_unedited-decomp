// MiRemoveDecayClusterTimer 
 
unsigned int __fastcall MiRemoveDecayClusterTimer(int a1)
{
  unsigned int v1; // r3
  unsigned int result; // r0
  int v3; // r2
  unsigned int v4; // r4
  unsigned int v5; // r7

  v1 = *(unsigned __int8 *)(a1 + 18);
  result = *(_DWORD *)(a1 + 4);
  v3 = (unsigned __int16)result >> 1;
  v4 = v1 >> 6;
  v5 = result >> 17;
  if ( v3 == 0x7FFF )
    *(_DWORD *)&MiSystemPartition[2 * v4 + 1386] = result & 0xFFFE0000 | *(_DWORD *)&MiSystemPartition[2 * v4 + 1386] & 0x1FFFF;
  else
    *(_DWORD *)(MmPfnDatabase + 24 * (dword_634690 + v3) + 4) = result & 0xFFFE0000 | *(_DWORD *)(MmPfnDatabase
                                                                                                + 24
                                                                                                * (dword_634690 + v3)
                                                                                                + 4) & 0x1FFFF;
  if ( v5 == 0x7FFF )
    *(_DWORD *)&MiSystemPartition[2 * v4 + 1386] ^= (*(_DWORD *)&MiSystemPartition[2 * v4 + 1386] ^ result) & 0xFFFE;
  else
    *(_DWORD *)(MmPfnDatabase + 24 * (dword_634690 + v5) + 4) ^= (*(_DWORD *)(MmPfnDatabase
                                                                            + 24 * (dword_634690 + v5)
                                                                            + 4) ^ result) & 0xFFFE;
  return result;
}
