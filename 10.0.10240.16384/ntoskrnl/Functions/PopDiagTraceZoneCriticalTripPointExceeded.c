// PopDiagTraceZoneCriticalTripPointExceeded 
 
int __fastcall PopDiagTraceZoneCriticalTripPointExceeded(int result, int a2)
{
  int v3; // r7
  __int64 v4; // kr00_8
  int v5; // r5
  int v6; // r6

  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CRITICAL_TRIP_POINT_DIAGNOSTIC)
      || (result = EtwEventEnabled(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_CRITICAL_TRIP_POINT_SYSTEM)) != 0 )
    {
      result = IoGetDeviceAttachmentBaseRef(a2);
      v5 = result;
      if ( result )
        v6 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v6 = 0;
      if ( v6 )
      {
        PopDiagTraceTripPointExceeded(
          *(unsigned __int16 *)(v6 + 160) >> 1,
          *(_DWORD *)(v6 + 164),
          *(_DWORD *)(v3 + 28) / 0xAu,
          (int)POP_ETW_EVENT_CRITICAL_TRIP_POINT_DIAGNOSTIC);
        result = PopDiagTraceTripPointExceeded(
                   *(unsigned __int16 *)(v6 + 160) >> 1,
                   *(_DWORD *)(v6 + 164),
                   *(_DWORD *)(v3 + 28) / 0xAu,
                   (int)POP_ETW_EVENT_CRITICAL_TRIP_POINT_SYSTEM);
      }
      if ( v5 )
        result = ObfDereferenceObject(v5);
    }
  }
  return result;
}
