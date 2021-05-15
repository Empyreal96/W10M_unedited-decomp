// WdipSemLoadScenarioTable 
 
int WdipSemLoadScenarioTable()
{
  unsigned int v0; // r5
  int v1; // r4
  int v2; // r4
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4
  unsigned int v6; // r7
  unsigned int v7; // r6
  int v8; // r0
  char v9; // r7
  int v10; // r0
  int v11; // r6
  _BYTE *v12; // r0
  int v13; // r0
  int v14; // r4
  int v15; // r4
  int v16; // r0
  int v18; // [sp+8h] [bp-F0h] BYREF
  int v19; // [sp+Ch] [bp-ECh]
  int v20; // [sp+10h] [bp-E8h] BYREF
  int v21; // [sp+14h] [bp-E4h] BYREF
  int v22; // [sp+18h] [bp-E0h] BYREF
  int v23; // [sp+1Ch] [bp-DCh] BYREF
  int v24; // [sp+20h] [bp-D8h] BYREF
  int v25; // [sp+24h] [bp-D4h] BYREF
  unsigned __int16 v26[4]; // [sp+28h] [bp-D0h] BYREF
  char v27[16]; // [sp+30h] [bp-C8h] BYREF
  int v28[46]; // [sp+40h] [bp-B8h] BYREF

  v20 = 0;
  v21 = 0;
  v18 = 0;
  v22 = 0;
  v23 = 0;
  v0 = 0;
  v24 = 0;
  v1 = WdipSemOpenRegistryKey(L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Scenarios", 0, &v21);
  if ( v1 >= 0 )
  {
    v2 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
LABEL_4:
              if ( v20 )
              {
                ZwClose();
                v20 = 0;
              }
              if ( v18 )
              {
                ZwClose();
                v18 = 0;
              }
              if ( v22 )
              {
                ZwClose();
                v22 = 0;
              }
              memset(v28, 0, 152);
              v3 = ZwEnumerateKey();
              v19 = ++v2;
              if ( v3 == -2147483622 )
              {
                v1 = 0;
                WdipSemEnableAllProviders(-2147483622, v4);
                goto LABEL_46;
              }
              if ( v3 >= 0 )
              {
                if ( v28[3] >= 0x80u )
                {
                  v1 = -2147483643;
                  goto LABEL_46;
                }
                *((_WORD *)&v28[4] + ((unsigned int)v28[3] >> 1)) = 0;
                RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)&v28[4]);
                if ( RtlGUIDFromString(v26, v27) >= 0 )
                  break;
              }
            }
            v5 = WdipSemDisabledScenarioTable;
            if ( !WdipSemDisabledScenarioTable )
              break;
            v6 = *(_DWORD *)(WdipSemDisabledScenarioTable + 1024);
            v7 = 0;
            if ( !v6 )
              break;
            while ( memcmp((unsigned int)v27, v5, 16) )
            {
              ++v7;
              v5 += 16;
              if ( v7 >= v6 )
                goto LABEL_18;
            }
LABEL_3:
            v2 = v19;
          }
LABEL_18:
          v8 = WdipSemOpenRegistryKey(&v28[4], v21, &v20);
          v2 = v19;
        }
        while ( v8 < 0 );
        v25 = 1;
        v9 = 1;
        if ( WdipSemOpenRegistryKey(L"Config", v20, &v18) >= 0 )
          break;
LABEL_25:
        v10 = WdipSemOpenRegistryKey(L"Instrumentation", v20, &v22);
        v2 = v19;
        if ( v10 >= 0 )
        {
          v11 = 0;
          while ( 1 )
          {
            while ( 1 )
            {
              if ( v0 )
                WdipSemFreeScenario(v0);
              v12 = (_BYTE *)WdipSemFastAllocate(1, 624);
              v0 = (unsigned int)v12;
              if ( !v12 )
              {
                v1 = -1073741670;
                goto LABEL_46;
              }
              memset(v12, 0, 624);
              *(_BYTE *)(v0 + 616) = v9;
              v13 = WdipSemLoadNextScenario(v22, v11, v0);
              v14 = v13;
              ++v11;
              if ( v13 == -2147483622 )
                goto LABEL_3;
              if ( v13 >= 0 )
                break;
              if ( EtwEventEnabled(WdipSemRegHandle, dword_61CB14, (int)WDI_SEM_EVENT_INIT_MISCONFIG) )
                WdipSemWriteMisconfigEvent(v0, *(unsigned __int16 *)(v0 + 16), v14);
            }
            if ( (unsigned int)dword_61C880 >= 0x40 )
              break;
            v15 = dword_61C760;
            if ( WdipSemUpdateProviderTableWithScenario(v0) < 0
              || *(_DWORD *)(v0 + 52) && WdipSemAddScenarioToTable(v0) < 0 )
            {
              WdipSemRollBackProviderTable(v15);
            }
            else
            {
              WdipSemUpdateProviderEntriesForScenario(v0);
              if ( *(_DWORD *)(v0 + 52) )
                v0 = 0;
            }
          }
          v16 = EtwEventEnabled(WdipSemRegHandle, dword_61CB14, (int)WDI_SEM_EVENT_INIT_SCENARIO_MAX);
          v2 = v19;
          if ( !v16 )
            goto LABEL_4;
          WdipSemWriteScenarioLimitExceededEvent(WDI_SEM_EVENT_INIT_SCENARIO_MAX, v0, *(unsigned __int16 *)(v0 + 16));
          goto LABEL_3;
        }
      }
      if ( WdipSemQueryValueFromRegistry(v18, L"ScenarioExecutionEnabled", 4, 4, &v24, &v23) >= 0 )
      {
        v2 = v19;
        if ( !v24 )
          continue;
      }
      if ( WdipSemQueryValueFromRegistry(v18, L"ScenarioTimeoutEnabled", 4, 4, &v25, &v23) >= 0 && !v25 )
        v9 = 0;
      goto LABEL_25;
    }
  }
LABEL_46:
  if ( v21 )
  {
    ZwClose();
    v21 = 0;
  }
  if ( v20 )
  {
    ZwClose();
    v20 = 0;
  }
  if ( v18 )
  {
    ZwClose();
    v18 = 0;
  }
  if ( v22 )
    ZwClose();
  if ( v0 )
    WdipSemFreeScenario(v0);
  return v1;
}
