// _wcsset_s 
 
int __fastcall wcsset_s(_WORD *a1, int a2, __int16 a3)
{
  int v3; // r3
  _WORD *i; // r4
  int v5; // t1

  if ( a1 && a2 )
  {
    v3 = (unsigned __int16)*a1;
    for ( i = a1; v3; ++i )
    {
      if ( !--a2 )
        break;
      *i = a3;
      v5 = (unsigned __int16)i[1];
      v3 = v5;
    }
    if ( a2 )
      return 0;
    *a1 = 0;
  }
  PopPoCoalescinCallback();
  return 22;
}
