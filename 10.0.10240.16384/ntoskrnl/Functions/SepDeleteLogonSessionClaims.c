// SepDeleteLogonSessionClaims 
 
int __fastcall SepDeleteLogonSessionClaims(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 64);
  if ( result )
    result = sub_80A6E0();
  return result;
}
