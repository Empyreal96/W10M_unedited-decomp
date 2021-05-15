// PoReenableSleepStates 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PoReenableSleepStates(unsigned int a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  unsigned __int8 v7; // r5
  unsigned int v8; // r1

  v2 = KeAbPreAcquire((unsigned int)&PopDisableSleepMutex, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PopDisableSleepMutex);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopDisableSleepMutex) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopDisableSleepMutex, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61F804 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F81C = v3;
  *(_QWORD *)&v5 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v6 != a1 )
    __fastfail(3u);
  *v6 = v5;
  *(_DWORD *)(v5 + 4) = v6;
  dword_61F804 = 0;
  v7 = dword_61F81C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopDisableSleepMutex);
  while ( !v8 && __strex(1u, (unsigned int *)&PopDisableSleepMutex) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PopDisableSleepMutex, v8);
  KfLowerIrql(v7);
  KeAbPostRelease((unsigned int)&PopDisableSleepMutex);
  return ExFreePoolWithTag(a1);
}
