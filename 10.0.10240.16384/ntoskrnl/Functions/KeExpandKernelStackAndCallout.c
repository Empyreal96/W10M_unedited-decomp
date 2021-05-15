// KeExpandKernelStackAndCallout 
 
int __fastcall KeExpandKernelStackAndCallout(int (__fastcall *a1)(int), int a2, int a3)
{
  return KeExpandKernelStackAndCalloutInternal(a1, a2, a3, 2);
}
