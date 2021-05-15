// MmUnlockPagableImageSection 
 
int __fastcall MmUnlockPagableImageSection(int a1)
{
  return MiLockPagableImageSection(a1, 0);
}
