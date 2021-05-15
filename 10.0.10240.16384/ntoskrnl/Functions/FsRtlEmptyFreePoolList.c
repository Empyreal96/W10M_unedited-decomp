// FsRtlEmptyFreePoolList 
 
int __fastcall FsRtlEmptyFreePoolList(int result)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r2
  __int64 v3; // r0

  v1 = (_DWORD *)result;
  while ( 1 )
  {
    v2 = (_DWORD *)*v1;
    if ( (_DWORD *)*v1 == v1 )
      break;
    v3 = *(_QWORD *)v2;
    if ( *(_DWORD **)(*v2 + 4) != v2 || *(_DWORD **)HIDWORD(v3) != v2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    result = FsRtlFreeTunnelNode(v2 - 3, 0);
  }
  return result;
}
