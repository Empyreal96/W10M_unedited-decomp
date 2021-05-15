// RtlpUnwindHandler 
 
int __fastcall RtlpUnwindHandler(int a1, int a2, int a3, int a4)
{
  int v4; // r0

  v4 = *(_DWORD *)(a2 - 8);
  *(_DWORD *)a4 = *(_DWORD *)v4;
  *(_DWORD *)(a4 + 4) = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(a4 + 8) = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(a4 + 12) = *(_DWORD *)(v4 + 12);
  *(_DWORD *)(a4 + 20) = *(_DWORD *)(v4 + 20);
  *(_DWORD *)(a4 + 24) = *(_DWORD *)(v4 + 24);
  *(_DWORD *)(a4 + 28) = *(_DWORD *)(v4 + 28);
  *(_DWORD *)(a4 + 32) = *(_DWORD *)(v4 + 32);
  *(_DWORD *)(a4 + 36) = *(_DWORD *)(v4 + 36);
  *(_BYTE *)(a4 + 40) = *(_BYTE *)(v4 + 40);
  *(_DWORD *)(a4 + 44) = *(_DWORD *)(v4 + 44);
  *(_DWORD *)(a4 + 48) = *(_DWORD *)(v4 + 48);
  return 3;
}
