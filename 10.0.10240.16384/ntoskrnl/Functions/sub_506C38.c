// sub_506C38 
 
int __fastcall sub_506C38(int result)
{
  int v1; // r7
  int v2; // r3

  *(_DWORD *)(v1 + 16) = result;
  if ( result )
  {
    result = *(_DWORD *)(v1 + 40);
    v2 = *(_DWORD *)(result + 8) + 13;
    *(_DWORD *)(result + 8) = v2;
    if ( v2 == 104 )
      result = KiVerifyXcptFilter();
  }
  return result;
}
