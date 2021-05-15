// PnprReplaceStart 
 
int __fastcall PnprReplaceStart(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2
  int v9; // r2
  int v10; // r6
  int v11; // r2
  int v12; // [sp+0h] [bp-20h] BYREF
  int v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h]
  int v15; // [sp+Ch] [bp-14h]

  v13 = a2;
  v14 = a3;
  v15 = a4;
  v4 = 0;
  v5 = PnprContext;
  v12 = 0;
  v13 = *(_DWORD *)(PnprContext + 16);
  v14 = *(_DWORD *)(PnprContext + 40);
  if ( (*(_DWORD *)(PnprContext + 564) & 2) != 0 )
  {
    v4 = 1;
    v12 = 1;
  }
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
    v12 = v4 | 2;
  result = off_6179E4(&v12, PnprContext + 548);
  if ( result < 0 )
  {
    v7 = PnprContext;
    v8 = *(_DWORD *)(PnprContext + 608);
    if ( !v8 )
      v8 = 2709;
    *(_DWORD *)(PnprContext + 608) = v8;
    v9 = *(_DWORD *)(v7 + 612);
    if ( !v9 )
      v9 = 6;
LABEL_16:
    *(_DWORD *)(v7 + 612) = v9;
    return result;
  }
  v10 = PnprContext;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 20) + 4) )
  {
    memset((_BYTE *)(v5 + 56), 0, 48);
    *(_DWORD *)(v5 + 56) = 48;
    *(_DWORD *)(v5 + 60) = 2;
    *(_DWORD *)(v5 + 64) = *(_DWORD *)(v10 + 8);
    *(_DWORD *)(v5 + 68) = *(_DWORD *)(v10 + 12);
    *(_DWORD *)(v5 + 72) = *(_DWORD *)(v10 + 32);
    *(_DWORD *)(v5 + 76) = *(_DWORD *)(v10 + 36);
    *(_DWORD *)(v5 + 80) = *(_DWORD *)(v10 + 16);
    *(_DWORD *)(v5 + 84) = *(_DWORD *)(v10 + 40);
    *(_DWORD *)(v5 + 88) = *(_DWORD *)(v10 + 20);
    *(_DWORD *)(v5 + 92) = *(_DWORD *)(v10 + 44);
    *(_DWORD *)(v5 + 96) = PnprMapTargetSparePhysicalPages;
    result = (*(int (__fastcall **)(int, int))(v10 + 572))(v5 + 56, v10 + 552);
    if ( result < 0 )
    {
      v7 = PnprContext;
      v11 = *(_DWORD *)(PnprContext + 608);
      if ( !v11 )
        v11 = 2735;
      *(_DWORD *)(PnprContext + 608) = v11;
      v9 = *(_DWORD *)(v7 + 612);
      if ( !v9 )
        v9 = 8;
      goto LABEL_16;
    }
  }
  return result;
}
