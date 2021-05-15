// PpmEventThermalCapChange 
 
int *__fastcall PpmEventThermalCapChange(int *result, int a2)
{
  int v2; // r3
  int *v3; // r4
  __int64 v4; // kr00_8
  __int16 v5; // [sp+8h] [bp-68h] BYREF
  int v6[4]; // [sp+10h] [bp-60h] BYREF
  int var50[23]; // [sp+20h] [bp-50h] BYREF
  int varsC; // [sp+7Ch] [bp+Ch] BYREF

  var50[22] = (int)result;
  varsC = a2;
  v2 = result[262];
  varsC = a2;
  v3 = result;
  var50[2] = v2;
  var50[3] = 0;
  var50[0] = a2;
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v6[0] = (int)var50;
    v6[1] = 0;
    v6[2] = 16;
    v6[3] = 0;
    result = EtwTraceKernelEvent(v6, 1, 0x80008000, 4662, 4200450);
  }
  if ( WmiThermalEventEnabled )
    result = (int *)PpmFireWmiEvent((int)(v3 + 780), PPM_THERMALCONSTRAINT_GUID, 0x10u, (int)var50);
  if ( PpmEtwRegistered )
  {
    v4 = *(_QWORD *)&PpmEtwHandle;
    result = (int *)EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_THERMAL_CAP_CHANGE);
    if ( result )
    {
      v5 = *((unsigned __int8 *)v3 + 1052);
      var50[4] = (int)&v5;
      var50[5] = 0;
      var50[6] = 2;
      var50[7] = 0;
      var50[8] = (int)v3 + 1053;
      var50[9] = 0;
      var50[10] = 1;
      var50[11] = 0;
      var50[12] = (int)&varsC;
      var50[13] = 0;
      var50[14] = 4;
      var50[15] = 0;
      result = (int *)EtwWrite(v4, SHIDWORD(v4), (int)PPM_ETW_THERMAL_CAP_CHANGE, 0);
    }
  }
  return result;
}
