// PsGetProcessId 
 
int __fastcall PsGetProcessId(int a1)
{
  return *(_DWORD *)(a1 + 176);
}
