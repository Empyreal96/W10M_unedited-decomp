// MiRemoveLockedPageFromWorkingSet 
 
int __fastcall MiRemoveLockedPageFromWorkingSet(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r5
  int v6; // r9
  int result; // r0
  int v10; // r3
  unsigned int v11; // r6

  v5 = a2;
  v6 = *(_DWORD *)(a1 + 92);
  if ( (*(_DWORD *)(a4 + 20) & 0x8000000) != 0 && (*(_DWORD *)(a4 + 8) & 0x400) != 0 && (*(_BYTE *)(a1 + 112) & 7) == 0 )
  {
    MiReturnCommit(MiSystemPartition, 1);
    do
      v11 = __ldrex(dword_640720);
    while ( __strex(v11 - 1, dword_640720) );
    v5 = a2;
  }
  result = *(_DWORD *)(v6 + 4) - 1;
  if ( a3 != result )
    result = MiSwapWslEntries(result, a3, a1);
  --*(_DWORD *)(v6 + 4);
  if ( v5 < dword_63389C )
  {
    v10 = *(_DWORD *)(a4 + 20);
    if ( (v10 & 0x8000000) != 0 )
      MiUnlockPageTableCharges(MmPfnDatabase + 24 * (v10 & 0xFFFFF), 2, 0);
    result = MiUnlockPageTableCharges(MmPfnDatabase + 24 * (*(_DWORD *)(((v5 >> 20) & 0xFFC) - 1070596096) >> 12), 2, 1);
  }
  return result;
}
