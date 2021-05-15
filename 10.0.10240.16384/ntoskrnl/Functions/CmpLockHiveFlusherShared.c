// CmpLockHiveFlusherShared 
 
int __fastcall CmpLockHiveFlusherShared(int a1)
{
  return ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 1872), 1);
}
