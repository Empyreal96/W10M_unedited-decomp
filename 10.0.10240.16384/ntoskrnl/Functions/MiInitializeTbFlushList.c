// MiInitializeTbFlushList 
 
int __fastcall MiInitializeTbFlushList(int result, int a2, int a3)
{
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_BYTE *)(result + 4) = 0;
  *(_BYTE *)(result + 5) = 0;
  *(_DWORD *)result = a2;
  *(_DWORD *)(result + 8) = a3;
  *(_DWORD *)(result + 20) = 0;
  return result;
}
