// EtwQueryTraceHandleByLoggerName 
 
int __fastcall EtwQueryTraceHandleByLoggerName(int a1, int a2)
{
  if ( !a1 || !*(_DWORD *)(a1 + 4) || !*(_WORD *)a1 || !a2 )
    return -1073741811;
  if ( EtwpAcquireLoggerContextByLoggerName((unsigned __int16 *)a1, 0) )
    return sub_7D0E8C();
  return -1073741162;
}
