// PopFanUpdateRunningState 
 
int __fastcall PopFanUpdateRunningState(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r3
  __int64 v8; // r0
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopFanLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PopFanLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&PopFanLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopFanLock, v3, (unsigned int)&PopFanLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61E624 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 )
    v6 = PopFanTracking + 1;
  else
    v6 = PopFanTracking - 1;
  __dmb(0xBu);
  PopFanTracking = v6;
  v7 = PopFanTracking;
  __dmb(0xBu);
  if ( v7 )
  {
    if ( !byte_61E664 )
    {
      byte_61E664 = 1;
      LODWORD(v8) = KeQueryInterruptTime();
      *(_QWORD *)&algn_61E666[2] = v8;
    }
  }
  else if ( byte_61E664 )
  {
    if ( byte_61E665 )
      PopFanEndCsFanPeriod();
    byte_61E664 = 0;
    *(_DWORD *)&algn_61E666[2] = 0;
    *(_DWORD *)&algn_61E666[6] = 0;
  }
  dword_61E624 = 0;
  __pld(&PopFanLock);
  v9 = PopFanLock;
  v10 = PopFanLock - 16;
  if ( (PopFanLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (PopFanLock & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopFanLock);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&PopFanLock) );
  if ( v11 != v9 )
LABEL_24:
    ExfReleasePushLock(&PopFanLock, v9);
  result = KeAbPostRelease((unsigned int)&PopFanLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
