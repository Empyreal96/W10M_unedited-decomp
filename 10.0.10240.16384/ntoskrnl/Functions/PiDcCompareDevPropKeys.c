// PiDcCompareDevPropKeys 
 
int __fastcall PiDcCompareDevPropKeys(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // r0

  v3 = memcmp(a2, a3, 20);
  if ( v3 < 0 )
    return 0;
  if ( v3 <= 0 )
    return 2;
  return 1;
}
