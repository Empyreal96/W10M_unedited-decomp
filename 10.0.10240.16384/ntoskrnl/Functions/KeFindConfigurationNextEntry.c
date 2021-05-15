// KeFindConfigurationNextEntry 
 
int __fastcall KeFindConfigurationNextEntry(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v6; // r4
  _DWORD *i; // r5
  int v9; // r0
  int v10; // [sp+8h] [bp-20h]

  v10 = a2;
  v6 = a1;
  if ( a4 )
    return sub_96F478();
  if ( a1 )
  {
    while ( 2 )
    {
      if ( *a5 )
      {
        if ( v6 == (_DWORD *)*a5 )
          *a5 = 0;
      }
      else if ( v6[3] == a2 && v6[4] == a3 )
      {
        return (int)v6;
      }
      for ( i = (_DWORD *)v6[2]; i; i = (_DWORD *)i[2] )
      {
        if ( *a5 )
        {
          if ( i == (_DWORD *)*a5 )
            *a5 = 0;
        }
        else if ( i[3] == a2 && i[4] == a3 )
        {
          return (int)i;
        }
        if ( i[1] )
        {
          v9 = KeFindConfigurationNextEntry();
          if ( v9 )
            return v9;
          a2 = v10;
        }
      }
      v6 = (_DWORD *)v6[1];
      if ( v6 )
        continue;
      break;
    }
  }
  return 0;
}
