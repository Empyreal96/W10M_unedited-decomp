// PpIrpQueryCapabilities 
 
int __fastcall PpIrpQueryCapabilities(int a1, int a2)
{
  int v5[12]; // [sp+8h] [bp-30h] BYREF

  memset((_BYTE *)a2, 0, 64);
  *(_WORD *)a2 = 64;
  *(_WORD *)(a2 + 2) = 1;
  *(_DWORD *)(a2 + 8) = -1;
  *(_DWORD *)(a2 + 12) = -1;
  memset(v5, 0, 40);
  LOWORD(v5[0]) = 2331;
  v5[2] = a2;
  return IopSynchronousCall(a1, (int)v5, -1073741637, 0, 0);
}
