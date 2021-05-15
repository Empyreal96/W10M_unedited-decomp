// CcReferenceVacbArray 
 
int __fastcall CcReferenceVacbArray(int a1)
{
  int result; // r0
  _DWORD *v3; // r2

  result = 0;
  v3 = *(_DWORD **)(CcVacbArrays + 4 * a1);
  if ( v3 )
  {
    result = *(_DWORD *)(CcVacbArrays + 4 * a1);
    ++v3[1];
    if ( *v3 != a1 )
      sub_53B49C(result);
  }
  return result;
}
