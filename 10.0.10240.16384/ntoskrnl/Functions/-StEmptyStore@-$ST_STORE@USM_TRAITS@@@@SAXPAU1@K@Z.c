// -StEmptyStore@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@K@Z 
 
unsigned int __fastcall ST_STORE<SM_TRAITS>::StEmptyStore(int a1, int a2)
{
  int v4; // r0
  unsigned int result; // r0

  if ( (dword_636E9C & 0x10) != 0 )
    SmEtwLogStoreStateChange(&unk_636E90, a2, a1, a2);
  if ( *(_DWORD *)(a1 + 3272) )
  {
    v4 = *(_DWORD *)(a1 + 816);
    *(_DWORD *)(a1 + 3272) = 0;
    ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(v4, 5, 0xFFFFFFFF, 0xFFFFFFFF);
  }
  result = ST_STORE<SM_TRAITS>::StDmCleanup(a1 + 56, 1);
  if ( a2 )
    result = ST_STORE<SM_TRAITS>::StDmCleanup(a1 + 824, 1);
  return result;
}
