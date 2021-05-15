// KeComplementAffinityEx 
 
int __fastcall KeComplementAffinityEx(int result, int a2)
{
  *(_WORD *)(result + 2) = 1;
  *(_WORD *)result = 1;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = ~*(_DWORD *)(a2 + 8);
  return result;
}
