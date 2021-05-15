// RtlpLangNameInMultiSzString 
 
int __fastcall RtlpLangNameInMultiSzString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r5
  int v3; // r4

  v2 = a1;
  v3 = 0;
  if ( a1 && a2 )
  {
    while ( *v2 )
    {
      if ( !wcsicmp((int)v2, a2) )
        return 1;
      v2 += wcslen(v2) + 1;
      if ( !v2 )
        return v3;
    }
  }
  return v3;
}
