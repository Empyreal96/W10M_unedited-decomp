// KeInitializeDpc 
 
int __fastcall KeInitializeDpc(int result, int a2, int a3)
{
  *(_BYTE *)result = 19;
  *(_BYTE *)(result + 1) = 1;
  *(_WORD *)(result + 2) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = a2;
  *(_DWORD *)(result + 16) = a3;
  return result;
}
