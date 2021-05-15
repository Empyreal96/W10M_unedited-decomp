// ExpFastCacheDescriptorCompare 
 
int __fastcall ExpFastCacheDescriptorCompare(int a1, int a2)
{
  return memcmp(*(_DWORD *)(a1 + 4), *(_DWORD *)(a2 + 4), 32);
}
