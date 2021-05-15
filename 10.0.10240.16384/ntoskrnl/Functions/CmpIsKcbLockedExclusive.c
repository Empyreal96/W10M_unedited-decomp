// CmpIsKcbLockedExclusive 
 
BOOL __fastcall CmpIsKcbLockedExclusive(int a1)
{
  return *(_DWORD *)(a1 + 32) == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
}
