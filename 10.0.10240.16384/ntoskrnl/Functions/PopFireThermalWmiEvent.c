// PopFireThermalWmiEvent 
 
__int64 __fastcall PopFireThermalWmiEvent(unsigned __int8 a1)
{
  int v1; // r4
  _DWORD v3[6]; // [sp+0h] [bp-18h] BYREF

  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[0] = a1;
  v1 = KfRaiseIrql(2);
  PpmFireWmiEvent(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4528, PPM_THERMAL_POLICY_CHANGE_GUID, 16, v3);
  return KfLowerIrql(v1);
}
