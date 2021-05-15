// SepDeleteLogonSessionSidValues 
 
int __fastcall SepDeleteLogonSessionSidValues(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 68);
  if ( result )
  {
    result = SepDereferenceSidValuesBlock(result, 0, a1);
    *(_DWORD *)(a1 + 68) = 0;
  }
  return result;
}
