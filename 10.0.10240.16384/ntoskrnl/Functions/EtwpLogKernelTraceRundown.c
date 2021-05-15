// EtwpLogKernelTraceRundown 
 
int __fastcall EtwpLogKernelTraceRundown(int a1, int *a2, int a3)
{
  EtwpLogGroupMask(a1, a2, 32);
  EtwpKernelTraceRundown(a2, a1, a3);
  return EtwpLogAlwaysPresentRundown(a1);
}
