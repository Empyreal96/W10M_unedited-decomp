// StringCbLengthW 
 
int __fastcall StringCbLengthW(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v4; // r1
  int result; // r0

  v4 = a2 >> 1;
  if ( a1 && v4 <= 0x7FFFFFFF )
    result = sub_447D74();
  else
    result = -2147024809;
  if ( a3 )
    *a3 = 0;
  return result;
}
