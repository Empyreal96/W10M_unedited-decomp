// EtwpBugCheckMultiPartCallback 
 
void __fastcall EtwpBugCheckMultiPartCallback(int a1, int a2, int a3)
{
  int v3; // r3
  __int16 *v4; // r7
  int v6; // r3
  _DWORD *v7; // r1
  int v8; // r1
  int v9; // r9
  unsigned int v10; // r10
  int v11; // r3
  unsigned int v12; // r3
  _DWORD *v13; // r6
  _DWORD *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r0
  unsigned int v20; // r2
  unsigned int *v21; // r1
  unsigned int v22; // r2
  int v23; // r2
  int v24; // r3

  v3 = *(_DWORD *)(a3 + 44);
  v4 = *(__int16 **)(a3 + 36);
  *(_DWORD *)(a3 + 32) = 0;
  if ( v3 != 4 )
    return;
  *(_DWORD *)(a3 + 12) = 730380048;
  *(_DWORD *)(a3 + 16) = 1333533843;
  *(_DWORD *)(a3 + 20) = 1583705264;
  *(_DWORD *)(a3 + 24) = -857845556;
  if ( !v4 )
  {
    v4 = &EtwpDumpCallbackContext;
    *(_DWORD *)&EtwpDumpCallbackContext = 0;
    dword_61A604 = 0;
    *(_DWORD *)(a3 + 36) = &EtwpDumpCallbackContext;
  }
  if ( !*((_BYTE *)v4 + 2) )
  {
    v6 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(a3 + 32) = 32;
    if ( v6 )
    {
      v7 = *(_DWORD **)a3;
      v7[4] = EtwpBootTime;
      v7[5] = MEMORY[0x61A90C];
      v7[2] = EtwCPUSpeedInMHz;
      v7[6] = EtwPerfFreq;
      v7[7] = MEMORY[0x61A77C];
      *v7 = KeMaximumIncrement;
      v7[1] = -268425216;
      *(_DWORD *)(a3 + 28) = *(_DWORD *)a3;
      *(_DWORD *)(a3 + 32) = 32;
      *(_DWORD *)(a3 + 4) = 32;
    }
    *((_BYTE *)v4 + 2) = 1;
    goto LABEL_32;
  }
  v8 = *((_DWORD *)v4 + 1);
  if ( v8 )
  {
    v19 = WmipLoggerContext[(unsigned __int16)*v4];
    v20 = *(_DWORD *)(v8 + 8);
    __dmb(0xBu);
    v21 = (unsigned int *)*((_DWORD *)v4 + 1);
    if ( v20 <= *v21 )
    {
      v22 = v21[2];
      __dmb(0xBu);
      *(_DWORD *)(*((_DWORD *)v4 + 1) + 48) = v22;
    }
    else
    {
      v21[12] = v21[1];
    }
    *(_DWORD *)(a3 + 32) = *(_DWORD *)(*((_DWORD *)v4 + 1) + 48);
    if ( *(_DWORD *)(a3 + 4) )
      *(_DWORD *)(a3 + 28) = *((_DWORD *)v4 + 1);
    v23 = *(_DWORD *)(*((_DWORD *)v4 + 1) + 56);
    if ( v23 != v19 + 72 )
    {
      v18 = v23 - 56;
      goto LABEL_30;
    }
    goto LABEL_29;
  }
  if ( (unsigned __int16)*v4 >= 0x40u )
    goto LABEL_32;
  while ( 1 )
  {
    v9 = WmipLoggerContext[(unsigned __int16)*v4];
    if ( (v9 & 1) != 0 || *(int *)(v9 + 12) >= 0 || (*(_DWORD *)(v9 + 224) & 1) != 0 )
      goto LABEL_17;
    if ( *(_DWORD *)(v9 + 508) )
    {
      __dmb(0xAu);
      __yield();
      goto LABEL_17;
    }
    v10 = 2 * (*(unsigned __int16 *)(v9 + 92) + 24);
    v11 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(a3 + 32) = v10;
    if ( !v11 )
      goto LABEL_20;
    if ( v10 <= *(_DWORD *)(a3 + 8) )
      break;
LABEL_17:
    v12 = (unsigned __int16)(*v4 + 1);
    *v4 = v12;
    if ( v12 >= 0x40 )
      goto LABEL_32;
  }
  v13 = *(_DWORD **)a3;
  v14 = (_DWORD *)(*(_DWORD *)a3 + 32);
  *v13 = 32223201;
  v13[1] = *(_DWORD *)v9;
  v13[4] = *(_DWORD *)(v9 + 4);
  v13[3] = *(_DWORD *)(v9 + 124);
  v13[6] = *(_DWORD *)(v9 + 584);
  v13[7] = *(_DWORD *)(v9 + 588);
  v13[2] = *(_DWORD *)(v9 + 12);
  v13[5] = *(unsigned __int16 *)(v9 + 92);
  v15 = *(_DWORD *)(v9 + 236);
  v16 = *(_DWORD *)(v9 + 240);
  v17 = *(_DWORD *)(v9 + 244);
  *v14 = *(_DWORD *)(v9 + 232);
  v14[1] = v15;
  v14[2] = v16;
  v14[3] = v17;
  memmove((int)(v13 + 12), *(_DWORD *)(v9 + 96), 2 * *(unsigned __int16 *)(v9 + 92));
  *(_DWORD *)(a3 + 28) = *(_DWORD *)a3;
  *(_DWORD *)(a3 + 32) = v10;
  *(_DWORD *)(a3 + 4) = v10;
LABEL_20:
  if ( *(_DWORD *)(v9 + 72) == v9 + 72 )
  {
LABEL_29:
    v18 = 0;
    goto LABEL_30;
  }
  v18 = *(_DWORD *)(v9 + 72) - 56;
LABEL_30:
  *((_DWORD *)v4 + 1) = v18;
  if ( !v18 )
    ++*v4;
LABEL_32:
  v24 = *(_DWORD *)(a3 + 40);
  if ( (unsigned __int16)*v4 >= 0x40u )
  {
    *(_DWORD *)(a3 + 40) = v24 & 0xFFFFFFFE;
    *((_DWORD *)v4 + 1) = 0;
    *((_BYTE *)v4 + 2) = 0;
    *v4 = 0;
  }
  else
  {
    *(_DWORD *)(a3 + 40) = v24 | 1;
  }
}
