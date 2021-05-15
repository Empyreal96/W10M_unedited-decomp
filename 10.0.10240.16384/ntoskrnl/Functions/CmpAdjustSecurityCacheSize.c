// CmpAdjustSecurityCacheSize 
 
int __fastcall CmpAdjustSecurityCacheSize(_DWORD *a1)
{
  unsigned int v1; // r2
  int v3; // r0
  int v4; // r5
  int v5; // r3

  v1 = a1[498];
  if ( v1 >= a1[499] )
    return 1;
  v3 = ExAllocatePoolWithTag(1, 8 * v1, 1666403651);
  v4 = v3;
  if ( v3 )
  {
    memmove(v3, a1[501], 8 * a1[498]);
    ExFreePoolWithTag(a1[501]);
    v5 = a1[498];
    a1[501] = v4;
    a1[499] = v5;
    return 1;
  }
  return 0;
}
