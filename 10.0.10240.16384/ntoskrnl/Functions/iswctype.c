// iswctype 
 
int __fastcall iswctype(unsigned int a1, __int16 a2)
{
  int result; // r0

  if ( a1 >= 0x100 )
    result = 0;
  else
    result = (unsigned __int16)(pwctype[a1] & a2);
  return result;
}
