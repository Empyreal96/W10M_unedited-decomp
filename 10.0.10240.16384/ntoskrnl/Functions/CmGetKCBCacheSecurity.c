// CmGetKCBCacheSecurity 
 
int __fastcall CmGetKCBCacheSecurity(int a1, int a2)
{
  int result; // r0

  if ( a2 )
    result = sub_805770();
  else
    result = *(_DWORD *)(a1 + 48);
  return result;
}
