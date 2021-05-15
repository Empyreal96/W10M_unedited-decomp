// VfUtilAddressRangeFit 
 
BOOL __fastcall VfUtilAddressRangeFit(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r4

  v3 = *a1;
  if ( !*a1 )
    return 0;
  if ( a2 > v3 )
    goto LABEL_5;
  if ( a3 >= a1[1] )
    return 1;
  if ( a2 >= v3 )
  {
LABEL_5:
    if ( a2 >= a1[1] )
      return a3 > v3 && a3 <= a1[1];
    return 1;
  }
  return a3 > v3 && a3 <= a1[1];
}
