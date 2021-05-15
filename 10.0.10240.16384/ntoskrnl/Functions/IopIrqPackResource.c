// IopIrqPackResource 
 
int __fastcall IopIrqPackResource(int a1, int a2, int a3, int a4, int a5)
{
  char v5; // r3

  *(_BYTE *)a5 = 2;
  *(_WORD *)(a5 + 2) = *(_WORD *)(a1 + 4);
  v5 = *(_BYTE *)(a1 + 2);
  *(_DWORD *)(a5 + 8) = a3;
  *(_WORD *)(a5 + 4) = a3;
  *(_BYTE *)(a5 + 1) = v5;
  *(_DWORD *)(a5 + 12) = -1;
  *(_WORD *)(a5 + 6) = 0;
  return 0;
}
