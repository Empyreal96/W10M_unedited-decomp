// WdipSemLoadNextScenario 
 
int __fastcall WdipSemLoadNextScenario(int a1, int a2, int a3)
{
  _BYTE *v4; // r6
  int v5; // r8
  int v7; // r4
  int v8; // r0
  unsigned int v10; // r2
  int v11; // r1
  unsigned int v12; // r2
  int v13; // r1
  unsigned __int16 *v14; // r4
  char *v15; // r0
  int v16; // r3
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r7
  _BYTE *v21; // r0
  int v22; // r0
  unsigned int v23; // r3
  int *v24; // r0
  int v25; // r7
  int v26; // r0
  unsigned int v27; // r3
  int v28; // [sp+8h] [bp-1E8h] BYREF
  int v29; // [sp+Ch] [bp-1E4h] BYREF
  int v30; // [sp+10h] [bp-1E0h] BYREF
  int v31; // [sp+14h] [bp-1DCh] BYREF
  int v32; // [sp+18h] [bp-1D8h] BYREF
  int v33; // [sp+1Ch] [bp-1D4h] BYREF
  int v34; // [sp+20h] [bp-1D0h] BYREF
  __int64 v35; // [sp+28h] [bp-1C8h] BYREF
  unsigned __int16 v36[4]; // [sp+30h] [bp-1C0h] BYREF
  int v37[38]; // [sp+38h] [bp-1B8h] BYREF
  unsigned __int16 v38[64]; // [sp+D0h] [bp-120h] BYREF
  unsigned __int16 v39[80]; // [sp+150h] [bp-A0h] BYREF

  v4 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  v35 = 0i64;
  v5 = 0;
  if ( !a1 || !a3 )
    return -1073741811;
  memset(v37, 0, sizeof(v37));
  v8 = ZwEnumerateKey();
  v7 = v8;
  if ( v8 != -2147483622 && v8 >= 0 )
  {
    if ( v37[3] >= 0x80u )
    {
      v7 = -2147483643;
      goto LABEL_8;
    }
    *((_WORD *)&v37[4] + ((unsigned int)v37[3] >> 1)) = 0;
    memset(v39, 0, 128);
    memset(v38, 0, sizeof(v38));
    v10 = 0;
    while ( 1 )
    {
      v11 = *((unsigned __int16 *)&v37[4] + v10);
      if ( v11 == 59 )
        break;
      v39[v10++] = v11;
      if ( v10 >= 0x40 )
        goto LABEL_23;
    }
    if ( 2 * v10 >= 0x80 )
      _report_rangecheckfailure();
    v39[v10] = 0;
LABEL_23:
    if ( v10 >= 0x40 )
      goto LABEL_24;
    v12 = v10 + 1;
    v13 = 0;
    if ( v12 >= 0x40 )
      goto LABEL_24;
    v14 = v38;
    v15 = (char *)v37 + 2 * v12;
    do
    {
      v16 = *((unsigned __int16 *)v15 + 8);
      *v14++ = v16;
      if ( !v16 )
        break;
      ++v12;
      v15 += 2;
      ++v13;
    }
    while ( v12 < 0x40 );
    if ( v12 >= 0x40 )
    {
LABEL_24:
      v7 = -1073741823;
      goto LABEL_8;
    }
    if ( v13 == 1 && v38[0] == 42 )
      v5 = 1;
    RtlInitUnicodeString((unsigned int)v36, v39);
    v7 = RtlGUIDFromString(v36, (_BYTE *)a3);
    if ( v7 < 0 )
      goto LABEL_8;
    if ( !v5 )
    {
      RtlInitUnicodeString((unsigned int)v36, v38);
      v7 = RtlUnicodeStringToInteger(v36, 0xAu, &v34);
      if ( v7 < 0 )
        goto LABEL_8;
      *(_WORD *)(a3 + 16) = v34;
    }
    v7 = WdipSemOpenRegistryKey(&v37[4], a1, &v28);
    if ( v7 < 0 )
      goto LABEL_8;
    v17 = WdipSemQueryValueFromRegistry(v28, L"Level", 4, 4, &v32, &v29);
    v7 = v17;
    if ( v17 >= 0 )
    {
      if ( v32 )
      {
        *(_BYTE *)(a3 + 18) = v32;
LABEL_44:
        v18 = WdipSemQueryValueFromRegistry(v28, L"Keyword", 11, 8, &v35, &v29);
        v7 = v18;
        if ( v18 >= 0 )
        {
          if ( v35 )
          {
            *(_QWORD *)(a3 + 24) = v35;
            goto LABEL_50;
          }
        }
        else if ( v18 != -1073741772 )
        {
          goto LABEL_8;
        }
        *(_DWORD *)(a3 + 24) = -1;
        *(_DWORD *)(a3 + 28) = -1;
LABEL_50:
        v19 = WdipSemQueryValueFromRegistry(v28, L"EnableProperty", 4, 4, &v33, &v29);
        v7 = v19;
        if ( v19 >= 0 )
        {
          *(_DWORD *)(a3 + 36) = v33;
        }
        else
        {
          if ( v19 != -1073741772 )
            goto LABEL_8;
          *(_DWORD *)(a3 + 36) = 0;
        }
        if ( WdipSemOpenRegistryKey(L"EndEvents", v28, &v31) < 0 )
        {
LABEL_55:
          v7 = 0;
          goto LABEL_8;
        }
        v20 = 0;
        while ( 1 )
        {
          v21 = (_BYTE *)WdipSemFastAllocate(0, 48);
          v4 = v21;
          if ( !v21 )
            goto LABEL_77;
          memset(v21, 0, 48);
          v22 = WdipSemLoadNextEndEvent(v31, v20, (int)v4);
          v7 = v22;
          ++v20;
          if ( v22 == -2147483622 )
            break;
          if ( v22 < 0 )
            goto LABEL_8;
          v23 = *(_DWORD *)(a3 + 52);
          if ( v23 >= 0x10 )
          {
            if ( EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_INIT_SCENARIO_END_EVENT_MAX) )
            {
              v24 = WDI_SEM_EVENT_INIT_SCENARIO_END_EVENT_MAX;
LABEL_76:
              WdipSemWriteScenarioLimitExceededEvent(v24, a3, *(unsigned __int16 *)(a3 + 16));
            }
            goto LABEL_24;
          }
          *(_DWORD *)(a3 + 4 * v23 + 552) = v4;
          ++*(_DWORD *)(a3 + 52);
        }
        if ( !*(_DWORD *)(a3 + 52) )
          goto LABEL_55;
        if ( !v5 )
        {
          if ( WdipSemOpenRegistryKey(L"ContextProviders", v28, &v30) < 0 )
            goto LABEL_55;
          v25 = 0;
          while ( 1 )
          {
            if ( !v4 )
            {
              v4 = (_BYTE *)WdipSemFastAllocate(0, 48);
              if ( !v4 )
                break;
            }
            memset(v4, 0, 48);
            v26 = WdipSemLoadNextContextProvider(v30, v25, (unsigned int)v4);
            v7 = v26;
            ++v25;
            if ( v26 == -2147483622 )
              goto LABEL_55;
            if ( v26 < 0 )
              goto LABEL_8;
            v27 = *(_DWORD *)(a3 + 48);
            if ( v27 >= 0x7C )
            {
              if ( !EtwEventEnabled(
                      WdipSemRegHandle,
                      MEMORY[0x61CB14],
                      (int)WDI_SEM_EVENT_INIT_SCENARIO_CONTEXT_PROVIDER_MAX) )
                goto LABEL_24;
              v24 = WDI_SEM_EVENT_INIT_SCENARIO_CONTEXT_PROVIDER_MAX;
              goto LABEL_76;
            }
            *(_DWORD *)(a3 + 4 * v27 + 56) = v4;
            ++*(_DWORD *)(a3 + 48);
            v4 = 0;
          }
LABEL_77:
          v7 = -1073741670;
          goto LABEL_8;
        }
        goto LABEL_24;
      }
    }
    else if ( v17 != -1073741772 )
    {
      goto LABEL_8;
    }
    *(_BYTE *)(a3 + 18) = -1;
    goto LABEL_44;
  }
LABEL_8:
  if ( v28 )
    ZwClose();
  if ( v30 )
    ZwClose();
  if ( v31 )
    ZwClose();
  if ( v4 )
    WdipSemFastFree(0, v4);
  return v7;
}
