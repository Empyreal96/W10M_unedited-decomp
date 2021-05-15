// sub_7EEF50 
 
void sub_7EEF50()
{
  __int64 v0; // r4
  int v1; // r6
  __int64 v2; // r2
  int v3; // r0

  HIDWORD(v0) = *(_DWORD *)v0;
  v2 = *(_QWORD *)*(_DWORD *)v0;
  if ( __PAIR64__(*(_DWORD *)(v2 + 4), HIDWORD(v2)) == v0 )
  {
    *(_DWORD *)v0 = v2;
    *(_DWORD *)(v2 + 4) = v0;
    --*(_DWORD *)(v1 + 264);
    v3 = *(_DWORD *)(HIDWORD(v0) + 24);
    *(_BYTE *)(HIDWORD(v0) + 50) |= 4u;
    KeSetEvent(v3, 0, 0);
    ObfDereferenceObject(SHIDWORD(v0));
    JUMPOUT(0x7812F2);
  }
  __fastfail(3u);
}
