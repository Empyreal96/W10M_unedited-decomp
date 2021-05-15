// PnprSwap 
 
int PnprSwap()
{
  _DWORD *v0; // r1
  int v1; // r3
  int v2; // r3
  int v3; // r5
  _DWORD *v4; // r2
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r2
  int (__fastcall *v10)(_DWORD); // r3
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r0
  unsigned int v15; // r7
  int v16; // r6
  int *v17; // r0
  int v18; // r1
  int *v19; // r0
  int v20; // r1

  v0 = (_DWORD *)PnprContext;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 20) + 4) && (*(_DWORD *)(PnprContext + 48) & 8) == 0 )
  {
    v1 = *(_DWORD *)(PnprContext + 148);
    __dmb(0xBu);
    if ( v1 < 2 )
    {
      v2 = PnprContext;
      __dmb(0xBu);
      *(_DWORD *)(v2 + 148) = 2;
    }
    v3 = PnprMirrorMarkedPages();
    if ( v3 < 0 )
    {
      v4 = (_DWORD *)PnprContext;
      v5 = *(_DWORD *)(PnprContext + 608);
      if ( !v5 )
        v5 = 2799;
      *(_DWORD *)(PnprContext + 608) = v5;
      v6 = v4[153];
      if ( !v6 )
        v6 = 1;
LABEL_10:
      v4[153] = v6;
      goto LABEL_36;
    }
    v7 = PnprContext;
    __dmb(0xBu);
    *(_DWORD *)(v7 + 152) = 1;
    v8 = PnprContext;
    __dmb(0xBu);
    *(_DWORD *)(v8 + 148) = 3;
    while ( 1 )
    {
      v9 = *(_DWORD *)(PnprContext + 152);
      __dmb(0xBu);
      v0 = (_DWORD *)PnprContext;
      if ( v9 >= *(_DWORD *)(PnprContext + 124) )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  v10 = (int (__fastcall *)(_DWORD))v0[149];
  if ( v10 )
  {
    v3 = v10(v0[138]);
    if ( v3 < 0 )
    {
      v4 = (_DWORD *)PnprContext;
      v11 = *(_DWORD *)(PnprContext + 608);
      if ( !v11 )
        v11 = 2819;
      *(_DWORD *)(PnprContext + 608) = v11;
      v6 = v4[153];
      if ( !v6 )
        v6 = 8;
      goto LABEL_10;
    }
    v0 = (_DWORD *)PnprContext;
  }
  __dmb(0xBu);
  v0[38] = 1;
  v12 = PnprContext;
  __dmb(0xBu);
  *(_DWORD *)(v12 + 148) = 4;
  while ( 1 )
  {
    v13 = *(_DWORD *)(PnprContext + 152);
    __dmb(0xBu);
    if ( v13 >= *(_DWORD *)(PnprContext + 124) )
      break;
    __dmb(0xAu);
    __yield();
  }
  v14 = PnprSwapFinalize();
  v4 = (_DWORD *)PnprContext;
  v3 = v14;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 20) + 4) )
  {
    v15 = 0;
    if ( *(_DWORD *)(PnprContext + 124) )
    {
      v16 = 0;
      do
      {
        v17 = (int *)(v16 + v4[26]);
        if ( v17 )
        {
          v18 = *v17;
          if ( *v17 )
          {
            if ( (*(_WORD *)(v18 + 6) & 1) != 0 )
            {
              MmUnmapReservedMapping(v17[1], 1366322768, v18);
              v4 = (_DWORD *)PnprContext;
            }
          }
        }
        v19 = (int *)(v16 + v4[27]);
        if ( v19 )
        {
          v20 = *v19;
          if ( *v19 )
          {
            if ( (*(_WORD *)(v20 + 6) & 1) != 0 )
            {
              MmUnmapReservedMapping(v19[1], 1366322768, v20);
              v4 = (_DWORD *)PnprContext;
            }
          }
        }
        ++v15;
        v16 += 12;
      }
      while ( v15 < v4[31] );
    }
  }
LABEL_36:
  __dmb(0xBu);
  v4[37] = 5;
  return v3;
}
