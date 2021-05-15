// ViDeadlockSimilarNode 
 
BOOL __fastcall ViDeadlockSimilarNode(int a1, int a2, int a3)
{
  return a1 == *(_DWORD *)(*(_DWORD *)(a3 + 28) + 8) && a2 == ((*(_DWORD *)(a3 + 36) >> 1) & 1);
}
