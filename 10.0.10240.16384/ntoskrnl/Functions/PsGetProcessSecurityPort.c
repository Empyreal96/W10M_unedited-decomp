// PsGetProcessSecurityPort 
 
int __fastcall PsGetProcessSecurityPort(int a1)
{
  return *(_DWORD *)(a1 + 376);
}
