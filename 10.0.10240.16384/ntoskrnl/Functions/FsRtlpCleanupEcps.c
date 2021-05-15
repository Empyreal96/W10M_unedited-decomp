// FsRtlpCleanupEcps 
 
int __fastcall FsRtlpCleanupEcps(int a1)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r6
  _DWORD *v4; // r2
  int v5; // r3
  __int64 v6; // r0

  if ( (*(_DWORD *)(a1 + 4) & 1) == 0 )
    return sub_806C44();
  v2 = (_DWORD *)(a1 + 8);
  v3 = *(_DWORD **)(a1 + 8);
  if ( v3 != (_DWORD *)(a1 + 8) )
  {
    do
    {
      v4 = v3 - 2;
      v5 = v3[7];
      v3 = (_DWORD *)*v3;
      if ( (v5 & 1) == 0 )
      {
        v6 = *((_QWORD *)v4 + 1);
        if ( *(_DWORD **)(v6 + 4) != v4 + 2 || *(_DWORD **)HIDWORD(v6) != v4 + 2 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v6) = v6;
        *(_DWORD *)(v6 + 4) = HIDWORD(v6);
        v4[2] = 0;
        v4[3] = 0;
        FsRtlFreeExtraCreateParameter(v4 + 13);
      }
    }
    while ( v3 != v2 );
  }
  return 0;
}
