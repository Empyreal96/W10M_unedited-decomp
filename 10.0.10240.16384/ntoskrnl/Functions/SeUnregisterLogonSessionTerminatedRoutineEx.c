// SeUnregisterLogonSessionTerminatedRoutineEx 
 
int __fastcall SeUnregisterLogonSessionTerminatedRoutineEx(void *a1)
{
  int result; // r0
  unsigned int v3; // r2
  unsigned int v4; // r7
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  void **v8; // r2
  void **v9; // r4
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  if ( !a1 )
    return -1073741811;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
  v8 = &SeFileSystemNotifyRoutinesExHead;
  dword_649EF8 = v4;
  v9 = (void **)SeFileSystemNotifyRoutinesExHead;
  if ( !SeFileSystemNotifyRoutinesExHead )
    goto LABEL_23;
  do
  {
    if ( v9[1] == a1 )
      break;
    v8 = v9;
    v9 = (void **)*v9;
  }
  while ( v9 );
  if ( v9 )
  {
    *v8 = *v9;
    dword_649EF8 = 0;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&SepRmNotifyMutex);
    while ( !v10 && __strex(1u, (unsigned int *)&SepRmNotifyMutex) );
    if ( v10 )
      ExpReleaseFastMutexContended((unsigned int *)&SepRmNotifyMutex, v10);
    v11 = KeAbPostRelease((unsigned int)&SepRmNotifyMutex);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(v11);
    ExFreePoolWithTag((unsigned int)v9);
    result = 0;
  }
  else
  {
LABEL_23:
    dword_649EF8 = 0;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&SepRmNotifyMutex);
    while ( !v14 && __strex(1u, (unsigned int *)&SepRmNotifyMutex) );
    if ( v14 )
      ExpReleaseFastMutexContended((unsigned int *)&SepRmNotifyMutex, v14);
    v15 = KeAbPostRelease((unsigned int)&SepRmNotifyMutex);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    result = -1073741275;
  }
  return result;
}
