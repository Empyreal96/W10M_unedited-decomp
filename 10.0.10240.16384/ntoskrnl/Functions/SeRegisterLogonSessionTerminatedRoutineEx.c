// SeRegisterLogonSessionTerminatedRoutineEx 
 
int __fastcall SeRegisterLogonSessionTerminatedRoutineEx(int a1)
{
  _DWORD *v3; // r6
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  if ( !a1 )
    return -1073741811;
  v3 = (_DWORD *)ExAllocatePoolWithTag(257, 8, 1397122387);
  if ( !v3 )
    return -1073741670;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  __mrc(15, 0, 13, 0, 3);
  v5 = KeAbPreAcquire((unsigned int)&SepRmNotifyMutex, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&SepRmNotifyMutex);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&SepRmNotifyMutex) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&SepRmNotifyMutex, v5);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *v3 = SeFileSystemNotifyRoutinesExHead;
  v3[1] = a1;
  dword_649EF8 = 0;
  SeFileSystemNotifyRoutinesExHead = v3;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&SepRmNotifyMutex);
  while ( !v8 && __strex(1u, (unsigned int *)&SepRmNotifyMutex) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&SepRmNotifyMutex, v8);
  v9 = KeAbPostRelease((unsigned int)&SepRmNotifyMutex);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return 0;
}
