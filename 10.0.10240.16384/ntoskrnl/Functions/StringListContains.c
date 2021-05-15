// StringListContains 
 
int __fastcall StringListContains(unsigned __int16 *a1, int a2, unsigned __int16 *a3, int a4)
{
  unsigned __int16 *v4; // r7
  int i; // r5
  unsigned __int16 *v9; // r6

  v4 = a3;
  for ( i = 0; *v4; v4 += wcslen(v4) + 1 )
  {
    v9 = a1;
    if ( *a1 )
    {
      while ( a4 ? wcsicmp((int)v9, v4) : wcscmp((char *)v9, (char *)v4) )
      {
        v9 += wcslen(v9) + 1;
        if ( !*v9 )
          goto LABEL_10;
      }
      i = 1;
    }
LABEL_10:
    if ( a2 == 18 || a2 == 8210 && i )
      break;
  }
  return i;
}
