// WdipSemLogInflightLimitExceededInformation 
 
int __fastcall WdipSemLogInflightLimitExceededInformation(int a1, int a2, int a3)
{
  int v6; // r4
  int *v7; // r5
  int v8; // r5
  int v9; // r0
  unsigned int v10; // r5
  int *v11; // r6
  int v12; // t1
  int v14; // [sp+0h] [bp-220h] BYREF
  int v15[134]; // [sp+8h] [bp-218h] BYREF

  v14 = 0;
  v6 = 0;
  memset(v15, 0, 504);
  if ( a1 && a3 )
  {
    if ( EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_SCENARIO_INFLIGHT_MAX)
      || ((int (*)(void))WdipSemSqmEnabled)() )
    {
      v7 = (int *)WdipSemEnabledInstanceTable;
      if ( &WdipSemEnabledInstanceTable == (int *)WdipSemEnabledInstanceTable )
      {
LABEL_14:
        v6 = -1073741823;
      }
      else
      {
        while ( 1 )
        {
          v6 = WdipSemUpdateInflightScenarioTable(v7[6], *(unsigned __int16 *)(v7[6] + 16), v15, &v14);
          if ( v6 < 0 )
            break;
          v7 = (int *)*v7;
          if ( &WdipSemEnabledInstanceTable == v7 )
          {
            v8 = v14;
            if ( !v14 )
              goto LABEL_14;
            v9 = EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_SCENARIO_INFLIGHT_MAX);
            if ( v9 )
              v9 = WdipSemWriteInflightLimitExceededEvent(a1, a2, a3, v15);
            if ( WdipSemSqmEnabled(v9) )
              WdipSemUpdateFrequentScenarioTable(v8);
            break;
          }
        }
      }
    }
  }
  else
  {
    v6 = -1073741811;
  }
  v10 = 0;
  if ( v15[125] )
  {
    v11 = v15;
    do
    {
      v12 = *v11++;
      WdipSemFastFree(5, v12);
      ++v10;
    }
    while ( v10 < v15[125] );
  }
  return v6;
}
