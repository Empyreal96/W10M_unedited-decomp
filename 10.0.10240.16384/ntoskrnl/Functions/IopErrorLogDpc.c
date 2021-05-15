// IopErrorLogDpc 
 
int __fastcall IopErrorLogDpc(int a1)
{
  if ( a1 )
    ExFreePoolWithTag(a1);
  dword_630E28 = (int)IopErrorLogThread;
  dword_630E2C = 0;
  IopErrorLogWorkItem = 0;
  return ExQueueWorkItem(&IopErrorLogWorkItem, 1);
}
