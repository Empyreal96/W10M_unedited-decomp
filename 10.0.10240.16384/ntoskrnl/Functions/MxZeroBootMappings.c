// MxZeroBootMappings 
 
unsigned int __fastcall MxZeroBootMappings(unsigned int result, unsigned int a2)
{
  _DWORD *v2; // r4

  v2 = (_DWORD *)result;
  if ( result < a2 )
  {
    while ( !*v2 )
    {
      if ( (unsigned int)++v2 >= a2 )
        return result;
    }
    result = sub_96AE34();
  }
  return result;
}
