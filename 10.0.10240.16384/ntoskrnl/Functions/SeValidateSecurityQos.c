// SeValidateSecurityQos 
 
int __fastcall SeValidateSecurityQos(int a1)
{
  int v1; // r3
  int result; // r0

  if ( *(_BYTE *)(a1 + 8) != 1 && *(_BYTE *)(a1 + 8) )
    return -1073741811;
  v1 = *(_DWORD *)(a1 + 4);
  if ( v1 < 0 || v1 > 3 )
    result = -1073741659;
  else
    result = 0;
  return result;
}
