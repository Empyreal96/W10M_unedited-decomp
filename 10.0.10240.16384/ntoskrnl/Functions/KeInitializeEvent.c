// KeInitializeEvent 
 
int __fastcall KeInitializeEvent(int result, char a2, int a3)
{
  *(_BYTE *)result = a2;
  *(_BYTE *)(result + 1) = 0;
  *(_BYTE *)(result + 2) = 4;
  *(_DWORD *)(result + 4) = a3;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  return result;
}
