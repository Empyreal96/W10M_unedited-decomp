// ViDeadlockSimilarNodes 
 
BOOL __fastcall ViDeadlockSimilarNodes(int a1, int a2)
{
  return *(_DWORD *)(a1 + 28) == *(_DWORD *)(a2 + 28) && ((*(_DWORD *)(a2 + 36) ^ *(_DWORD *)(a1 + 36)) & 2) == 0;
}
