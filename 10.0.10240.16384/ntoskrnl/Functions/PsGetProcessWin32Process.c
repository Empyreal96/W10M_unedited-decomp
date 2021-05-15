// PsGetProcessWin32Process 
 
int __fastcall PsGetProcessWin32Process(int a1)
{
  return *(_DWORD *)(a1 + 284);
}
