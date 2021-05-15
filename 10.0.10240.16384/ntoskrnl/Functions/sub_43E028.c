// sub_43E028 
 
int __fastcall sub_43E028(int a1, unsigned int a2)
{
  int result; // r0

  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -1073741811;
  return result;
}
