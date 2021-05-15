// PopDiagTraceEventNoPayload 
 
void __fastcall PopDiagTraceEventNoPayload(int result)
{
  if ( PopDiagHandleRegistered )
  {
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, result) )
      sub_50F76C();
  }
}
