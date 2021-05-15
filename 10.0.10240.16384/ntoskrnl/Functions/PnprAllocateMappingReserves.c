// PnprAllocateMappingReserves 
 
int __fastcall PnprAllocateMappingReserves(int *a1, int *a2, unsigned int a3)
{
  int v4; // r4
  int v5; // r6
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r7
  int v9; // r8
  int v10; // r0
  _DWORD *v11; // r4
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r0
  int v15; // r2
  int v16; // r3

  v4 = 3 * a3;
  v5 = ExAllocatePoolWithTag(512, 12 * a3, 1366322768);
  if ( !v5 )
    return -1073741670;
  v7 = ExAllocatePoolWithTag(512, 4 * v4, 1366322768);
  if ( v7 )
  {
    memset((_BYTE *)v5, 0, 4 * v4);
    memset((_BYTE *)v7, 0, 4 * v4);
    v8 = 0;
    if ( a3 )
    {
      v9 = v7;
      while ( 1 )
      {
        v6 = PnprInitializeMappingReserve(2, v5 - v7 + v9);
        if ( v6 < 0 )
          break;
        v6 = PnprInitializeMappingReserve(2050, v9);
        if ( v6 < 0 )
        {
          PnprFreeMappingReserve(v5 + 12 * v8);
          goto LABEL_11;
        }
        ++v8;
        v9 += 12;
        if ( v8 >= a3 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      v6 = 0;
LABEL_11:
      if ( v6 >= 0 )
        goto LABEL_18;
    }
  }
  else
  {
    v6 = -1073741670;
  }
  if ( v7 && *(_DWORD *)v5 && *(_DWORD *)v7 )
  {
    v10 = PnprContext;
    v11 = (_DWORD *)(v5 + 12 * *(_DWORD *)(PnprContext + 128));
    if ( !*v11 )
    {
      v12 = *(_DWORD *)(v5 + 4);
      v13 = *(_DWORD *)(v5 + 8);
      *v11 = *(_DWORD *)v5;
      v11[1] = v12;
      v11[2] = v13;
      v14 = (_DWORD *)(v7 + 12 * *(_DWORD *)(v10 + 128));
      v15 = *(_DWORD *)(v7 + 4);
      v16 = *(_DWORD *)(v7 + 8);
      *v14 = *(_DWORD *)v7;
      v14[1] = v15;
      v14[2] = v16;
      *(_DWORD *)v5 = 0;
      *(_DWORD *)(v5 + 4) = 0;
      *(_DWORD *)(v5 + 8) = 0;
      *(_DWORD *)v7 = 0;
      *(_DWORD *)(v7 + 4) = 0;
      *(_DWORD *)(v7 + 8) = 0;
    }
    v6 = 0;
LABEL_18:
    *a1 = v5;
    *a2 = v7;
    return v6;
  }
  ExFreePoolWithTag(v5);
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v6;
}
