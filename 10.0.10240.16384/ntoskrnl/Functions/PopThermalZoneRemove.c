// PopThermalZoneRemove 
 
int __fastcall PopThermalZoneRemove(int a1)
{
  __int64 v2; // r0
  int result; // r0

  *(_BYTE *)(a1 + 34) = 1;
  IoCancelIrp(*(_DWORD *)(a1 + 28));
  KeWaitForSingleObject(a1 + 328, 0, 0, 0, 0);
  LODWORD(v2) = a1 + 368;
  HIDWORD(v2) = (unsigned __int8)*(_DWORD *)(a1 + 48);
  PopThermalUpdatePassiveTimeTracking(v2);
  PopTraceThermalZonePassiveHistogram(a1);
  if ( *(_BYTE *)(a1 + 40) )
  {
    PopDiagTraceThermalStandbyState(*(_DWORD *)(a1 + 24));
    PopAcquirePolicyLock();
    if ( !--dword_61E4A4 && byte_61E4A1 == 1 )
    {
      PopThermalStandbyNotify(0);
      byte_61E4A1 = 0;
    }
    PopReleasePolicyLock();
  }
  if ( *(_BYTE *)(a1 + 41) )
    PopUpdateOverThrottledCount(a1);
  KeCancelTimer(a1 + 80);
  KeFlushQueuedDpcs();
  *(_BYTE *)(a1 + 33) |= 0x80u;
  if ( !--PopThermalZoneCount )
  {
    PopAcquirePolicyLock();
    if ( byte_61EA4D )
    {
      byte_61EA4D = 0;
      PopResetCurrentPolicies();
    }
    PopReleasePolicyLock();
  }
  result = PopThermalUpdateTelemetryClientCount(0);
  if ( (PoDebug & 0x20) != 0 )
    result = DbgPrint("Thermal Zone %p: going away\n", (const void *)a1);
  return result;
}
