// sub_80E7C0 
 
void sub_80E7C0()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r0
  int *v3; // r1
  int v4; // r2

  v2 = RtlpCopyRangeListEntry(v1);
  if ( v2 )
  {
    v3 = (int *)v0[1];
    v4 = v2 + 28;
    *(_DWORD *)(v2 + 28) = v0;
    *(_DWORD *)(v2 + 32) = v3;
    if ( (_DWORD *)*v3 == v0 )
    {
      *v3 = v4;
      v0[1] = v4;
      JUMPOUT(0x79796E);
    }
    __fastfail(3u);
  }
  RtlFreeRangeList(v0);
  JUMPOUT(0x79797E);
}
