// PopBatteryUpdateAlarms 
 
int __fastcall PopBatteryUpdateAlarms(int a1, unsigned int a2)
{
  int v3; // r7
  int v4; // r1
  int v5; // r8
  unsigned int v6; // r6
  char *v7; // r5
  int v8; // r1
  unsigned int v9; // r3
  int v10; // r1
  unsigned int v12; // r3
  int v13; // [sp-4h] [bp-120h]
  int v14; // [sp-4h] [bp-120h]
  int v15; // [sp-4h] [bp-120h]
  unsigned int v16; // [sp+4h] [bp-118h] BYREF
  unsigned int v17; // [sp+8h] [bp-114h] BYREF
  int v18; // [sp+Ch] [bp-110h]
  char v19[264]; // [sp+14h] [bp-108h] BYREF

  v3 = a1;
  v18 = a1;
  memmove((int)v19, PopPolicy, 0xE8u);
  v5 = dword_61EC0C;
  if ( v3 )
  {
    a2 = 0;
    v6 = 4;
  }
  else
  {
    v6 = a2 + 1;
  }
  if ( a2 < v6 )
  {
    v7 = &v19[24 * a2 + 96];
    do
    {
      if ( PopGetPowerSettingValue((int)GUIDS_BATTERY_DISCHARGE_ACTION[a2], v4, v5, (int)&v16, v13, &v17) >= 0 )
      {
        v9 = v16;
        if ( v16 <= 6 )
        {
          *((_DWORD *)v7 + 2) = v16;
          *v7 = v9 != 0;
        }
      }
      if ( PopGetPowerSettingValue((int)GUIDS_BATTERY_DISCHARGE_LEVEL[a2], v8, v5, (int)&v16, v14, &v17) >= 0 )
      {
        v12 = v16;
        if ( v16 > 0x64 )
          v12 = 100;
        *((_DWORD *)v7 + 1) = v12;
      }
      if ( PopGetPowerSettingValue((int)GUIDS_BATTERY_DISCHARGE_FLAGS[a2], v10, v5, (int)&v16, v15, &v17) >= 0 )
        *((_DWORD *)v7 + 4) = v16 & 7;
      ++a2;
      v7 += 24;
    }
    while ( a2 < v6 );
    v3 = v18;
  }
  return PopApplyPolicy(1, v3, v19, 232);
}
