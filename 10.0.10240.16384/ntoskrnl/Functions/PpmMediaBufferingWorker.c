// PpmMediaBufferingWorker 
 
int PpmMediaBufferingWorker()
{
  int v0; // r7
  int v1; // r6
  unsigned int v3; // r2
  int v4; // r5
  __int64 v5; // kr00_8
  int v6[2]; // [sp+8h] [bp-38h] BYREF
  int var30[13]; // [sp+10h] [bp-30h] BYREF
  int vars4; // [sp+44h] [bp+4h]

  while ( 1 )
  {
    v0 = 1;
    v1 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_50F4D0();
    do
      v3 = __ldrex((unsigned int *)&PpmMediaBufferingWork);
    while ( __strex(1u, (unsigned int *)&PpmMediaBufferingWork) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire(&PpmMediaBufferingWork);
    v4 = (unsigned __int8)byte_61F485;
    if ( byte_61F485 == byte_61EC4C )
      break;
    byte_61EC4C = byte_61F485;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PpmMediaBufferingWork, vars4);
    }
    else
    {
      __dmb(0xBu);
      PpmMediaBufferingWork = 0;
    }
    KfLowerIrql(v1);
    if ( PpmEtwRegistered )
    {
      v5 = *(_QWORD *)&PpmEtwHandle;
      if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_MEDIA_BUFFERING_NOTIFY) )
      {
        var30[0] = (int)v6;
        var30[1] = 0;
        var30[2] = 4;
        var30[3] = 0;
        ((void (__fastcall *)(_DWORD, _DWORD, int *, _DWORD, int, int *, bool, int))EtwWrite)(
          v5,
          HIDWORD(v5),
          PPM_ETW_MEDIA_BUFFERING_NOTIFY,
          0,
          1,
          var30,
          v4 != 0,
          v6[1]);
      }
    }
    PpmAcquireLock(&PpmPerfPolicyLock);
    if ( !PpmLowPowerProfile && (v4 || !PpmPdcMediaEngaged) )
      v0 = 0;
    PpmReleaseLock(&PpmPerfPolicyLock);
    if ( v0 )
    {
      PpmPdcMediaEngaged = v4;
      PpmPdcNotifyMediaBufferingUpdate(v4);
    }
  }
  byte_61F484 = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PpmMediaBufferingWork, vars4);
  }
  else
  {
    __dmb(0xBu);
    PpmMediaBufferingWork = 0;
  }
  return KfLowerIrql(v1);
}
