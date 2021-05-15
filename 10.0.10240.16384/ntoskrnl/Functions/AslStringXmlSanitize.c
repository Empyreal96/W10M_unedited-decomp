// AslStringXmlSanitize 
 
int __fastcall AslStringXmlSanitize(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r4
  unsigned int i; // r0
  unsigned int v4; // r5
  __int16 *v5; // r2
  unsigned int v6; // r1

  v1 = a1;
  if ( !a1 )
    return -1073741811;
  if ( *a1 )
  {
    for ( i = wcslen(a1); i; --i )
    {
      v4 = *v1;
      v5 = &word_41D548;
      v6 = 0;
      while ( v4 < (unsigned __int16)*v5 || v4 > (unsigned __int16)v5[1] )
      {
        ++v6;
        v5 += 2;
        if ( v6 >= 5 )
        {
          *v1 = 64;
          break;
        }
      }
      ++v1;
    }
  }
  return 0;
}
