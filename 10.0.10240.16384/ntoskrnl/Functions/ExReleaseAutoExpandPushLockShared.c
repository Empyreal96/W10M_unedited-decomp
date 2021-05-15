// ExReleaseAutoExpandPushLockShared 
 
__int64 __fastcall ExReleaseAutoExpandPushLockShared(__int64 a1, unsigned __int64 a2)
{
  char v2; // r6
  unsigned int *v3; // r4
  unsigned int v4; // r5
  unsigned int v5; // r2
  unsigned int v7; // r3
  BOOL v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r0
  unsigned __int64 v11; // r2
  unsigned __int64 v13; // [sp+8h] [bp-20h] BYREF

  v13 = a2;
  v2 = BYTE4(a1);
  if ( (a1 & 0xFFFFFFFC00000000ui64) != 0 )
    sub_51E638(a1, 3, a2, HIDWORD(a1) & 0xFFFFFFFC);
  if ( (a1 & 2) != 0 && (a1 & 0x200000000i64) != 0 )
    KeBugCheckEx(338, HIDWORD(a1), a1);
  v3 = (unsigned int *)(a1 & 0xFFFFFFFC);
  if ( (a1 & 1) != 0 )
  {
    __pld(v3 + 2);
    v4 = *(_DWORD *)((a1 & 0xFFFFFFFC) + 8);
    if ( v4 >= 0x80000000 && (*(_DWORD *)((a1 & 0xFFFFFFFC) + 4) & 3) == 0 )
    {
      v8 = (unsigned __int16)v4 >= (unsigned int)ExpAeCycleCountThreshold && (v4 & 0xF0000) < 0xF0000;
      if ( v8 && (unsigned int)KeGetCurrentIrql(a1) < 2 )
      {
        ExpTryExpandAutoExpandPushLock(v3);
      }
      else
      {
        v4 = (v4 >> 2) & 0x3FF33FFF;
        v3[2] = v4;
      }
    }
    __dmb(0xBu);
    do
      v5 = __ldrex(v3);
    while ( v5 == 17 && __strex(0, v3) );
    if ( v5 == 17 )
    {
LABEL_11:
      if ( v4 < 0x80000000 )
        v3[2] = v4 + 0x100000;
      goto LABEL_13;
    }
    if ( (ExpAeSamplingPeriodMask & v4) == 0 )
    {
      ExfReleasePushLockSharedEx(v3, &v13);
      if ( !v13 )
        goto LABEL_13;
      v10 = v3[2];
      if ( v10 >= 0x80000000 )
        goto LABEL_13;
      v11 = v13 >> ExpAeCycleCountScaler;
      if ( v13 >> ExpAeCycleCountScaler > 0x1FF )
      {
        LODWORD(v11) = 511;
        HIDWORD(v13) = 0;
      }
      v4 = v11 + v10;
      goto LABEL_11;
    }
    ExfReleasePushLockSharedEx(v3, 0);
    v7 = v3[2];
    if ( v7 < 0x80000000 )
      v3[2] = v7 + 0x100000;
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(v3);
    while ( v9 == 17 && __strex(0, v3) );
    if ( v9 != 17 )
      ExfReleasePushLockShared(v3, 0);
    v3 = (unsigned int *)v3[1];
  }
LABEL_13:
  if ( (v2 & 2) == 0 )
    KeAbPostRelease(v3);
  return a1;
}
