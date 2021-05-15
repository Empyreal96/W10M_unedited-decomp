// IopErrorLogConnectSession 
 
int __fastcall IopErrorLogConnectSession(int a1, int a2, int a3, int a4)
{
  _DWORD v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[1] = a3;
  v5[2] = a4;
  if ( ErrorLogSessionOpened )
    return 1;
  RtlInitUnicodeString((unsigned int)v5, L"Eventlog-System");
  if ( EtwQueryTraceHandleByLoggerName((int)v5, (int)&IopErrorLogSession) >= 0 )
  {
    ErrorLogSessionOpened = 1;
    return 1;
  }
  IopErrorLogQueueRequest();
  return 0;
}
