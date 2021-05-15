// sub_80E72C 
 
void __fastcall sub_80E72C(int a1)
{
  int v1; // r7
  unsigned int v2; // r8
  unsigned int v3; // lr
  __int64 v4; // r2
  __int64 v5; // kr08_8

  LODWORD(v4) = *(_DWORD *)(a1 + 12);
  HIDWORD(v4) = *(_DWORD *)(a1 + 8);
  if ( v4 == __PAIR64__(v2, v3) && *(_DWORD *)(a1 + 20) == v1 )
  {
    v5 = *(_QWORD *)(a1 + 28);
    if ( *(_DWORD *)(v5 + 4) == a1 + 28 && *(_DWORD *)HIDWORD(v5) == a1 + 28 )
    {
      *(_DWORD *)HIDWORD(v5) = v5;
      *(_DWORD *)(v5 + 4) = HIDWORD(v5);
      RtlpFreeRangeListEntry(a1);
      JUMPOUT(0x7977EA);
    }
    __fastfail(3u);
  }
  JUMPOUT(0x797790);
}
