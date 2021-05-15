// MiCollapseRunTopDown 
 
int __fastcall MiCollapseRunTopDown(unsigned int *a1)
{
  unsigned int v1; // r2
  unsigned int v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r3
  int v7; // r5
  unsigned int v9; // r3

  v1 = a1[3];
  if ( a1[1] - 1 > v1 )
    a1[1] = v1 + 1;
  v2 = a1[2];
  if ( *a1 < v2 )
    *a1 = v2;
  v3 = a1[1];
  v4 = *a1;
  if ( *a1 < v3 )
  {
    v5 = a1[5];
    while ( v5 <= v3 - v4 )
    {
      v6 = a1[4];
      if ( !v6 )
        return 1;
      v7 = ~(v6 - 1);
      if ( (((v3 - 1) ^ (v3 - v5)) & v7) == 0 )
        return 1;
      v9 = v3 & v7;
      if ( (v3 & v7) == v3 )
        v9 = v3 + v7;
      v3 = v9;
      a1[1] = v9;
      if ( v4 >= v9 )
        return 0;
    }
  }
  return 0;
}
