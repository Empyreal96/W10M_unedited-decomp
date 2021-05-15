// PsGetThreadProcessId 
 
int __fastcall PsGetThreadProcessId(int a1)
{
  return *(_DWORD *)(a1 + 876);
}
