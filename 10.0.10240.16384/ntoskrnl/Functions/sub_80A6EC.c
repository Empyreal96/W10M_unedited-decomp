// sub_80A6EC 
 
void sub_80A6EC()
{
  int v0; // r7
  _DWORD *v1; // r8
  int v2; // r10
  _DWORD *v3; // r9
  int v4; // r3

  v3 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  *(_WORD *)(v0 + 76) = v2 + 32;
  *(_WORD *)(v0 + 78) = 0;
  *(_DWORD *)(v0 + 72) = -1073676286;
  *(_DWORD *)(v0 + 80) = v3[220];
  *(_DWORD *)(v0 + 84) = v3[219];
  *(_DWORD *)(v0 + 96) = v3[101];
  *(_DWORD *)(v0 + 100) = v3[112];
  *(_DWORD *)(v0 + 88) = v1[60];
  *(_DWORD *)(v0 + 92) = v1[61];
  memset((_BYTE *)(v0 + 104), 0, v2);
  v4 = v1[1];
  *(_BYTE *)(v0 + 109) = 0;
  *(_DWORD *)(v0 + 104) = v4;
  *(_BYTE *)(v0 + 108) = 10;
  *(_DWORD *)(v0 + 112) = 10240;
  JUMPOUT(0x76011C);
}
