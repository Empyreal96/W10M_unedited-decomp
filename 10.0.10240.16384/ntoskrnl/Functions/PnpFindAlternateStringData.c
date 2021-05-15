// PnpFindAlternateStringData 
 
int __fastcall PnpFindAlternateStringData(char *a1, unsigned int a2, char **a3, _DWORD *a4)
{
  char *v5; // r6
  int v6; // r5
  unsigned int i; // r7
  int v8; // r4
  int v9; // t1

  if ( a2 > 2 && *(_WORD *)a1 == 64 )
  {
    v5 = a1 + 2;
    v6 = 0;
    for ( i = (unsigned int)(a1 + 4); i < (unsigned int)&a1[2 * (a2 >> 1)]; i += 2 )
    {
      v9 = *(unsigned __int16 *)v5;
      v5 += 2;
      v8 = v9;
      if ( !v9 )
        break;
      if ( v8 == 44 )
      {
        if ( *(_WORD *)v5 != 37 )
          return sub_7EFA9C();
        v6 = 1;
      }
      else if ( v8 == 59 )
      {
        if ( !v6 )
          return 0;
        *a4 = a1 - v5 + a2;
        *a3 = v5;
        return 1;
      }
    }
  }
  return 0;
}
