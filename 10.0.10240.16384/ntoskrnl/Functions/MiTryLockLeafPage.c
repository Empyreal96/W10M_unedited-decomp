// MiTryLockLeafPage 
 
int __fastcall MiTryLockLeafPage(unsigned int *a1, int a2)
{
  unsigned int v4; // r4
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1

  do
  {
    v4 = *a1;
    if ( (*a1 & 2) == 0 && ((v4 & 0x400) != 0 || (v4 & 0x800) == 0) )
      return 0;
  }
  while ( !MI_IS_PFN(v4 >> 12) );
  result = MmPfnDatabase + 24 * (v4 >> 12);
  v6 = (unsigned __int8 *)(result + 15);
  if ( a2 == 1 )
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
  }
  else
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
  }
  __dmb(0xBu);
  if ( v7 >> 7 )
    return 0;
  if ( *a1 != v4 )
    result = sub_51F02C();
  return result;
}
