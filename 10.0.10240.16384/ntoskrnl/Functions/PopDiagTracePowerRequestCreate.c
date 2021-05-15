// PopDiagTracePowerRequestCreate 
 
int __fastcall PopDiagTracePowerRequestCreate(int result)
{
  int *v1; // r2

  if ( PopDiagHandleRegistered )
  {
    if ( result )
      v1 = POP_ETW_EVENT_POWER_REQUEST_RUNDOWN;
    else
      v1 = POP_ETW_EVENT_CREATE_POWER_REQUEST;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v1);
    if ( result )
      result = sub_7F2D84();
  }
  return result;
}
