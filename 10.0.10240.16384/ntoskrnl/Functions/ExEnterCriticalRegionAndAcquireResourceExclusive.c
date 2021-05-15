// ExEnterCriticalRegionAndAcquireResourceExclusive 
 
int __fastcall ExEnterCriticalRegionAndAcquireResourceExclusive(int a1)
{
  unsigned int v1; // r3
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  ExAcquireResourceExclusiveLite(a1, 1);
  result = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x11C);
  __dmb(0xBu);
  return result;
}
