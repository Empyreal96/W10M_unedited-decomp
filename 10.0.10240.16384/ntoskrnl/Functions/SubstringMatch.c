// SubstringMatch 
 
BOOL __fastcall SubstringMatch(char *a1, char *a2, int a3, int a4)
{
  unsigned __int16 *v7; // r0
  bool v8; // zf
  unsigned int v9; // r4
  BOOL result; // r0

  if ( a3 )
    v7 = (unsigned __int16 *)wcsistr();
  else
    v7 = (unsigned __int16 *)wcsstr(a1, a2);
  result = 0;
  if ( v7 )
  {
    if ( a4 == 9 )
    {
      v8 = v7 == (unsigned __int16 *)a1;
    }
    else if ( a4 == 10 )
    {
      v9 = wcslen(v7);
      v8 = v9 == wcslen((unsigned __int16 *)a2);
    }
    else
    {
      v8 = a4 == 11;
    }
    if ( v8 )
      result = 1;
  }
  return result;
}
