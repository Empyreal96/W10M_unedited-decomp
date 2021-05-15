// PopLogDisabledSleepReason 
 
unsigned int PopLogDisabledSleepReason()
{
  int v0; // r7
  int v1; // r9
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  int *v6; // r2
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r8
  int *v12; // r2
  _DWORD *v13; // r6

  v0 = 0;
  v1 = 0;
  v2 = KeAbPreAcquire((unsigned int)&PopDisableSleepMutex, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PopDisableSleepMutex);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopDisableSleepMutex) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    return sub_7BDCEC();
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61F804 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F81C = v3;
  PopRemoveReasonRecordByReasonCode(13);
  v6 = (int *)PopDisableSleepList;
  if ( (int *)PopDisableSleepList != &PopDisableSleepList )
  {
    do
    {
      v9 = v6[3];
      v6 = (int *)*v6;
      ++v1;
      v0 |= v9;
    }
    while ( v6 != &PopDisableSleepList );
    if ( v0 )
    {
      v10 = ExAllocatePoolWithTag(1, 8 * v1, 1718968931);
      v11 = v10;
      if ( v10 )
      {
        v12 = (int *)PopDisableSleepList;
        v13 = (_DWORD *)v10;
        while ( v12 != &PopDisableSleepList )
        {
          *v13 = v12[2];
          v13[1] = v12[3];
          v12 = (int *)*v12;
          v13 += 2;
        }
        PopLogSleepDisabled(13, v0, v10, 8 * v1);
        ExFreePoolWithTag(v11);
      }
    }
  }
  dword_61F804 = 0;
  v7 = dword_61F81C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopDisableSleepMutex);
  while ( !v8 && __strex(1u, (unsigned int *)&PopDisableSleepMutex) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PopDisableSleepMutex, v8);
  KfLowerIrql(v7);
  return KeAbPostRelease((unsigned int)&PopDisableSleepMutex);
}
