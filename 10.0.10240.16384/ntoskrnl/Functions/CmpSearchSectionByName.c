// CmpSearchSectionByName 
 
int **__fastcall CmpSearchSectionByName(int ***a1, unsigned __int8 *a2)
{
  int **i; // r4
  int **v5; // r5
  unsigned __int8 *v7; // r0

  i = 0;
  if ( a1 && a2 )
  {
    v5 = a1[1];
    i = v5;
    if ( v5 )
    {
      do
      {
        if ( !stricmp((unsigned __int8 *)i[1], a2) )
          break;
        i = (int **)*i;
      }
      while ( i );
      if ( i )
        goto LABEL_6;
    }
    for ( i = *a1; i; i = (int **)*i )
    {
      if ( i == v5 )
        goto LABEL_19;
      v7 = (unsigned __int8 *)i[1];
      if ( v7 )
      {
        if ( !stricmp(v7, a2) )
          break;
      }
    }
    if ( i != v5 )
      goto LABEL_16;
LABEL_19:
    i = 0;
LABEL_16:
    if ( i )
LABEL_6:
      a1[1] = i;
  }
  return i;
}
