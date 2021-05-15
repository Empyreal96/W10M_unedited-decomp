// CmRmIsKCBVisible 
 
int __fastcall CmRmIsKCBVisible(int a1, int a2, int a3)
{
  int v4; // r1
  int result; // r0

  v4 = *(_DWORD *)(a1 + 124);
  if ( v4 )
    result = sub_7FDD2C(a1, v4, a3, a2);
  else
    result = 1;
  return result;
}
