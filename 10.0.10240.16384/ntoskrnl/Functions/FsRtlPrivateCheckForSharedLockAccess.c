// FsRtlPrivateCheckForSharedLockAccess 
 
int __fastcall FsRtlPrivateCheckForSharedLockAccess(int a1, int a2, int a3, int a4)
{
  int v5; // r0

  v5 = *(_DWORD *)(a1 + 8);
  if ( !v5 )
    return 1;
  if ( !FsRtlFindFirstOverlappingExclusiveNode(v5, a2, a2 + 32) )
  {
    if ( a4 )
      *(_DWORD *)(a1 + 8) = RtlSplay(a4);
    return 1;
  }
  return sub_51E2E0();
}
