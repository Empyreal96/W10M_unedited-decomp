// IopIrqUnpackResource 
 
int __fastcall IopIrqUnpackResource(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(_DWORD *)(a1 + 8);
  result = 0;
  *a2 = v3;
  a2[1] = 0;
  *a3 = 1;
  a3[1] = 0;
  return result;
}
