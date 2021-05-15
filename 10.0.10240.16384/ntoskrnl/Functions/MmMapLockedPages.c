// MmMapLockedPages 
 
int __fastcall MmMapLockedPages(int a1, char a2)
{
  return MmMapLockedPagesSpecifyCache(a1, a2, 1, 0, 1, 32);
}
