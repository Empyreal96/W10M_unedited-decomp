// sub_6E331C 
 
int __fastcall sub_6E331C(int a1, int a2, int a3, int a4, unsigned int a5, int a6, _DWORD *a7)
{
  int result; // r0
  int v11; // [sp+8h] [bp-18h]

  v11 = a4;
  if ( a1 != 3 && a1 != 4 )
    return sub_7DB520();
  result = ExQueryClipSp(a1, a2, a3, a5, a6, a7);
  if ( result < 0 && result != -1073741789 )
    result = sub_6E3370(a1, a2, a4, a5, a6, a7, v11);
  return result;
}
