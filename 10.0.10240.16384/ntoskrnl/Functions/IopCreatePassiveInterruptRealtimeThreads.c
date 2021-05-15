// IopCreatePassiveInterruptRealtimeThreads 
 
int IopCreatePassiveInterruptRealtimeThreads()
{
  int v0; // r6
  int result; // r0
  int v2; // r4
  int v3; // [sp+10h] [bp-40h] BYREF
  int v4; // [sp+14h] [bp-3Ch] BYREF
  int v5[14]; // [sp+18h] [bp-38h] BYREF

  v5[0] = 24;
  v5[1] = 0;
  v5[3] = 512;
  v5[2] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v0 = 0;
  if ( !PassiveInterruptRealtimeWorkerCount )
    return 0;
  while ( 1 )
  {
    result = PsCreateSystemThread((int)&v3, 0x1FFFFF, (int)v5);
    if ( result < 0 )
      break;
    v2 = ObReferenceObjectByHandle(v3, 0x1FFFFF, PsThreadType, 0, (int)&v4, 0);
    ZwClose();
    if ( v2 >= 0 )
    {
      KeSetActualBasePriorityThread(v4, (unsigned __int8)PassiveInterruptRealtimeWorkerPriority);
      ObfDereferenceObject(v4);
    }
    if ( ++v0 >= (unsigned int)(unsigned __int8)PassiveInterruptRealtimeWorkerCount )
      return 0;
  }
  return result;
}
