// NtQueueApcThread 
 
int __fastcall NtQueueApcThread(int a1, int a2, int a3)
{
  return NtQueueApcThreadEx(a1, 0, a2, a3);
}
