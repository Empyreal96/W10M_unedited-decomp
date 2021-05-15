// PpmMediaBufferingWorker 
 
void PpmMediaBufferingWorker()
{
  int v0; // r7
  int v1; // r6
  unsigned int v2; // r2
  int v3; // r5
  __int64 v4; // kr00_8
  int var38[15]; // [sp+8h] [bp-38h] BYREF
  int vars4; // [sp+44h] [bp+4h]

  while ( 1 )
  {
    v0 = 1;
    v1 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      sub_50F4D0();
      return;
    }
    do
      v2 = __ldrex((unsigned int *)&PpmMediaBufferingWork);
    while ( __strex(1u, (unsigned int *)&PpmMediaBufferingWork) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PpmMediaBufferingWork);
    v3 = (unsigned __int8)byte_61F485;
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
      v4 = *(_QWORD *)&PpmEtwHandle;
      if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_MEDIA_BUFFERING_NOTIFY) )
      {
        var38[0] = v3 != 0;
        var38[2] = (int)var38;
        var38[3] = 0;
        var38[4] = 4;
        var38[5] = 0;
        EtwWrite(v4, SHIDWORD(v4), (int)PPM_ETW_MEDIA_BUFFERING_NOTIFY, 0);
      }
    }
    PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
    if ( !PpmLowPowerProfile && (v3 || !PpmPdcMediaEngaged) )
      v0 = 0;
    PpmReleaseLock(&PpmPerfPolicyLock);
    if ( v0 )
    {
      PpmPdcMediaEngaged = v3;
      PpmPdcNotifyMediaBufferingUpdate();
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
  KfLowerIrql(v1);
}
