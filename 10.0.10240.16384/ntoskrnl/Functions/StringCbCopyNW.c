// StringCbCopyNW 
 
int __fastcall StringCbCopyNW(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // r0

  result = 0;
  if ( !(a2 >> 1) )
    result = -2147024809;
  if ( result >= 0 )
  {
    if ( a4 >> 1 == 0x7FFFFFFF )
    {
      result = -2147024809;
      *a1 = 0;
    }
    else
    {
      result = sub_5B3C20(a1, a2 >> 1, a3, a3);
    }
  }
  return result;
}
