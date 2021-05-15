// PoTraceSystemTimerResolutionUpdate 
 
int __fastcall PoTraceSystemTimerResolutionUpdate(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_TIME_RESOLUTION_UPDATE);
    if ( result )
      result = sub_555AB4();
  }
  return result;
}
