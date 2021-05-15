// EmpAcquirePagingReference 
 
int EmpAcquirePagingReference()
{
  int v0; // r6
  int v1; // r0
  unsigned int v2; // r2
  unsigned int v4; // r1

  v0 = 0;
  v1 = KeAbPreAcquire((unsigned int)&EmpPagingLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&EmpPagingLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&EmpPagingLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_694790(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  if ( dword_631F1C < 0 )
  {
    dword_631F1C = dword_631F1C & 0x80000000 | (dword_631F1C + 1) & 0x7FFFFFFF;
    v0 = 1;
  }
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&EmpPagingLock);
  while ( __strex(v4 - 1, (unsigned int *)&EmpPagingLock) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpPagingLock);
  KeAbPostRelease((unsigned int)&EmpPagingLock);
  return v0;
}
