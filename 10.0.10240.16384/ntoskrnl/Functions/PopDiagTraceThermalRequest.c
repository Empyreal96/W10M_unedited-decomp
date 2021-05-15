// PopDiagTraceThermalRequest 
 
void __fastcall PopDiagTraceThermalRequest(int a1, int a2)
{
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, a2) )
      sub_81A97C();
  }
}
