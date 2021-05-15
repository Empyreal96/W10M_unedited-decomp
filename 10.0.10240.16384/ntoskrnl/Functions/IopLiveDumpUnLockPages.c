// IopLiveDumpUnLockPages 
 
int __fastcall IopLiveDumpUnLockPages(int a1, int a2, int a3)
{
  return MiLockPagableImageSection(ExPageLockHandle, 0, a3, (int)&ExPageLockHandle);
}
