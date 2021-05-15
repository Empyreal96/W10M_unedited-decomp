// RtlWriteTryAcquireTickLock 
 
int RtlWriteTryAcquireTickLock()
{
  __int64 v0; // r0
  unsigned __int64 v1; // r2
  unsigned __int64 v2; // kr00_8
  int result; // r0

  __pld((void *)0xFFFF9340);
  v0 = MEMORY[0xFFFF9340];
  if ( (MEMORY[0xFFFF9340] & 1) != 0 )
    return 0;
  v1 = MEMORY[0xFFFF9340] + 1i64;
  do
    v2 = __ldrexd((unsigned __int64 *)0xFFFF9340);
  while ( v2 == v0 && __strexd(v1, (unsigned __int64 *)0xFFFF9340) );
  __dmb(0xBu);
  if ( __PAIR64__(v0, HIDWORD(v0)) == __PAIR64__(v2, HIDWORD(v2)) )
    result = 1;
  else
    result = sub_51C03C();
  return result;
}
