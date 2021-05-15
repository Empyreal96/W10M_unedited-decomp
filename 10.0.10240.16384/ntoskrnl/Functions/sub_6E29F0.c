// sub_6E29F0 
 
int __fastcall sub_6E29F0(_DWORD *a1, _DWORD *a2, unsigned int a3, _DWORD *a4, int a5)
{
  int result; // r0
  _DWORD *varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = a1;
  result = 0;
  *a4 = 4;
  if ( a3 < 4 )
    return -1073741789;
  if ( a1 )
    *a1 = 4;
  if ( a2 )
    *a2 = a5;
  return result;
}
