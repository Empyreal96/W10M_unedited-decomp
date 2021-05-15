// KeInitializeApc 
 
int __fastcall KeInitializeApc(int result, int a2, int a3, int a4, int a5, int a6, char a7, int a8)
{
  *(_BYTE *)result = 18;
  *(_BYTE *)(result + 2) = 48;
  if ( a3 == 2 )
    *(_BYTE *)(result + 44) = *(_BYTE *)(a2 + 362);
  else
    *(_BYTE *)(result + 44) = a3;
  *(_DWORD *)(result + 20) = a4;
  *(_DWORD *)(result + 8) = a2;
  *(_DWORD *)(result + 24) = a5;
  *(_DWORD *)(result + 28) = a6;
  if ( a6 )
  {
    *(_BYTE *)(result + 45) = a7;
    *(_DWORD *)(result + 32) = a8;
  }
  else
  {
    *(_BYTE *)(result + 45) = 0;
    *(_DWORD *)(result + 32) = 0;
  }
  *(_BYTE *)(result + 46) = 0;
  return result;
}
