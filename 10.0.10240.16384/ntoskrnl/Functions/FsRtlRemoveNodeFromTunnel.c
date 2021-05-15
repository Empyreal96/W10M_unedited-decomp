// FsRtlRemoveNodeFromTunnel 
 
int __fastcall FsRtlRemoveNodeFromTunnel(int a1, unsigned int a2, unsigned int a3, _BYTE *a4)
{
  int v8; // r0
  __int64 v9; // r0

  if ( a4 && *a4 )
  {
    v8 = RtlDelete((_DWORD *)a2);
    *a4 = 0;
    *(_DWORD *)(a1 + 32) = v8;
  }
  else
  {
    RtlDeleteNoSplay((_DWORD *)a2, (_DWORD *)(a1 + 32));
  }
  v9 = *(_QWORD *)(a2 + 12);
  if ( *(_DWORD *)(v9 + 4) != a2 + 12 || *(_DWORD *)HIDWORD(v9) != a2 + 12 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v9) = v9;
  *(_DWORD *)(v9 + 4) = HIDWORD(v9);
  --*(_WORD *)(a1 + 44);
  return FsRtlFreeTunnelNode(__SPAIR64__(a3, a2));
}
