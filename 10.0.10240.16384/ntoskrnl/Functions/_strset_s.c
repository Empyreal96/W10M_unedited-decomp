// _strset_s 
 
int __fastcall strset_s(_BYTE *a1, int a2, char a3)
{
  int v3; // r3
  _BYTE *i; // r4
  int v5; // t1

  if ( a1 && a2 )
  {
    v3 = (char)*a1;
    for ( i = a1; v3; ++i )
    {
      if ( !--a2 )
        break;
      *i = a3;
      v5 = (char)i[1];
      v3 = v5;
    }
    if ( a2 )
      return 0;
    *a1 = 0;
  }
  PopPoCoalescinCallback();
  return 22;
}
