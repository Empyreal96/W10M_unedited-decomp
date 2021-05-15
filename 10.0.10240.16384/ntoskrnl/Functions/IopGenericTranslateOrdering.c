// IopGenericTranslateOrdering 
 
int __fastcall IopGenericTranslateOrdering(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int v7; // r5
  int v9; // r3
  int v10; // r4
  int v11; // r5
  int v12; // r4
  char v13; // r3
  int v15; // [sp+4h] [bp-24h]
  _DWORD v16[8]; // [sp+8h] [bp-20h] BYREF

  v16[0] = a3;
  v16[1] = a4;
  v5 = *(_DWORD *)(a2 + 4);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)a1 = *(_DWORD *)a2;
  *(_DWORD *)(a1 + 4) = v5;
  *(_DWORD *)(a1 + 8) = v6;
  *(_DWORD *)(a1 + 12) = v7;
  v9 = *(_DWORD *)(a2 + 20);
  v10 = *(_DWORD *)(a2 + 24);
  v11 = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(a1 + 20) = v9;
  *(_DWORD *)(a1 + 24) = v10;
  *(_DWORD *)(a1 + 28) = v11;
  v12 = *(unsigned __int8 *)(a2 + 1);
  if ( v12 == 1 || v12 == 3 || v12 == 7 )
  {
    if ( IopTranslateBusAddress(*(_DWORD *)(a2 + 16), *(_DWORD *)(a2 + 20), v12, a1 + 16, v16, a2) < 0
      || IopTranslateBusAddress(*(_DWORD *)(a2 + 24), *(_DWORD *)(a2 + 28), v12, a1 + 24, (char *)v16 + 1, v15) < 0 )
    {
      v13 = 0;
    }
    else
    {
      v13 = v16[0];
    }
    *(_BYTE *)(a1 + 1) = v13;
  }
  return 0;
}
