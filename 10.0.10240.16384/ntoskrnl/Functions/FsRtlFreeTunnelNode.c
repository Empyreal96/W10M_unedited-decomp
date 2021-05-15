// FsRtlFreeTunnelNode 
 
int __fastcall FsRtlFreeTunnelNode(__int64 a1)
{
  int v1; // r2
  int v2; // r2

  v1 = a1;
  if ( HIDWORD(a1) )
  {
    LODWORD(a1) = *(_DWORD *)HIDWORD(a1);
    *(_QWORD *)(v1 + 12) = a1;
    v2 = v1 + 12;
    if ( *(_DWORD *)(a1 + 4) != HIDWORD(a1) )
      __fastfail(3u);
    *(_DWORD *)(a1 + 4) = v2;
    *(_DWORD *)HIDWORD(a1) = v2;
  }
  else if ( (*(_DWORD *)(a1 + 40) & 1) != 0 )
  {
    LODWORD(a1) = ExFreePoolWithTag(a1);
  }
  else
  {
    LODWORD(a1) = ExFreeToPagedLookasideList((int)&TunnelLookasideList, (_DWORD *)a1);
  }
  return a1;
}
