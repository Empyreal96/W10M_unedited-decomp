// IoEnqueueIrp 
 
int __fastcall IoEnqueueIrp(int a1)
{
  return IopQueueThreadIrp(a1);
}
