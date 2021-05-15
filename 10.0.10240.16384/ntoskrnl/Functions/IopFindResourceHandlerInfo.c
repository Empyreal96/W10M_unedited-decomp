// IopFindResourceHandlerInfo 
 
int __fastcall IopFindResourceHandlerInfo(int a1, unsigned __int16 *a2, unsigned int a3, int ***a4)
{
  int v6; // r0
  int v7; // r2
  int ***v8; // r1
  int v9; // r3
  int **i; // r2

  *a4 = 0;
  if ( a1 == 1 )
  {
    v6 = a2[172];
    v7 = a2[173];
    v8 = (int ***)(a2 + 168);
  }
  else
  {
    if ( a1 != 2 )
      return 0;
    v6 = a2[174];
    v7 = a2[175];
    v8 = (int ***)(a2 + 164);
  }
  v9 = (unsigned __int16)(1 << a3);
  if ( (v6 & v9) != 0 )
    return 1;
  if ( (v7 & v9) != 0 || a3 > 0xF )
  {
    for ( i = *v8; i != (int **)v8; i = (int **)*i )
    {
      if ( *((unsigned __int8 *)i + 8) == a3 )
      {
        if ( a3 > 0xF )
          return sub_80E084();
        *a4 = i;
        return 1;
      }
    }
  }
  return 0;
}
