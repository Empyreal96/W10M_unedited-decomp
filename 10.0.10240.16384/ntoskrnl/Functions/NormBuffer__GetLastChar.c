// NormBuffer__GetLastChar 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall NormBuffer__GetLastChar(int a1)
{
  int v2; // r1
  int v3; // r2 OVERLAPPED
  int v4; // r1 OVERLAPPED
  int v5; // r5
  unsigned int v6; // r0
  char v7; // r0
  char v8; // r3

  v2 = *(_DWORD *)(a1 + 20);
  if ( *(_DWORD *)(a1 + 36) != v2 - 2 )
  {
    v3 = v2 - 2;
    v4 = *(unsigned __int16 *)(v2 - 2);
    *(_QWORD *)(a1 + 32) = *(_QWORD *)&v4;
    if ( v4 > 56320 && v4 <= 57343 )
      *(_DWORD *)(a1 + 32) = v4 + ((*(unsigned __int16 *)(v3 - 2) - 55287) << 10);
    v5 = *(_DWORD *)(a1 + 68);
    v6 = Normalization__PageLookup(v5, *(_DWORD *)(a1 + 32));
    if ( v6 && v6 < 0xFB )
    {
      v7 = Normalization__TableLookup(v5);
      *(_BYTE *)(a1 + 40) = v7 & 0x3F;
      v8 = v7 & 0xC0;
    }
    else
    {
      v8 = 0;
      *(_BYTE *)(a1 + 40) = 0;
    }
    *(_BYTE *)(a1 + 41) = v8;
  }
  return *(_DWORD *)(a1 + 32);
}
