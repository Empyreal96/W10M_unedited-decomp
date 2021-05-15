// ExUnlockUserBuffer 
 
int __fastcall ExUnlockUserBuffer(int a1)
{
  MmUnlockPages(a1);
  return ExFreePoolWithTag(a1, 0);
}
