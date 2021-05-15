// FsRtlpRestoreCallerEcpsToCallerList 
 
int __fastcall FsRtlpRestoreCallerEcpsToCallerList(int a1, int a2)
{
  _DWORD *v2; // r2
  _DWORD *v3; // r5
  int v4; // r3
  _DWORD *v5; // r0
  __int64 v6; // kr00_8
  _DWORD *v7; // r5

  if ( (*(_DWORD *)(a2 + 4) & 1) != 0 )
  {
    v2 = *(_DWORD **)(a2 + 8);
    while ( v2 != (_DWORD *)(a2 + 8) )
    {
      v3 = v2 - 2;
      v4 = v2[7];
      v2 = (_DWORD *)*v2;
      if ( (v4 & 1) != 0 )
      {
        v5 = v3 + 2;
        v6 = *((_QWORD *)v3 + 1);
        if ( *(_DWORD **)(v6 + 4) != v3 + 2 || *(_DWORD **)HIDWORD(v6) != v5 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v6) = v6;
        *(_DWORD *)(v6 + 4) = HIDWORD(v6);
        v3[2] = 0;
        v3[3] = 0;
        v7 = (_DWORD *)MEMORY[0xC];
        *v5 = 8;
        v5[1] = v7;
        if ( *v7 != 8 )
          __fastfail(3u);
        *v7 = v5;
        MEMORY[0xC] = v5;
      }
    }
  }
  FsRtlFreeExtraCreateParameterList(a2);
  return 0;
}
