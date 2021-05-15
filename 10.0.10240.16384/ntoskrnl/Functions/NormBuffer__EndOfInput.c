// NormBuffer__EndOfInput 
 
BOOL __fastcall NormBuffer__EndOfInput(int a1)
{
  return *(_DWORD *)(a1 + 8) == *(_DWORD *)(a1 + 4);
}
