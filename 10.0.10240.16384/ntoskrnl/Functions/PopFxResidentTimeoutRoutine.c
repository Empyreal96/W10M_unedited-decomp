// PopFxResidentTimeoutRoutine 
 
int PopFxResidentTimeoutRoutine()
{
  int v0; // r3
  int v1; // r0
  unsigned int v2; // r2
  __int64 v4; // r0
  int *v5; // r5
  unsigned int v6; // r8
  unsigned int v7; // r4
  int v8; // r7
  int v9; // r3
  unsigned int *v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // [sp+0h] [bp-30h]
  int v18[10]; // [sp+8h] [bp-28h] BYREF

  v0 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v0 & 0xFFFFFFC0) + 0x134);
  v1 = KeAbPreAcquire(&PopFxDeviceListLock, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v2 )
    return sub_51EC88(v1, 17);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  if ( (int *)PopFxDeviceList != &PopFxDeviceList )
  {
    v4 = RtlGetInterruptTimePrecise(v18);
    v5 = (int *)PopFxDeviceList;
    v17 = HIDWORD(v4);
    v18[0] = v4;
    if ( (int *)PopFxDeviceList != &PopFxDeviceList )
    {
      v6 = HIDWORD(v4);
      do
      {
        v7 = 0;
        if ( v5[97] )
        {
          v8 = v18[0];
          do
          {
            v9 = *(_DWORD *)(v5[98] + 4 * v7);
            v10 = (unsigned int *)(v9 + 60);
            if ( *(int *)(v9 + 60) > 0
              && __PAIR64__(v6, v8) - *(_QWORD *)(v9 + 96) >= (unsigned int)PopFxActiveIdleThreshold )
            {
              do
                v15 = __ldrex(v10);
              while ( __strex(v15 - 1, v10) );
              __dmb(0xBu);
              do
                v16 = __ldrex((unsigned int *)&PopFxResidentComponentCount);
              while ( __strex(v16 - 1, (unsigned int *)&PopFxResidentComponentCount) );
              __dmb(0xBu);
              PopFxIdleComponent(v5, v7, 1, 0, v17);
            }
            ++v7;
          }
          while ( v7 < v5[97] );
        }
        v5 = (int *)*v5;
      }
      while ( v5 != &PopFxDeviceList );
    }
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v11 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v11 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock, 0);
  v12 = KeAbPostRelease(&PopFxDeviceListLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return PopFxArmResidentTimer(1);
}
