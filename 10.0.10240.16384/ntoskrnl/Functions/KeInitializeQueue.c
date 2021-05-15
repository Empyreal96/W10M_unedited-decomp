// KeInitializeQueue 
 
int __fastcall KeInitializeQueue(int result, int a2)
{
  *(_BYTE *)result = 4;
  *(_BYTE *)(result + 2) = 10;
  *(_BYTE *)(result + 1) = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  *(_DWORD *)(result + 16) = result + 16;
  *(_DWORD *)(result + 20) = result + 16;
  *(_DWORD *)(result + 32) = result + 32;
  *(_DWORD *)(result + 36) = result + 32;
  *(_DWORD *)(result + 24) = 0;
  if ( a2 )
    *(_DWORD *)(result + 28) = a2;
  else
    *(_DWORD *)(result + 28) = KeNumberProcessors_0;
  return result;
}
