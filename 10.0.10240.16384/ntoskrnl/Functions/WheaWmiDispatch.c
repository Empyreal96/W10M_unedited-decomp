// WheaWmiDispatch 
 
int __fastcall WheaWmiDispatch(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int result; // r0

  switch ( a1 )
  {
    case 0:
      return sub_5C3408(0, a3, a4, a6);
    case 8:
      return sub_4F7B1C(8, a3, a4, a6);
    case 1:
      return sub_5C345C(1, a3, a4, a6);
    case 9:
      return sub_55538C(9, a2, a3, a6);
  }
  result = -1073741808;
  *a6 = 0;
  return result;
}
