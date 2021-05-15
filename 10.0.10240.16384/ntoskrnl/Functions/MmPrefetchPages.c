// MmPrefetchPages 
 
int __fastcall MmPrefetchPages(int a1, int a2)
{
  return MmPrefetchPagesEx(a1, a2, 0);
}
