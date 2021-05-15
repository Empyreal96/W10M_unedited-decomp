// MiDemoteLargeFreePage 
 
int __fastcall MiDemoteLargeFreePage(int a1)
{
  unsigned int v1; // r4
  int v2; // r1

  v1 = a1 & 0xFFFFFC00;
  v2 = MiTryUnlinkNodeLargePage(a1 & 0xFFFFFC00);
  if ( v2 > 1 )
    return 0;
  MiInsertLargePageInFreeOrZeroList(MmPfnDatabase + 24 * v1, v2);
  return 1;
}
