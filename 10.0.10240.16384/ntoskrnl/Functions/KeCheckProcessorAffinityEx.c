// KeCheckProcessorAffinityEx 
 
int __fastcall KeCheckProcessorAffinityEx(int a1, char a2)
{
  return (*(_DWORD *)(a1 + 8) >> a2) & 1;
}
