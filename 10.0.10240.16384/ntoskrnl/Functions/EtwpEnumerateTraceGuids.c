// EtwpEnumerateTraceGuids 
 
int __fastcall EtwpEnumerateTraceGuids(int a1, _DWORD *a2)
{
  __int64 v3; // kr00_8
  int v4; // r8
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r8
  int v8; // r3
  int v9; // r4
  int v10; // r5

  v3 = 954437177i64 * (unsigned int)*a2;
  v4 = 0;
  v5 = 0;
  v6 = EtwpGetNextGuidEntry(0, 0);
  if ( v6 )
  {
    v7 = a1;
    do
    {
      if ( ++v5 <= HIDWORD(v3) >> 3 )
      {
        v8 = *(_DWORD *)(v6 + 16);
        v9 = *(_DWORD *)(v6 + 20);
        v10 = *(_DWORD *)(v6 + 24);
        *(_DWORD *)v7 = *(_DWORD *)(v6 + 12);
        *(_DWORD *)(v7 + 4) = v8;
        *(_DWORD *)(v7 + 8) = v9;
        *(_DWORD *)(v7 + 12) = v10;
        *(_DWORD *)(v7 + 28) = *(_DWORD *)(v6 + 40);
        *(_DWORD *)(v7 + 20) = *(unsigned __int16 *)(v6 + 48);
        *(_DWORD *)(v7 + 24) = *(unsigned __int8 *)(v6 + 50);
        *(_BYTE *)(v7 + 32) = *(_BYTE *)(v6 + 51) & 1;
        v7 += 36;
      }
      v6 = EtwpGetNextGuidEntry((_DWORD *)v6, 0);
    }
    while ( v6 );
    v4 = 0;
  }
  *a2 = 36 * v5;
  if ( v5 > HIDWORD(v3) >> 3 )
    v4 = -1073741789;
  return v4;
}
