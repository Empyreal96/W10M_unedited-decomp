// IopLiveDumpLockPages 
 
int __fastcall IopLiveDumpLockPages(int a1, int a2, int a3)
{
  return MiLockPagableImageSection(ExPageLockHandle, 1, a3, (int)&ExPageLockHandle);
}
