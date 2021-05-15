// IopGenericPackResource 
 
int __fastcall IopGenericPackResource(int a1, __int64 a2, int a3)
{
  char v4; // r1
  int v5; // r3
  int result; // r0

  *(_BYTE *)a3 = *(_BYTE *)(a1 + 1);
  *(_WORD *)(a3 + 2) = *(_WORD *)(a1 + 4);
  v4 = *(_BYTE *)(a1 + 2);
  *(_QWORD *)(a3 + 4) = a2;
  *(_BYTE *)(a3 + 1) = v4;
  v5 = *(_DWORD *)(a1 + 8);
  result = 0;
  *(_DWORD *)(a3 + 12) = v5;
  return result;
}
