// ObQueryTypeInfo 
 
int __fastcall ObQueryTypeInfo(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v6; // r6
  unsigned int v7; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3

  v6 = -1073741820;
  v7 = *a4 + ((*(unsigned __int16 *)(a1 + 8) + 5) & 0xFFFFFFFC) + 96;
  *a4 = v7;
  if ( a3 >= v7 )
  {
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 36);
    *(_DWORD *)(a2 + 56) = *(_DWORD *)(a1 + 48);
    v8 = *(_DWORD *)(a1 + 56);
    v9 = *(_DWORD *)(a1 + 60);
    v10 = *(_DWORD *)(a1 + 64);
    *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1 + 52);
    *(_DWORD *)(a2 + 64) = v8;
    *(_DWORD *)(a2 + 68) = v9;
    *(_DWORD *)(a2 + 72) = v10;
    *(_DWORD *)(a2 + 76) = *(_DWORD *)(a1 + 68);
    *(_BYTE *)(a2 + 80) = (unsigned __int8)(*(_BYTE *)(a1 + 42) & 8) >> 3;
    *(_BYTE *)(a2 + 81) = (unsigned __int8)(*(_BYTE *)(a1 + 42) & 0x10) >> 4;
    *(_DWORD *)(a2 + 84) = *(_DWORD *)(a1 + 76);
    *(_DWORD *)(a2 + 88) = *(_DWORD *)(a1 + 80);
    *(_DWORD *)(a2 + 92) = *(_DWORD *)(a1 + 84);
    *(_BYTE *)(a2 + 82) = *(_BYTE *)(a1 + 20);
    v6 = 0;
    *(_BYTE *)(a2 + 83) = 0;
    *(_DWORD *)(a2 + 4) = a2 + 96;
    *(_WORD *)a2 = *(_WORD *)(a1 + 8);
    *(_WORD *)(a2 + 2) = *(_WORD *)(a1 + 8) + 2;
    memmove(a2 + 96, *(_DWORD *)(a1 + 12), *(unsigned __int16 *)(a1 + 8));
    *(_WORD *)(a2 + 2 * ((*(unsigned __int16 *)(a1 + 8) >> 1) + 48)) = 0;
  }
  return v6;
}
