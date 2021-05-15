// KeIsEqualAffinityEx 
 
BOOL __fastcall KeIsEqualAffinityEx(int a1, int a2)
{
  return *(_DWORD *)(a1 + 8) == *(_DWORD *)(a2 + 8);
}
