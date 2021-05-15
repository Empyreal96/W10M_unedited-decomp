// PpmEventBiosCapChange 
 
int __fastcall PpmEventBiosCapChange(int result, int a2)
{
  int v2; // r6
  __int64 v3; // kr00_8
  __int16 v4; // [sp+8h] [bp-48h] BYREF
  __int16 *v5; // [sp+10h] [bp-40h]
  int v6; // [sp+14h] [bp-3Ch]
  int v7; // [sp+18h] [bp-38h]
  int v8; // [sp+1Ch] [bp-34h]
  int v9; // [sp+20h] [bp-30h]
  int v10; // [sp+24h] [bp-2Ch]
  int v11; // [sp+28h] [bp-28h]
  int v12; // [sp+2Ch] [bp-24h]
  int *v13; // [sp+30h] [bp-20h]
  int v14; // [sp+34h] [bp-1Ch]
  int v15; // [sp+38h] [bp-18h]
  int v16; // [sp+3Ch] [bp-14h]
  int anonymous0; // [sp+58h] [bp+8h]
  int varsC; // [sp+5Ch] [bp+Ch] BYREF

  anonymous0 = result;
  varsC = a2;
  v2 = result;
  if ( PpmEtwRegistered )
  {
    v3 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_BIOS_CAP_CHANGE);
    if ( result )
    {
      v4 = *(unsigned __int8 *)(v2 + 1052);
      v5 = &v4;
      v6 = 0;
      v7 = 2;
      v8 = 0;
      v9 = v2 + 1053;
      v10 = 0;
      v11 = 1;
      v12 = 0;
      v13 = &varsC;
      v14 = 0;
      v15 = 4;
      v16 = 0;
      result = EtwWrite(v3, SHIDWORD(v3), (int)PPM_ETW_BIOS_CAP_CHANGE, 0);
    }
  }
  return result;
}
