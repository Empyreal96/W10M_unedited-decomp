// sub_43E31C 
 
int __fastcall sub_43E31C(int a1, unsigned int a2, int a3, __int16 a4)
{
  int result; // r0

  result = 0;
  if ( (a4 & 0x100) == 0 )
    return sub_43E028(0, a2);
  if ( !a1 && a2 || a2 > 0x7FFFFFFF )
    result = -1073741811;
  return result;
}
