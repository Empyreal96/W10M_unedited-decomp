// VerifierIoAllocateWorkItem 
 
int __fastcall VerifierIoAllocateWorkItem(int a1)
{
  int v2; // [sp+4h] [bp-4h]

  return pXdvIoAllocateWorkItem(a1, v2, IovAllocateWorkItem);
}
