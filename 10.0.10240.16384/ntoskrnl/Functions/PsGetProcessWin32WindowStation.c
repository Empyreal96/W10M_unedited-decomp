// PsGetProcessWin32WindowStation 
 
int __fastcall PsGetProcessWin32WindowStation(int a1)
{
  return *(_DWORD *)(a1 + 308);
}
