// PopDiagTraceEventNoPayload 
 
int __fastcall PopDiagTraceEventNoPayload(int result)
{
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, result);
    if ( result )
      result = sub_50F76C();
  }
  return result;
}
