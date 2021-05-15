// IopBusNumberPackResource 
 
int __fastcall IopBusNumberPackResource(int a1, int a2, int a3, int a4, int a5)
{
  __int16 v5; // r3
  int v6; // r3
  int result; // r0

  *(_BYTE *)a5 = 6;
  *(_BYTE *)(a5 + 1) = *(_BYTE *)(a1 + 2);
  v5 = *(_WORD *)(a1 + 4);
  *(_DWORD *)(a5 + 4) = a3;
  *(_WORD *)(a5 + 2) = v5;
  v6 = *(_DWORD *)(a1 + 8);
  result = 0;
  *(_DWORD *)(a5 + 8) = v6;
  return result;
}
