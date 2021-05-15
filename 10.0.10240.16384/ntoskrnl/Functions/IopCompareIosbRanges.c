// IopCompareIosbRanges 
 
int __fastcall IopCompareIosbRanges(int a1, unsigned int *a2, unsigned int *a3)
{
  unsigned int v3; // r2

  v3 = *a3;
  if ( *a2 < v3 )
    return 0;
  if ( *a2 <= v3 )
    return 2;
  return 1;
}
