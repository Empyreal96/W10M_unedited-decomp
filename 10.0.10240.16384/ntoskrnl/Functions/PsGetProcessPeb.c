// PsGetProcessPeb 
 
int __fastcall PsGetProcessPeb(int a1)
{
  return *(_DWORD *)(a1 + 320);
}
