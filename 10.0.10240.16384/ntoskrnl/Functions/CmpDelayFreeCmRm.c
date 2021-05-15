// CmpDelayFreeCmRm 
 
void __fastcall __spoils<R2,R3,R12> CmpDelayFreeCmRm(int *a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  int **v5; // r1
  unsigned __int8 v6; // r5
  unsigned int v7; // r1

  v2 = KeAbPreAcquire((unsigned int)&CmpDelayFreeRMLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&CmpDelayFreeRMLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&CmpDelayFreeRMLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpDelayFreeRMLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_631FE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (int **)dword_631FC4;
  dword_631FFC = v3;
  *a1 = (int)&CmpDelayFreeRMListHead;
  a1[1] = (int)v5;
  if ( *v5 != &CmpDelayFreeRMListHead )
    __fastfail(3u);
  *v5 = a1;
  dword_631FC4 = (int)a1;
  if ( !CmpDelayFreeRMWorkItemActive )
  {
    CmpDelayFreeRMWorkItemActive = 1;
    KiSetTimerEx((int)&CmpDelayFreeRMTimer, 0, -300000000i64, 0, 0, (int)&CmpDelayFreeRMDpc);
  }
  dword_631FE4 = 0;
  v6 = dword_631FFC;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&CmpDelayFreeRMLock);
  while ( !v7 && __strex(1u, (unsigned int *)&CmpDelayFreeRMLock) );
  if ( v7 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpDelayFreeRMLock, v7);
  KfLowerIrql(v6);
  KeAbPostRelease((unsigned int)&CmpDelayFreeRMLock);
}
