// EtwpCheckSystemTraceAccess 
 
int __fastcall EtwpCheckSystemTraceAccess(int a1, int a2)
{
  int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 608);
  if ( (v2 & 0x20) != 0 )
    result = EtwpCheckLoggerControlAccess(a2, a1);
  else
    result = EtwpCheckGuidAccess((int)SystemTraceControlGuid, a2, 0, v2);
  return result;
}
