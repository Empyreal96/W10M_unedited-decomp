// CmpSyncKcbCacheForHive 
 
int __fastcall CmpSyncKcbCacheForHive(int a1, int a2, int a3)
{
  int v4; // r3

  if ( a2 && *(_DWORD *)(a1 + 20) != a2 )
    return 0;
  if ( (*(_DWORD *)(a1 + 4) & 0x20000) != 0 )
    return 0;
  if ( !*(_DWORD *)(a1 + 20) )
    return 0;
  v4 = *(unsigned __int16 *)(a1 + 106);
  if ( (v4 & 0x10) != 0 || CmpRebuildKcbCache(a1, a2, a3, v4) )
    return 0;
  CmpFlushNotifiesOnKeyBodyList(a1);
  CmpMarkKcbDeleted((_DWORD *)a1);
  *(_DWORD *)(a1 + 24) = 0;
  return 2;
}
