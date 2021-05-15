// KiMoveApcState 
 
int __fastcall KiMoveApcState(int result, int a2)
{
  int v3; // r1
  _DWORD *v4; // r3

  *(_DWORD *)(a2 + 16) = *(_DWORD *)(result + 16);
  *(_BYTE *)(a2 + 20) = *(_BYTE *)(result + 20);
  *(_BYTE *)(a2 + 21) = *(_BYTE *)(result + 21);
  *(_BYTE *)(a2 + 22) = *(_BYTE *)(result + 22);
  v3 = *(_DWORD *)result;
  if ( *(_DWORD *)result == result )
  {
    *(_DWORD *)a2 = a2;
    *(_DWORD *)(a2 + 4) = a2;
    *(_BYTE *)(a2 + 21) = 0;
  }
  else
  {
    v4 = *(_DWORD **)(result + 4);
    *(_DWORD *)a2 = v3;
    *(_DWORD *)(a2 + 4) = v4;
    *(_DWORD *)(v3 + 4) = a2;
    *v4 = a2;
  }
  if ( *(_DWORD *)(result + 8) != result + 8 )
    return sub_50CDB0();
  *(_DWORD *)(a2 + 8) = a2 + 8;
  *(_DWORD *)(a2 + 12) = a2 + 8;
  *(_BYTE *)(a2 + 22) = 0;
  return result;
}
