// PopResetIdleTime 
 
int __fastcall PopResetIdleTime(int a1)
{
  int result; // r0
  int v3; // r8
  int v4; // r9
  unsigned int v5; // r2
  __int64 v6; // kr00_8
  int v7; // [sp+8h] [bp-48h] BYREF
  int var44[18]; // [sp+Ch] [bp-44h] BYREF

  result = KeGetCurrentIrql(a1);
  if ( !PopPlatformAoAc || a1 != 4 )
    dword_61E808 = 0;
  dword_61E838 = 0;
  v3 = 0;
  if ( a1 != 3 && a1 != 5 )
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&PopIdleAoAcDozeS4Lock);
    }
    else
    {
      do
        v5 = __ldrex((unsigned int *)&PopIdleAoAcDozeS4Lock);
      while ( __strex(1u, (unsigned int *)&PopIdleAoAcDozeS4Lock) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire(&PopIdleAoAcDozeS4Lock);
    }
    if ( byte_61E83C )
    {
      KeCancelTimer2(&PopIdleAoAcDozeS4Timer, 0);
      byte_61E83C = 0;
      v3 = 1;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PopIdleAoAcDozeS4Lock);
    }
    else
    {
      __dmb(0xBu);
      PopIdleAoAcDozeS4Lock = 0;
    }
    result = KfLowerIrql(v4);
  }
  var44[0] = a1;
  if ( PopDiagHandleRegistered )
  {
    v6 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_SYSTEM_IDLE_TIME_RESET);
    if ( result )
    {
      var44[1] = (int)var44;
      var44[2] = 0;
      var44[3] = 4;
      var44[4] = 0;
      var44[5] = (int)&v7;
      var44[6] = 0;
      var44[7] = 4;
      var44[8] = 0;
      v7 = v3;
      result = EtwWrite(v6, SHIDWORD(v6), (int)POP_ETW_EVENT_SYSTEM_IDLE_TIME_RESET, 0);
    }
  }
  return result;
}
