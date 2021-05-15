// PoDisableSleepStates 
 
int __fastcall PoDisableSleepStates(int a1, int a2, int **a3)
{
  int *v6; // r0
  int *v7; // r6
  int v9; // r5
  int v10; // r8
  unsigned int v11; // r2
  int **v12; // r1
  unsigned __int8 v13; // r5
  unsigned int v14; // r1

  v6 = (int *)ExAllocatePoolWithTag(1, 16, 1683189584);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  *v6 = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  v6[2] = a1;
  v6[3] = a2;
  v9 = KeAbPreAcquire((unsigned int)&PopDisableSleepMutex, 0, 0);
  v10 = KfRaiseIrql(1);
  do
    v11 = __ldrex((unsigned __int8 *)&PopDisableSleepMutex);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)&PopDisableSleepMutex) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopDisableSleepMutex, v9);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_61F804 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = (int **)dword_61F7F4;
  dword_61F81C = v10;
  *v7 = (int)&PopDisableSleepList;
  v7[1] = (int)v12;
  if ( *v12 != &PopDisableSleepList )
    __fastfail(3u);
  *v12 = v7;
  dword_61F804 = 0;
  v13 = dword_61F81C;
  dword_61F7F4 = (int)v7;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&PopDisableSleepMutex);
  while ( !v14 && __strex(1u, (unsigned int *)&PopDisableSleepMutex) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)&PopDisableSleepMutex, v14);
  KfLowerIrql(v13);
  KeAbPostRelease((unsigned int)&PopDisableSleepMutex);
  *a3 = v7;
  return 0;
}
