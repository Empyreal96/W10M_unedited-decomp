// HvViewMapCopyToFileOffset 
 
int __fastcall HvViewMapCopyToFileOffset(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r4
  int v7; // r7
  unsigned int v8; // r0
  int result; // r0

  v4 = a4;
  v5 = a2;
  if ( !a4 )
    return 0;
  v7 = a3 - a2;
  while ( 1 )
  {
    v8 = HvViewMapAddressForFileOffset(a1, v5);
    result = MmCopyToCachedPage(v8, v7 + v5, 0, 0x1000u, 0);
    if ( result < 0 )
      break;
    v5 += 4096;
    v4 -= 4096;
    if ( !v4 )
      return 0;
  }
  return result;
}
