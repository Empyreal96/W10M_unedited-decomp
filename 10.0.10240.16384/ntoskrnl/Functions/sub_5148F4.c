// sub_5148F4 
 
void __fastcall sub_5148F4(int a1, __int64 *a2)
{
  int v2; // r4
  __int16 v3; // r6
  __int64 v4; // kr00_8
  int v5; // r3

  v4 = *a2;
  if ( *(__int64 **)(*(_DWORD *)a2 + 4) == a2 && *(__int64 **)HIDWORD(v4) == a2 )
  {
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    RtlpFreeAtom(a2);
    if ( (*(_WORD *)(v2 + 22) & 1) == 0 )
    {
      v5 = (unsigned __int16)(*(_WORD *)(v2 + 20) + v3);
      *(_WORD *)(v2 + 20) = v5;
      if ( !v5 )
        JUMPOUT(0x43180A);
    }
    JUMPOUT(0x4317FA);
  }
  __fastfail(3u);
}
