// EtwpLogFileNameRundown 
 
int __fastcall EtwpLogFileNameRundown(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = EtwpCheckGuidAccess((int)FileProvGuid, 128, 0, a4);
  if ( result >= 0 )
  {
    result = WmiTraceRundownNotify(a1);
    if ( result >= 0 )
      result = 0;
  }
  return result;
}
