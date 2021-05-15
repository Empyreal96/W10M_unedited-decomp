// CmpTryAcquireIXLockExclusive 
 
BOOL __fastcall CmpTryAcquireIXLockExclusive(_DWORD *a1)
{
  return *a1 == 0;
}
