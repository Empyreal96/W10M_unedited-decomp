// sub_7CC110 
 
void __fastcall sub_7CC110(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  char *v12; // r4
  int v13; // r6
  int v14; // r8
  char *v15; // r0
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r2
  int v24; // r1
  int v25; // lr
  int (__fastcall *v26)(int, int); // r2
  int v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r1
  char *v30; // r3

  v15 = KsepPoolAllocateNonPaged(128);
  if ( v15 )
  {
    v16 = *((_DWORD *)v12 + 11);
    if ( v16 )
    {
      v17 = a9;
      if ( a9 )
      {
        *(_DWORD *)v15 = v16;
        *((_DWORD *)v12 + 11) = v17;
      }
    }
    v18 = *((_DWORD *)v12 + 12);
    if ( v18 )
    {
      v19 = a10;
      if ( a10 )
      {
        *((_DWORD *)v15 + 1) = v18;
        *((_DWORD *)v12 + 12) = v19;
      }
    }
    v20 = *((_DWORD *)v12 + 13);
    if ( v20 )
    {
      v21 = a11;
      if ( a11 )
      {
        *((_DWORD *)v15 + 2) = v20;
        *((_DWORD *)v12 + 13) = v21;
      }
    }
    v22 = *(_DWORD *)(v13 + 4);
    if ( v22 )
    {
      v23 = a12;
      if ( a12 )
      {
        *((_DWORD *)v15 + 3) = v22;
        *(_DWORD *)(v13 + 4) = v23;
      }
    }
    v24 = 28;
    v25 = v15 - v12;
    while ( 1 )
    {
      v26 = (int (__fastcall *)(int, int))*((_DWORD *)v12 + 14);
      if ( v26 )
      {
        if ( v26 != IopInvalidDeviceRequest )
        {
          v27 = *(_DWORD *)&v12[v25 + 16 + (char *)&a9 - v15];
          if ( v27 )
          {
            *(_DWORD *)&v12[v25 + 16] = v26;
            *((_DWORD *)v12 + 14) = v27;
          }
        }
      }
      v12 += 4;
      if ( !--v24 )
      {
        *(_DWORD *)(v13 + 28) = v15;
        __dmb(0xBu);
        do
        {
          v28 = __ldrex(KsepHistoryMessagesIndex);
          v29 = v28 + 1;
        }
        while ( __strex(v29, KsepHistoryMessagesIndex) );
        __dmb(0xBu);
        v30 = (char *)&KsepHistoryMessages + 8 * (v29 & 0x3F);
        *((_DWORD *)v30 + 1) = 0;
        *((_WORD *)v30 + 1) = 8;
        *(_WORD *)v30 = 262;
        if ( (KsepDebugFlag & v14) != 0 )
          KsepDebugPrint(9, (int)"KSE: Hooked callbacks for driver [%ws].\n");
        KsepLogInfo(9, (int)"KSE: Hooked callbacks for driver [%ws].\n", a6);
        JUMPOUT(0x76FFD8);
      }
    }
  }
  JUMPOUT(0x76FFD2);
}
