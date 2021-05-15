// EtwpUpdateKernelGroupsWork 
 
int __fastcall EtwpUpdateKernelGroupsWork(unsigned int a1)
{
  ExFreePoolWithTag(a1);
  return EtwpUpdateKernelGroupMasks(0, 8);
}
