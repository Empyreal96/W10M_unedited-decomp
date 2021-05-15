// ExEnterPriorityRegionAndAcquireResourceExclusive 
 
int __fastcall ExEnterPriorityRegionAndAcquireResourceExclusive(int a1)
{
  unsigned int v2; // r5
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PsBoostThreadIoEx(v2, 0, 0);
  --*(_WORD *)(v2 + 308);
  ExAcquireResourceExclusiveLite(a1, 1);
  result = *(_DWORD *)(v2 + 284);
  __dmb(0xBu);
  return result;
}
