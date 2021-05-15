// ExAllocatePoolEx 
 
int __fastcall ExAllocatePoolEx(int a1, int a2, int a3)
{
  return ExAllocatePoolWithTag(a1, a2, a3);
}
