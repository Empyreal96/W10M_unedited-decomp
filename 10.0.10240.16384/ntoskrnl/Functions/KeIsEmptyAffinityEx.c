// KeIsEmptyAffinityEx 
 
BOOL __fastcall KeIsEmptyAffinityEx(int a1)
{
  return *(_DWORD *)(a1 + 8) == 0;
}
