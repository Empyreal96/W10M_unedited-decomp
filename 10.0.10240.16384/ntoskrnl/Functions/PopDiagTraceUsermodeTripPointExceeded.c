// PopDiagTraceUsermodeTripPointExceeded 
 
int __fastcall PopDiagTraceUsermodeTripPointExceeded(int a1, int a2, int a3, int a4)
{
  int *v7; // r3

  if ( a4 )
  {
    PopDiagTraceTripPointExceeded(a1, a2, a3, (int)POP_ETW_EVENT_CRITICAL_TRIP_POINT_DIAGNOSTIC);
    v7 = POP_ETW_EVENT_CRITICAL_TRIP_POINT_SYSTEM;
  }
  else
  {
    PopDiagTraceTripPointExceeded(a1, a2, a3, (int)POP_ETW_EVENT_S4_TRIP_POINT_DIAGNOSTIC);
    v7 = POP_ETW_EVENT_S4_TRIP_POINT_SYSTEM;
  }
  return PopDiagTraceTripPointExceeded(a1, a2, a3, (int)v7);
}
