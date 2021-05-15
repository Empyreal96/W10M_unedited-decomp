// PpmWmiIdleAccountingWork 
 
int __fastcall PpmWmiIdleAccountingWork(unsigned int a1)
{
  ExFreePoolWithTag(a1);
  return PopExecuteOnTargetProcessors((int)&KeActiveProcessors, (int)PpmWmiFireIdleAccountingEvent, 0, 0);
}
