// EtwpKernelTraceRundown 
 
int EtwpKernelTraceRundown(int *a1, ...)
{
  unsigned int v1; // r5
  int v3; // r8
  int v5; // r2
  int v6; // r3
  unsigned int varg_r1; // [sp+24h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+24h] [bp+Ch]
  int varg_r2; // [sp+28h] [bp+10h]
  va_list varg_r3; // [sp+2Ch] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r1;
  v3 = IoSetThreadHardErrorMode(0);
  if ( a1 )
  {
    if ( (a1[1] & 0x20) != 0 )
      return sub_7D02A0();
    v5 = *a1;
    if ( (*a1 & 0xC004) != 0 || (a1[4] & 0x40) != 0 || (v5 & 1) != 0 || (v5 & 2) != 0 || (a1[1] & 0x8000000) != 0 )
      EtwpProcessThreadImageRundown((int)a1, varg_r1, varg_r2);
    if ( (*a1 & 0x20000) != 0 || (a1[2] & 0x1000000) != 0 )
      CmEtwRunDown(varg_r1, (*a1 & 0x20000) != 0, (a1[2] & 0x1000000) != 0, varg_r2);
    if ( (a1[1] & 2) != 0 )
      EtwpSampledProfileRunDown(varg_r1, varg_r2, 1);
    if ( (a1[1] & 0x400) != 0 )
      EtwpSampledProfileRunDown(varg_r1, varg_r2, 0);
    if ( (a1[1] & 0x10000) != 0 )
      EtwpSpinLockConfigRunDown(varg_r1, varg_r2);
    if ( (a1[1] & 0x20000) != 0 )
      EtwpExecutiveResourceConfigRunDown(varg_r1, varg_r2);
    if ( (a1[1] & 0x400008) != 0 )
      MmPerfLogSessionRundown(varg_r1, varg_r2);
    if ( (a1[1] & 0x8000049) != 0 )
      EtwpPoolRunDown(varg_r1, varg_r2);
    if ( (a1[2] & 0x100000) != 0 )
      EtwpClockSourceRunDown(varg_r1, varg_r2);
  }
  if ( varg_r2 )
  {
    if ( a1 )
    {
      if ( (a1[1] & 0x8000000) != 0 )
      {
        MmIdentifyPhysicalMemory(varg_r1, 645, 1);
        MmLogSystemShareablePfnInfo(varg_r1);
      }
      if ( (a1[1] & 0x20) != 0 )
        EtwpLogRefSetAutoMark(varg_r2, varg_r1);
    }
  }
  else if ( a1 )
  {
    if ( (a1[1] & 0x8000000) != 0 )
    {
      MmLogSystemShareablePfnInfo(varg_r1);
      MmIdentifyPhysicalMemory(varg_r1, 645, 1);
    }
    if ( (a1[1] & 9) != 0 )
    {
      EtwpLogMemInfoRundown(varg_r1);
      MmIdentifyPhysicalMemory(varg_r1, 547, 0);
    }
    if ( (a1[1] & 0x80000) != 0 )
    {
      MmLogQueryCombineStats((unsigned int *)varg_r1a, 0);
      v1 = varg_r1;
    }
    if ( (*a1 & 0x200) != 0 )
      WmiTraceRundownNotify(v1);
    if ( (a1[4] & 0x8000) != 0 )
      PopExecuteOnTargetProcessors((int)&KeActiveProcessors, (int)PpmTracePerfIdleRundown, 0, 0);
    v6 = a1[4];
    if ( (v6 & 0x40) != 0 || (v6 & 0x80) != 0 )
      EtwpObjectTypeRundown(v1, 0);
    if ( (a1[2] & 0x10000) != 0 )
      EtwpProcessorRundown(v1);
  }
  return IoSetThreadHardErrorMode(v3);
}
