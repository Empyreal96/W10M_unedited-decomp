// MmLockPagableSectionByHandle 
 
int __fastcall MmLockPagableSectionByHandle(int a1, int a2, int a3, int a4)
{
  return MiLockPagableImageSection(a1, 1, a3, a4);
}
