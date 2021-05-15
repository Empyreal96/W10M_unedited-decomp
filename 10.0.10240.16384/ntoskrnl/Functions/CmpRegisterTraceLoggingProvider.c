// CmpRegisterTraceLoggingProvider 
 
int __fastcall CmpRegisterTraceLoggingProvider(int a1, __int64 a2)
{
  LODWORD(a2) = 0;
  return TraceLoggingRegisterEx((int)&dword_616398, a2);
}
