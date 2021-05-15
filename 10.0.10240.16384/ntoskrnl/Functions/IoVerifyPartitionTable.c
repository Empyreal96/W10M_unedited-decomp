// IoVerifyPartitionTable 
 
int __fastcall IoVerifyPartitionTable(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int *v6; // r5
  int v8; // [sp+0h] [bp-18h] BYREF
  int v9[5]; // [sp+4h] [bp-14h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = FstubAllocateDiskInformation(a1, (unsigned int *)&v8);
  if ( v5 >= 0 )
  {
    v6 = (int *)v8;
    v5 = FstubDetectPartitionStyle(v8, v9);
    if ( v5 < 0
      || (!v9[0] ? (v5 = 0) : v9[0] == 1 ? (v5 = FstubVerifyPartitionTableEFI(v6, a2)) : (v5 = -1073741637), v6) )
    {
      FstubFreeDiskInformation((unsigned int)v6);
    }
  }
  return v5;
}
