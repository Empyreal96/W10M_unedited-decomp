// PsSetProcessSecurityPort 
 
int __fastcall PsSetProcessSecurityPort(int a1, int a2)
{
  *(_DWORD *)(a1 + 376) = a2;
  return 0;
}
