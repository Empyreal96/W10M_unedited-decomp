// PopSetDisplayStatus 
 
int __fastcall PopSetDisplayStatus(int a1)
{
  int v2; // r4
  int v3; // r0

  v2 = PsGetProcessSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  PopAcquireAdaptiveLock(1);
  v3 = PopSetSessionDisplayStatus(v2, a1, 1);
  return PopReleaseAdaptiveLock(v3);
}
