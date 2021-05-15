// SmSanitizeString 
 
unsigned int __fastcall SmSanitizeString(unsigned int result, unsigned int a2)
{
  _WORD *v2; // r4
  unsigned int v3; // r7
  unsigned int v4; // r6
  unsigned int v5; // r5

  v2 = (_WORD *)result;
  v3 = 0;
  if ( result > result + 2 * (a2 >> 1) - 2 )
    v4 = 0;
  else
    v4 = (2 * (a2 >> 1) - 1) >> 1;
  if ( v4 )
  {
    do
    {
      v5 = (unsigned __int16)*v2;
      if ( *v2 )
      {
        if ( v5 > 0xFF || (result = isprint((unsigned __int16)*v2)) == 0 )
          v5 = (unsigned __int16)(v5 - 87 * ((int)((unsigned __int64)(789879043i64 * (int)v5) >> 32) >> 4) + 36);
        if ( v5 == 92 )
          LOWORD(v5) = 95;
        *v2 = v5;
      }
      else
      {
        *v2 = 126;
      }
      ++v3;
      ++v2;
    }
    while ( v3 < v4 );
  }
  *v2 = 0;
  return result;
}
