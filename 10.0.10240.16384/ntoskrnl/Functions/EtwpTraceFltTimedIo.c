// EtwpTraceFltTimedIo 
 
int __fastcall EtwpTraceFltTimedIo(int a1, int a2, unsigned int a3, int a4, int a5)
{
  return EtwTraceTimedEvent(a4, a3, a1, a2, 4200451, a5);
}
