// KeInitializeInterruptEx 
 
int __fastcall KeInitializeInterruptEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, char a10, int a11, char a12, int a13, int a14, char a15, int a16)
{
  _BYTE *v19; // r0
  int result; // r0
  int v21; // r3

  v19 = memset((_BYTE *)a1, 0, 176);
  *(_WORD *)a1 = 22;
  *(_WORD *)(a1 + 2) = 176;
  *(_DWORD *)(a1 + 24) = a4;
  if ( !a2 )
    return sub_51F9CC(v19);
  *(_DWORD *)(a1 + 12) = a2;
  v21 = a6;
  result = 0;
  if ( !a6 )
  {
    *(_DWORD *)(a1 + 28) = 0;
    v21 = a1 + 28;
  }
  *(_DWORD *)(a1 + 36) = v21;
  *(_DWORD *)(a1 + 44) = a8;
  *(_BYTE *)(a1 + 49) = a10;
  *(_DWORD *)(a1 + 64) = a11;
  *(_BYTE *)(a1 + 56) = a12;
  *(_BYTE *)(a1 + 48) = a9;
  if ( !a10 )
  {
    *(_BYTE *)(a7 + 2) = 4;
    *(_BYTE *)a7 = 1;
    *(_BYTE *)(a7 + 1) = 0;
    *(_DWORD *)(a7 + 4) = 1;
    *(_DWORD *)(a7 + 8) = a7 + 8;
    *(_DWORD *)(a7 + 12) = a7 + 8;
    *(_DWORD *)(a1 + 80) = a7;
  }
  *(_DWORD *)(a1 + 52) = a13;
  *(_BYTE *)(a1 + 57) = a15;
  *(_DWORD *)(a1 + 96) = a16;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 4) = a1 + 4;
  *(_DWORD *)(a1 + 8) = a1 + 4;
  *(_BYTE *)(a1 + 51) = 0;
  return result;
}
