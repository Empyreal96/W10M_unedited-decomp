// MiCreatePfnDatabase 
 
int __fastcall MiCreatePfnDatabase(int a1)
{
  int v2; // r4
  int v3; // r1
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3

  MiInitializeColors();
  v2 = (unsigned __int16)KeNumberNodes * dword_633818;
  dword_633818 = v2;
  v3 = dword_633850;
  if ( dword_634690 == -1 )
  {
    dword_634690 = dword_633850 + 1;
    v3 = dword_633850 + 2048;
  }
  dword_63FB00 = 24 * (v3 + 1);
  dword_63FB04 = dword_63FB00 + 20 * v2;
  dword_63FB08 = (dword_63FB04 + 20 * v2 + 7) & 0xFFFFFFF8;
  dword_63FB0C = dword_63FB08 + 8 * v2;
  v4 = dword_63FB0C + 8 * v2;
  dword_6337E8 = (v4 + 104 * (unsigned __int16)KeNumberNodes + 7) & 0xFFFFFFF8;
  dword_6337E4 = dword_6337E8 + 176 * (unsigned __int16)KeNumberNodes;
  dword_634808 = (dword_6337E4 + 2 * (unsigned __int16)KeNumberNodes * (unsigned __int16)KeNumberNodes + 7) & 0xFFFFFFF8;
  v5 = (dword_634808 + 72 * (unsigned __int16)KeNumberNodes + 4095) & 0xFFFFF000;
  MxPfnAllocation = v5 >> 12;
  MmPfnDatabase = MiObtainSystemVa((v5 + 0x3FFFFF) >> 22, 4);
  dword_63FB00 += MmPfnDatabase;
  dword_63FB04 += MmPfnDatabase;
  dword_63FB08 += MmPfnDatabase;
  dword_63FB0C += MmPfnDatabase;
  dword_6337E8 += MmPfnDatabase;
  dword_6337E4 += MmPfnDatabase;
  dword_634808 += MmPfnDatabase;
  dword_63F718 = MmPfnDatabase + v4;
  if ( !MiCreateSparsePfnDatabase(a1) )
    return 0;
  MiInitializePartitions(0);
  MiInitializePartition();
  MiInsertNewPartitionInList(v6, v7, v8, v9);
  MiInitializeNumaGraph(a1);
  return 1;
}
