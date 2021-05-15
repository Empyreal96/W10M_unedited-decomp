// PfRequestRangeCheck 
 
int __fastcall PfRequestRangeCheck(unsigned int *a1, unsigned int a2, int a3, int a4, int a5)
{
  unsigned int v6; // r3
  unsigned int v7; // r2

  if ( a2 < *a1 )
    return 0;
  v6 = a1[1];
  if ( a2 >= v6 )
  {
    if ( a3 )
      return 0;
  }
  v7 = a3 + a2;
  if ( v7 < *a1 || v7 > v6 || ((a4 - 1) & v7) != 0 )
    return 0;
  if ( a5 )
    *a1 = v7;
  return 1;
}
