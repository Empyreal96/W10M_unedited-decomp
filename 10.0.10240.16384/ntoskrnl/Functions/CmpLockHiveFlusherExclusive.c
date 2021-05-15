// CmpLockHiveFlusherExclusive 
 
int __fastcall CmpLockHiveFlusherExclusive(int a1, int a2, int a3, int a4)
{
  return ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 1872), 1, a3, a4);
}
