// LockRMLog 
 
int __fastcall LockRMLog(int a1)
{
  int v1; // r2
  int v2; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(__int16 *)(v1 + 0x134) - 1;
  *(_WORD *)(v1 + 308) = v2;
  return ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 80), 1, v1, v2);
}
