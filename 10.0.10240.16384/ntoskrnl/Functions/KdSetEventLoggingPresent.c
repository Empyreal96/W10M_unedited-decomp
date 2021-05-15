// KdSetEventLoggingPresent 
 
char __fastcall KdSetEventLoggingPresent(char result)
{
  KdEventLoggingPresent = result;
  return result;
}
