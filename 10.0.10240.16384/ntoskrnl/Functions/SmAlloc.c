// SmAlloc 
 
int __fastcall SmAlloc(int a1, int a2)
{
  return ExAllocatePoolWithTag(512, a1, a2);
}
