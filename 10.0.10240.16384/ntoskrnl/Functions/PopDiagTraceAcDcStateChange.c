// PopDiagTraceAcDcStateChange 
 
void PopDiagTraceAcDcStateChange()
{
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_ACDC_STATE_CHANGE) )
      sub_81C940();
  }
}
