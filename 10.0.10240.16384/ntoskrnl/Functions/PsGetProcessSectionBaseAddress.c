// PsGetProcessSectionBaseAddress 
 
int __fastcall PsGetProcessSectionBaseAddress(int a1)
{
  return *(_DWORD *)(a1 + 296);
}
