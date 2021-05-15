// CmpCopySyncTree 
 
int __fastcall CmpCopySyncTree(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r4
  int v9; // r3

  v6 = ExAllocatePoolWithTag(1, 10240, 538987843);
  v7 = v6;
  if ( !v6 )
    return 0;
  *(_DWORD *)(v6 + 4) = a4;
  *(_DWORD *)(v6 + 8) = 0;
  v9 = *(_DWORD *)(v6 + 12);
  *(_DWORD *)v6 = a2;
  *(_DWORD *)(v6 + 12) = v9 & 0xFFFFFFF8;
  *(_BYTE *)(v6 + 16) &= 0xFCu;
  v8 = CmpCopySyncTree2(v6);
  ExFreePoolWithTag(v7);
  return v8;
}
