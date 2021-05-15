// HvpGetCellFlat 
 
int __fastcall HvpGetCellFlat(int a1, int a2, _DWORD *a3)
{
  int v3; // r3

  v3 = *(_DWORD *)(a1 + 32);
  *a3 = a2;
  return v3 + a2 + 4100;
}
