// CmpInsertKeyHashToDeletedKcbTable 
 
int __fastcall CmpInsertKeyHashToDeletedKcbTable(int a1, _DWORD *a2)
{
  unsigned int v2; // r3

  v2 = 101027 * (*a2 ^ (*a2 >> 9));
  return CmpAddKeyHashToEntry(a2, *(_DWORD *)(a1 + 1852) + 12 * ((*(_DWORD *)(a1 + 1856) - 1) & (v2 ^ (v2 >> 9))), 1);
}
