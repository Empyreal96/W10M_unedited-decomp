// sub_8069B0 
 
void sub_8069B0()
{
  int v0; // r4
  int v1; // r7
  __int64 v2; // r0
  int v3; // r0
  __int64 v4; // kr00_8

  v2 = *(_QWORD *)(v0 + 16);
  if ( *(_DWORD *)(v2 + 4) == v0 + 16 && *(_DWORD *)HIDWORD(v2) == v0 + 16 )
  {
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    v3 = KfRaiseIrql(1);
    v4 = *(_QWORD *)(v0 + 8);
    if ( *(_DWORD *)(v4 + 4) == v0 + 8 && *(_DWORD *)HIDWORD(v4) == v0 + 8 )
    {
      *(_DWORD *)HIDWORD(v4) = v4;
      *(_DWORD *)(v4 + 4) = HIDWORD(v4);
      KfLowerIrql(v3);
      if ( *(_DWORD *)(v0 + 28) != 1 )
      {
        CmpAddToDelayedDeref(v0, v1);
        CmpFreePostBlock((_DWORD *)v0);
        JUMPOUT(0x754AD6);
      }
      JUMPOUT(0x754A2E);
    }
    __fastfail(3u);
  }
  __fastfail(3u);
}
