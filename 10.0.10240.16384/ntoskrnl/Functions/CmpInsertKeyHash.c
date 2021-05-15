// CmpInsertKeyHash 
 
_DWORD *__fastcall CmpInsertKeyHash(int a1, _DWORD *a2, int a3)
{
  int v4; // r6
  unsigned int v5; // r3
  int v6; // r1

  v4 = *(_DWORD *)(a1 + 1844);
  v5 = 101027 * (*a2 ^ (*a2 >> 9));
  v6 = (v5 ^ (v5 >> 9)) & (*(_DWORD *)(a1 + 1848) - 1);
  if ( a3 )
    ++a2[3];
  return CmpAddKeyHashToEntry(a2, v4 + 12 * v6, 0);
}
