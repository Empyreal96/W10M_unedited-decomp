// MmMarkPhysicalMemoryAsGood 
 
int __fastcall MmMarkPhysicalMemoryAsGood(__int64 *a1, int a2)
{
  unsigned int v3; // r0
  int v4; // r3
  unsigned int v6; // r5
  unsigned int v7; // r4

  v3 = *a1 >> 12;
  v4 = *(__int64 *)a2 >> 12;
  if ( v3 >= v4 + v3 )
    return -1073741585;
  v6 = MiMoveEccPagesToFreeList(v3, v4 + v3);
  MiReturnResidentAvailable(v6);
  do
    v7 = __ldrex(&dword_634A2C[59]);
  while ( __strex(v7 + v6, &dword_634A2C[59]) );
  MiReturnCommit((int)MiSystemPartition, v6);
  *(_DWORD *)a2 = v6 << 12;
  *(_DWORD *)(a2 + 4) = v6 >> 20;
  return 0;
}
