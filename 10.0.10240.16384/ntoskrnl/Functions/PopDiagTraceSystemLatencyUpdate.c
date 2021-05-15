// PopDiagTraceSystemLatencyUpdate 
 
int __fastcall PopDiagTraceSystemLatencyUpdate(int result, int a2)
{
  int *v2; // r2
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    if ( result )
      v2 = POP_ETW_EVENT_SYSTEM_LATENCY_RUNDOWN;
    else
      v2 = POP_ETW_EVENT_SYSTEM_LATENCY_UPDATE;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, v2);
    if ( result )
      result = sub_529A1C();
  }
  return result;
}
