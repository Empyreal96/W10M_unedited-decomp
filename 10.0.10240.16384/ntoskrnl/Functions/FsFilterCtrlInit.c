// FsFilterCtrlInit 
 
int __fastcall FsFilterCtrlInit(int a1, char a2, int a3, int a4, int a5)
{
  _BYTE *v7; // r0
  unsigned __int16 v8; // r3

  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)a1 = 36;
  *(_BYTE *)(a1 + 4) = a2;
  *(_DWORD *)(a1 + 8) = a3;
  *(_DWORD *)(a1 + 12) = a5;
  v7 = memset((_BYTE *)(a1 + 16), 0, 20);
  v8 = *(char *)(a3 + 48);
  *(_WORD *)(a1 + 46) = 0;
  *(_WORD *)(a1 + 44) = v8;
  if ( v8 > 0xFu )
    return sub_546AEC(v7);
  *(_DWORD *)(a1 + 48) = a1 + 52;
  *(_WORD *)(a1 + 44) = 15;
  memset(*(_BYTE **)(a1 + 48), 0, 240);
  return 0;
}
