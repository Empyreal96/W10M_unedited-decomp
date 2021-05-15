// CcFlushCacheToLsn 
 
int __fastcall CcFlushCacheToLsn(int a1, _DWORD *a2, int a3)
{
  return CcFlushCachePriv(a1, 0, 0, a2, 0, a3);
}
