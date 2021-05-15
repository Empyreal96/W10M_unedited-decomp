// TraceLoggingRegister 
 
int __fastcall TraceLoggingRegister(int a1, __int64 a2)
{
  LODWORD(a2) = 0;
  return TraceLoggingRegisterEx(a1, a2);
}
