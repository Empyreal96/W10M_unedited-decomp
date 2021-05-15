// ViFaultsAddAllApps 
 
int __fastcall ViFaultsAddAllApps(_WORD *a1, int a2)
{
  _WORD *v2; // r5
  int v3; // r2
  int v4; // r3
  _WORD *i; // r4
  int v6; // r3

  v2 = &a1[a2];
  v3 = 0;
  while ( a1 < v2 )
  {
    v4 = (unsigned __int16)*a1;
    if ( v4 == 9 || v4 == 10 || v4 == 13 || v4 == 32 || v4 == 12288 || !*a1 )
    {
      ++a1;
    }
    else
    {
      for ( i = a1; i < v2; ++i )
      {
        v6 = (unsigned __int16)*i;
        if ( v6 == 9 )
          break;
        if ( v6 == 10 )
          break;
        if ( v6 == 13 )
          break;
        if ( v6 == 32 )
          break;
        if ( v6 == 12288 )
          break;
        if ( !*i )
          break;
      }
      v3 = ViFaultsAddAppNoDuplicates();
      if ( v3 < 0 )
        return v3;
      a1 = i + 1;
    }
  }
  return v3;
}
