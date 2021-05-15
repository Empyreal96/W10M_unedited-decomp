// sub_6DF3D0 
 
int __fastcall sub_6DF3D0(_DWORD *a1)
{
  int result; // r0

  result = sub_6DF3F4(*a1, a1[1], a1[2], a1 + 3);
  a1[5] = result;
  return result;
}
