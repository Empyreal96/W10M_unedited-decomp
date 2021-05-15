// PopDiagTraceThermalCoolingMode 
 
void PopDiagTraceThermalCoolingMode()
{
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COOLING_MODE) )
      sub_8150C0();
  }
}
