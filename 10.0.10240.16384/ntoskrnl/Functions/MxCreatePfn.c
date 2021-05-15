// MxCreatePfn 
 
int __fastcall MxCreatePfn(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r2
  char v8; // r3
  int result; // r0

  v6 = MmPfnDatabase + 24 * a1;
  if ( a4 == 1 )
    memset((_BYTE *)(MmPfnDatabase + 24 * a1), 0, 24);
  v7 = *(_DWORD *)(v6 + 12);
  *(_DWORD *)(v6 + 20) = *(_DWORD *)(v6 + 20) & 0xFFF00000 | a3 & 0xFFFFF;
  *(_WORD *)(v6 + 16) = 1;
  *(_DWORD *)(v6 + 4) = a2;
  *(_DWORD *)(v6 + 8) = 128;
  v8 = *(_BYTE *)(v6 + 18);
  *(_DWORD *)(v6 + 12) = v7 & 0xC0000000 | (v7 + 1) & 0x3FFFFFFF;
  *(_BYTE *)(v6 + 18) = v8 & 0x28 | 0x56;
  result = MiPageToNode();
  *(_DWORD *)(v6 + 20) = *(_DWORD *)(v6 + 20) & 0xFFFFFFF | (result << 28);
  return result;
}
