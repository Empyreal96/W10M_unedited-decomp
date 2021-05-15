// KeInitializeGate 
 
int __fastcall KeInitializeGate(int result)
{
  *(_BYTE *)result = 7;
  *(_BYTE *)(result + 1) = 1;
  *(_BYTE *)(result + 2) = 4;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  return result;
}
