// MmPageEntireDriver 
 
unsigned int __fastcall MmPageEntireDriver(unsigned int a1)
{
  int *v2; // r0
  int v3; // r7
  unsigned int v4; // r6
  int v5; // r0
  int v6; // r1
  int v7; // r0
  int v8; // r1
  int v9; // r4

  if ( (*(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return 0;
  v2 = MiLookupDataTableEntry(a1, 0);
  v3 = (int)v2;
  if ( !v2 )
    return 0;
  v4 = v2[6];
  if ( (dword_681250 & 1) == 0 )
  {
    if ( a1 < dword_63389C
      || (v5 = MiGetSystemRegionIndex(a1), *(_BYTE *)(v5 + v6 + 9692) != 1)
      && (v7 = MiGetSystemRegionIndex(a1), *(_BYTE *)(v7 + v8 + 9692) != 11) )
    {
      KeFlushQueuedDpcs();
      v9 = ((v4 >> 10) & 0x3FFFFC) - 0x40000000 + 4 * (*(_DWORD *)(v3 + 32) >> 12);
      MiCancelPhase0Locking(v3);
      MiSetPagingOfDriver(v3, ((v4 >> 10) & 0x3FFFFC) - 0x40000000, v9 - 4);
    }
  }
  return v4;
}
