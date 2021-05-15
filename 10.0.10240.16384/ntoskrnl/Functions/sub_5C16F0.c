// sub_5C16F0 
 
int __fastcall sub_5C16F0(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  int result; // r0

  if ( !a3 || !a5 )
    return -1073741811;
  *a5 = 2;
  result = ZwOpenKey();
  if ( result < 0 && (a2 & 2) != 0 )
    result = ZwCreateKey();
  return result;
}
