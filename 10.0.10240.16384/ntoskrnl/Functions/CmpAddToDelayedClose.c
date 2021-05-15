// CmpAddToDelayedClose 
 
unsigned int __fastcall CmpAddToDelayedClose(_DWORD *a1)
{
  int v2; // r8
  int v3; // r5
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r0
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  unsigned int result; // r0

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&CmpDelayedCloseTableLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)&CmpDelayedCloseTableLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&CmpDelayedCloseTableLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpDelayedCloseTableLock, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_6322E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = CmpDelayedLRUListHead;
  dword_6322FC = v4;
  a1[29] = CmpDelayedLRUListHead;
  a1[30] = &CmpDelayedLRUListHead;
  if ( *(int **)(v6 + 4) != &CmpDelayedLRUListHead )
    sub_7EE360();
  *(_DWORD *)(v6 + 4) = a1 + 29;
  CmpDelayedLRUListHead = (int)(a1 + 29);
  a1[2] |= 2u;
  ++CmpDelayedCloseElements;
  ++qword_920968;
  if ( CmpDelayedCloseElements > (unsigned int)CmpDelayedCloseSize )
    v2 = 1;
  dword_6322E4 = 0;
  v7 = dword_6322FC;
  __dmb(0xBu);
  do
    v8 = __ldrex(&CmpDelayedCloseTableLock);
  while ( !v8 && __strex(1u, &CmpDelayedCloseTableLock) );
  if ( v8 )
    ExpReleaseFastMutexContended(&CmpDelayedCloseTableLock, v8);
  KfLowerIrql(v7);
  result = KeAbPostRelease((unsigned int)&CmpDelayedCloseTableLock);
  if ( v2 == 1 )
    result = CmpArmDelayedCloseTimer(result);
  return result;
}
