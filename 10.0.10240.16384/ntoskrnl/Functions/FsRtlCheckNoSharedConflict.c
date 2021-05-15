// FsRtlCheckNoSharedConflict 
 
BOOL __fastcall FsRtlCheckNoSharedConflict(int a1, unsigned __int64 *a2, _DWORD *a3, int a4)
{
  int v7; // r4
  __int64 v8; // r0
  int v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = (int)a3;
  v10[1] = a4;
  v7 = FsRtlFindFirstOverlappingSharedNode(*(_DWORD *)(a1 + 4), a2, a3, v10, 0);
  LODWORD(v8) = v10[0];
  if ( v10[0] )
    *(_DWORD *)(a1 + 4) = RtlSplay(v8);
  return !v7 || *(_BYTE *)(v7 - 12) && !FsRtlFindFirstOverlapInNode(v7 - 16, a2, a3);
}
