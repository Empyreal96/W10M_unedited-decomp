// ExfTryAcquirePushLockShared 
 
int __fastcall ExfTryAcquirePushLockShared(unsigned int *a1)
{
  unsigned int *v1; // r5
  int result; // r0
  unsigned int i; // r2
  int v5; // r1
  unsigned int v6; // r4

  v1 = a1;
  __pld(a1);
  result = 0;
  for ( i = *a1; (i & 1) == 0 || (i & 2) == 0 && (i & 0xFFFFFFF0) != 0; i = v6 )
  {
    v5 = i | 1;
    if ( (i & 2) == 0 )
      v5 += 16;
    __dmb(0xBu);
    do
      v6 = __ldrex(v1);
    while ( v6 == i && __strex(v5, v1) );
    __dmb(0xBu);
    if ( v6 == i )
      return 1;
  }
  return result;
}
