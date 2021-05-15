// MiUnlockVa 
 
int __fastcall MiUnlockVa(int a1, unsigned int a2)
{
  int v4; // r6
  int v5; // r5
  int v6; // r4

  v4 = 3 * (*(_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v5 = MmPfnDatabase;
  v6 = MiLocateWsle(a2, a1, *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12)));
  MiUpdateWorkingSetAgeDistribution(a1, (*(_DWORD *)(MEMORY[0xC0402024] * v6 - 1069537344) >> 9) & 7, 1);
  MiRemoveLockedPageFromWorkingSet(a1, a2, v6, v5 + 8 * v4);
  return MiInsertWsle(-1069539328, MEMORY[0xC0402024] * MEMORY[0xC0402004] - 1069537344, 0);
}
