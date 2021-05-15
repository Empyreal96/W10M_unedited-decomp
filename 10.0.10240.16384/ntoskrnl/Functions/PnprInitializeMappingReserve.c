// PnprInitializeMappingReserve 
 
int __fastcall PnprInitializeMappingReserve(__int16 a1, int a2)
{
  int v4; // r5
  int v5; // r0
  unsigned int v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r3

  v4 = 0;
  v5 = MmAllocateMappingAddress(0x10000, 1366322768);
  v6 = v5;
  if ( v5 )
  {
    v10 = IoAllocateMdl(v5, 0x10000, 0, 0, 0);
    if ( v10 )
    {
      *(_DWORD *)a2 = v10;
      *(_DWORD *)(a2 + 4) = v6;
      *(_WORD *)(a2 + 8) = a1;
    }
    else
    {
      MmFreeMappingAddress(v6, 1366322768);
      v4 = -1073741670;
      v11 = PnprContext;
      v12 = *(_DWORD *)(PnprContext + 608);
      if ( !v12 )
        v12 = 3921;
      *(_DWORD *)(PnprContext + 608) = v12;
      v13 = *(_DWORD *)(v11 + 612);
      if ( !v13 )
        v13 = 10;
      *(_DWORD *)(v11 + 612) = v13;
    }
  }
  else
  {
    v4 = -1073741670;
    v7 = PnprContext;
    v8 = *(_DWORD *)(PnprContext + 608);
    if ( !v8 )
      v8 = 3906;
    *(_DWORD *)(PnprContext + 608) = v8;
    v9 = *(_DWORD *)(v7 + 612);
    if ( !v9 )
      v9 = 10;
    *(_DWORD *)(v7 + 612) = v9;
  }
  return v4;
}
