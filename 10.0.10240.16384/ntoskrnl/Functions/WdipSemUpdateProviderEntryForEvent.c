// WdipSemUpdateProviderEntryForEvent 
 
int __fastcall WdipSemUpdateProviderEntryForEvent(int result, int a2)
{
  int v2; // r4
  unsigned int v3; // r5
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r1
  __int64 v9; // r5
  int v10; // r2
  int v11; // r3

  v2 = *(_DWORD *)(result + 40);
  v3 = *(unsigned __int8 *)(v2 + 16);
  v4 = *(_DWORD *)(v2 + 32);
  if ( *(unsigned __int8 *)(result + 18) > v3 )
    LOBYTE(v3) = *(_BYTE *)(result + 18);
  v5 = *(_DWORD *)(result + 36);
  *(_QWORD *)(v2 + 24) |= *(_QWORD *)(result + 24);
  *(_BYTE *)(v2 + 16) = v3;
  v6 = v4 | v5;
  v7 = *(_DWORD *)(v2 + 40);
  *(_DWORD *)(v2 + 32) = v6;
  *(_DWORD *)(v2 + 40) = v7 + 1;
  *(_BYTE *)(v2 + 36) |= 1u;
  if ( a2 )
  {
    v8 = *(unsigned __int8 *)(v2 + 48);
    v10 = *(_DWORD *)(v2 + 64);
    if ( *(unsigned __int8 *)(result + 18) > v8 )
      LOBYTE(v8) = *(_BYTE *)(result + 18);
    v11 = *(_DWORD *)(result + 36);
    LODWORD(v9) = *(_DWORD *)(v2 + 56) | *(_DWORD *)(result + 24);
    HIDWORD(v9) = *(_DWORD *)(v2 + 60) | *(_DWORD *)(result + 28);
    *(_QWORD *)(v2 + 56) = v9;
    *(_BYTE *)(v2 + 48) = v8;
    *(_DWORD *)(v2 + 64) = v11 | v10;
    *(_BYTE *)(v2 + 68) |= 1u;
  }
  return result;
}
