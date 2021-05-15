// CmpDoSystemCacheRead 
 
int __fastcall CmpDoSystemCacheRead(int a1, unsigned int *a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4
  unsigned int i; // r6
  int v9; // r10
  unsigned int v10; // r5

  v4 = a4;
  for ( i = *a2; v4; a3 += v10 )
  {
    v9 = HvViewMapAddressForFileOffset(a1 + 152, i);
    v10 = HvViewMapContiguousBytesAfterFileOffset(a1 + 152, i);
    if ( v10 > v4 )
      v10 = v4;
    memmove(a3, v9, v10);
    i += v10;
    *a2 = i;
    v4 -= v10;
  }
  return 0;
}
