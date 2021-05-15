// CmGetVisibleValueCount 
 
int __fastcall CmGetVisibleValueCount(int a1, int a2, int a3)
{
  int result; // r0

  result = -1;
  if ( a2 )
    result = *(_DWORD *)(a2 + 36);
  if ( a1 )
  {
    if ( a3 )
      result = sub_80454C(result);
    else
      result = *(_DWORD *)(a1 + 52);
  }
  return result;
}
