// EtwpEventWriteTemplateSessionEnd 
 
int __fastcall EtwpEventWriteTemplateSessionEnd(int a1, int a2, int a3, int a4)
{
  return EtwWrite(a1, a2, (int)ETW_EVENT_SESSION_END_FAILED, 0);
}
