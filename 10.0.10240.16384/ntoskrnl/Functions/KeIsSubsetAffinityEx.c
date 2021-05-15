// KeIsSubsetAffinityEx 
 
BOOL __fastcall KeIsSubsetAffinityEx(int a1, int a2)
{
  return (*(_DWORD *)(a2 + 8) & *(_DWORD *)(a1 + 8)) == *(_DWORD *)(a1 + 8);
}
