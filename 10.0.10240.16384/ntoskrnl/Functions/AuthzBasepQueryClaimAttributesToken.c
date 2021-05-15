// AuthzBasepQueryClaimAttributesToken 
 
int __fastcall AuthzBasepQueryClaimAttributesToken(_DWORD *a1, _DWORD *a2, unsigned int a3, _DWORD *a4)
{
  int result; // r0

  *a4 = 0;
  if ( *a1 )
    return sub_7EAC3C();
  if ( a3 < 0xC )
  {
    result = -1073741789;
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
    *(_WORD *)a2 = 1;
    result = 0;
  }
  *a4 = 12;
  return result;
}
