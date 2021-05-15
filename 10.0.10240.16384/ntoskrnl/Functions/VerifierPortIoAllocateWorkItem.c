// VerifierPortIoAllocateWorkItem 
 
int __fastcall VerifierPortIoAllocateWorkItem(int a1, int a2)
{
  return pXdvIoAllocateWorkItem(a1, a2, IovAllocateWorkItem);
}
