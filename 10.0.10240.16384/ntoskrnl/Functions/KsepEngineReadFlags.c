// KsepEngineReadFlags 
 
int __fastcall KsepEngineReadFlags(int *a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v7; // r0
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  unsigned int v11; // r2
  char *v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r2
  char *v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  _WORD *v18; // r3
  int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r1
  _WORD *v22; // r3
  char v23; // r2
  unsigned int v24; // r2
  unsigned int v25; // r2
  char *v26; // r3
  int v27; // [sp+0h] [bp-28h] BYREF
  int v28; // [sp+4h] [bp-24h] BYREF
  int v29[8]; // [sp+8h] [bp-20h] BYREF

  v28 = a3;
  v29[0] = a4;
  v5 = 0;
  v27 = 0;
  if ( !a1 )
    return sub_9653F8(4);
  *a1 = 0;
  v7 = KsepRegistryOpenKey(
         L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Microsoft\\Compatibility",
         0,
         &v27);
  if ( v7 )
  {
    if ( v7 == -1073741772 )
      a1[2] |= 2u;
  }
  else
  {
    v28 = 0;
    v29[0] = 0;
    if ( !KsepRegistryQueryDWORD(v27, L"DisableDeviceFlags", &v28) && v28 == 1 )
    {
      v5 = 2;
      a1[2] |= 4u;
    }
    if ( !KsepRegistryQueryDWORD(v27, L"DisableDriverShims", v29) && v29[0] == 1 )
    {
      v5 |= 1u;
      a1[2] |= 8u;
    }
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(KsepHistoryMessagesIndex);
      v14 = v13 + 1;
    }
    while ( __strex(v14, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v15 = (char *)&KsepHistoryMessages + 8 * (v14 & 0x3F);
    *((_DWORD *)v15 + 1) = 0;
    *((_WORD *)v15 + 1) = 4;
    *(_WORD *)v15 = 131;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(0, (int)"KSE: Engine has group policy flags: %08x\n");
    KsepLogInfo(0, (int)"KSE: Engine has group policy flags: %08x\n", v5);
    KsepRegistryCloseKey(v27);
    v27 = 0;
  }
  v8 = KsepRegistryOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility", 0, &v27);
  v9 = v8;
  if ( v8 == -1073741772 )
  {
    a1[2] |= 1u;
  }
  else
  {
    if ( v8 < 0 )
    {
      __dmb(0xBu);
      do
      {
        v16 = __ldrex(&KsepHistoryErrorsIndex);
        v17 = v16 + 1;
      }
      while ( __strex(v17, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v18 = &KsepHistoryErrors[4 * (v17 & 0x3F)];
      *((_DWORD *)v18 + 1) = v8;
      v18[1] = 4;
      *v18 = 160;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(0, (int)"KSE: Error reading compatibility key: status: %08x\n");
      KsepLogError(0, (int)"KSE: Error reading compatibility key: status: %08x\n", v9);
      goto LABEL_9;
    }
    v19 = KsepRegistryQueryDWORD(v27, L"DisableFlags", v29);
    v9 = v19;
    if ( v19 != -1073741772 )
    {
      if ( v19 >= 0 )
      {
        v23 = v29[0] & 3;
        *a1 = v29[0] & 3;
        if ( (v23 & 1) != 0 )
          a1[2] |= 0x20u;
        if ( (v23 & 2) != 0 )
          a1[2] |= 0x10u;
        __dmb(0xBu);
        do
        {
          v24 = __ldrex(KsepHistoryMessagesIndex);
          v25 = v24 + 1;
        }
        while ( __strex(v25, KsepHistoryMessagesIndex) );
        __dmb(0xBu);
        v26 = (char *)&KsepHistoryMessages + 8 * (v25 & 0x3F);
        *((_DWORD *)v26 + 1) = 0;
        *((_WORD *)v26 + 1) = 4;
        *(_WORD *)v26 = 199;
        if ( (KsepDebugFlag & 1) != 0 )
          KsepDebugPrint(0, (int)"KSE: Engine initialized with registry flags: %08x\n");
        KsepLogInfo(0, (int)"KSE: Engine initialized with registry flags: %08x\n", *a1);
      }
      else
      {
        __dmb(0xBu);
        do
        {
          v20 = __ldrex(&KsepHistoryErrorsIndex);
          v21 = v20 + 1;
        }
        while ( __strex(v21, &KsepHistoryErrorsIndex) );
        __dmb(0xBu);
        v22 = &KsepHistoryErrors[4 * (v21 & 0x3F)];
        *((_DWORD *)v22 + 1) = v19;
        v22[1] = 4;
        *v22 = 182;
        if ( (KsepDebugFlag & 2) != 0 )
          KsepDebugPrint(0, (int)"KSE: Error reading compatibility value [%ws]: status: %08x\n");
        KsepLogError(
          0,
          (int)"KSE: Error reading compatibility value [%ws]: status: %08x\n",
          L"DisableFlags",
          v9,
          v27,
          v28);
      }
      goto LABEL_9;
    }
  }
  v9 = 0;
LABEL_9:
  *a1 |= v5;
  __dmb(0xBu);
  do
  {
    v10 = __ldrex(KsepHistoryMessagesIndex);
    v11 = v10 + 1;
  }
  while ( __strex(v11, KsepHistoryMessagesIndex) );
  __dmb(0xBu);
  v12 = (char *)&KsepHistoryMessages + 8 * (v11 & 0x3F);
  *((_DWORD *)v12 + 1) = 0;
  *((_WORD *)v12 + 1) = 4;
  *(_WORD *)v12 = 210;
  if ( (KsepDebugFlag & 1) != 0 )
    KsepDebugPrint(0, (int)"KSE: Engine flags (after registry/group policy): %08x\n");
  KsepLogInfo(0, (int)"KSE: Engine flags (after registry/group policy): %08x\n", *a1);
  KsepRegistryCloseKey(v27);
  return v9;
}
