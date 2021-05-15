// BgpTxtGetRegionContext 
 
_DWORD *__fastcall BgpTxtGetRegionContext(int a1, int a2, void **a3, void **a4)
{
  BOOL v5; // r7
  _BYTE *v6; // r0
  _DWORD *v7; // r5
  int v8; // r2
  int v9; // r3
  void **v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  if ( !a1 || (*(_DWORD *)(a1 + 48) & 1) == 0 || BgpFoGetFontHandle(0, v11) < 0 )
    return 0;
  v5 = *(void ***)(a1 + 36) == v11[0];
  v6 = (_BYTE *)BgpFwAllocateMemory(0x1Cu);
  v7 = v6;
  if ( v6 )
  {
    memset(v6, 0, 28);
    *v7 = *(_DWORD *)a1;
    v7[1] = *(_DWORD *)(a1 + 4);
    v8 = *(_DWORD *)(a1 + 12);
    v9 = *(_DWORD *)(a1 + 16);
    v7[2] = *(_DWORD *)(a1 + 8);
    v7[3] = v8;
    v7[4] = v9;
    v7[5] = *(_DWORD *)(a1 + 40);
    v7[6] = v5;
  }
  return v7;
}
