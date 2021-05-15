// EmpReleasePagingReference 
 
unsigned int EmpReleasePagingReference()
{
  int v0; // r0
  unsigned int v1; // r2
  unsigned int v3; // r1

  v0 = KeAbPreAcquire((unsigned int)&EmpPagingLock, 0, 0);
  do
    v1 = __ldrex((unsigned __int8 *)&EmpPagingLock);
  while ( __strex(v1 | 1, (unsigned __int8 *)&EmpPagingLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    return sub_694764(v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  dword_631F1C = dword_631F1C & 0x80000000 | (dword_631F1C - 1) & 0x7FFFFFFF;
  if ( (dword_631F1C & 0x7FFFFFFF) == 0 && EmpPagingStatus )
    KeSetEvent(EmpPagingStatus, 0, 0);
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&EmpPagingLock);
  while ( __strex(v3 - 1, (unsigned int *)&EmpPagingLock) );
  if ( (v3 & 2) != 0 && (v3 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpPagingLock);
  return KeAbPostRelease((unsigned int)&EmpPagingLock);
}
