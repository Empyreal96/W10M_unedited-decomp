// KeInitializeProcess 
 
int __fastcall KeInitializeProcess(int a1, char a2, int a3, int a4, int a5, char a6)
{
  int result; // r0

  *(_BYTE *)a1 = 3;
  *(_BYTE *)(a1 + 2) = 42;
  *(_DWORD *)(a1 + 8) = a1 + 8;
  *(_DWORD *)(a1 + 12) = a1 + 8;
  *(_BYTE *)(a1 + 104) = a2;
  *(_WORD *)(a1 + 88) = 1;
  *(_WORD *)(a1 + 90) = 1;
  *(_DWORD *)(a1 + 92) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  if ( (a6 & 1) != 0 )
    *(_DWORD *)(a1 + 100) |= 1u;
  *(_WORD *)(a1 + 64) = 1;
  *(_WORD *)(a1 + 66) = 1;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 72) = *(_DWORD *)a3;
  *(_DWORD *)(a1 + 100) ^= ((unsigned __int16)*(_DWORD *)(a1 + 100) ^ (unsigned __int16)((unsigned __int16)(1 << *(_WORD *)(a3 + 4)) << 8)) & 0x100;
  *(_DWORD *)(a1 + 16) = a1 + 16;
  *(_DWORD *)(a1 + 20) = a1 + 16;
  *(_DWORD *)(a1 + 76) = a1 + 76;
  *(_DWORD *)(a1 + 80) = a1 + 76;
  *(_DWORD *)(a1 + 40) = a1 + 40;
  *(_DWORD *)(a1 + 44) = a1 + 40;
  *(_BYTE *)(a1 + 105) = 6;
  *(_DWORD *)(a1 + 116) = 0;
  KiSetIdealNodeProcessByGroup(a1, a4, *(unsigned __int16 *)(a3 + 4), 6);
  result = 0;
  *(_WORD *)(a1 + 114) = *(_WORD *)(a1 + 2 * *(unsigned __int16 *)(a3 + 4) + 112);
  *(_DWORD *)(a1 + 144) = a5;
  return result;
}
