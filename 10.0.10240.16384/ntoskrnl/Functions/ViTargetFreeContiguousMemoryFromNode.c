// ViTargetFreeContiguousMemoryFromNode 
 
int __fastcall ViTargetFreeContiguousMemoryFromNode(int a1, int a2)
{
  int v2; // r1
  _DWORD *i; // r0
  __int64 v6; // kr00_8

  v2 = *(_DWORD *)(a2 + 24);
  if ( v2 )
  {
    for ( i = *(_DWORD **)(v2 + 136); i != (_DWORD *)(v2 + 136); i = (_DWORD *)*i )
    {
      if ( i[2] == a1 )
      {
        v6 = *(_QWORD *)i;
        if ( *(_DWORD **)(*i + 4) != i || *(_DWORD **)HIDWORD(v6) != i )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v6) = v6;
        *(_DWORD *)(v6 + 4) = HIDWORD(v6);
        *(_DWORD *)(v2 + 128) -= i[3];
        VfPoolDelayFreeIfPossible((int)i, 0);
        return 1;
      }
    }
  }
  return 0;
}
