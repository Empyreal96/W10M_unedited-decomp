// WdipSemLoadLocalGroupPolicy 
 
int __fastcall WdipSemLoadLocalGroupPolicy(int a1)
{
  int v2; // r0
  int v3; // r8
  int v4; // r4
  int v5; // r0
  int v6; // r4
  _BYTE *v7; // r0
  unsigned int v8; // r3
  _DWORD *v9; // r5
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v14; // [sp+8h] [bp-D8h] BYREF
  int v15; // [sp+Ch] [bp-D4h] BYREF
  int v16; // [sp+10h] [bp-D0h] BYREF
  unsigned __int16 v17[4]; // [sp+18h] [bp-C8h] BYREF
  _DWORD v18[4]; // [sp+20h] [bp-C0h] BYREF
  int v19[44]; // [sp+30h] [bp-B0h] BYREF

  v2 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v3 = 0;
  if ( !a1 )
    return -1073741811;
  while ( 1 )
  {
    if ( v2 )
    {
      ZwClose();
      v14 = 0;
    }
    memset(v19, 0, 152);
    v5 = ZwEnumerateKey();
    ++v3;
    if ( v5 == -2147483622 )
      break;
    if ( v5 >= 0 )
    {
      if ( v19[3] >= 0x80u )
      {
        v4 = -2147483643;
        goto LABEL_22;
      }
      *((_WORD *)&v19[4] + ((unsigned int)v19[3] >> 1)) = 0;
      RtlInitUnicodeString((unsigned int)v17, (unsigned __int16 *)&v19[4]);
      if ( RtlGUIDFromString(v17, v18) >= 0
        && WdipSemOpenRegistryKey(&v19[4], a1, &v14) >= 0
        && WdipSemQueryValueFromRegistry(v14, L"ScenarioExecutionEnabled", 4, 4, &v15, &v16) >= 0
        && !v15 )
      {
        v6 = WdipSemDisabledScenarioTable;
        if ( !WdipSemDisabledScenarioTable )
        {
          v7 = (_BYTE *)ExAllocatePoolWithTag(1, 1028, 1934181463);
          v6 = (int)v7;
          WdipSemDisabledScenarioTable = (int)v7;
          if ( !v7 )
          {
            v4 = -1073741670;
            goto LABEL_22;
          }
          memset(v7, 0, 1028);
        }
        v8 = *(_DWORD *)(v6 + 1024);
        if ( v8 >= 0x40 )
        {
          v4 = -1073741823;
          goto LABEL_22;
        }
        v9 = (_DWORD *)(v6 + 16 * v8);
        *(_DWORD *)(v6 + 1024) = v8 + 1;
        v10 = v18[1];
        v11 = v18[2];
        v12 = v18[3];
        *v9 = v18[0];
        v9[1] = v10;
        v9[2] = v11;
        v9[3] = v12;
      }
    }
    v2 = v14;
  }
  v4 = 0;
LABEL_22:
  if ( v14 )
    ZwClose();
  return v4;
}
