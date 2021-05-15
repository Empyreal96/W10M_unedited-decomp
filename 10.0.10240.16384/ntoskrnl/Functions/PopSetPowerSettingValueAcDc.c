// PopSetPowerSettingValueAcDc 
 
int __fastcall PopSetPowerSettingValueAcDc(int *a1, unsigned int a2, int a3)
{
  int v6; // r4
  int v7; // r0
  int result; // r0

  v6 = 0;
  v7 = PopSetPowerSettingValue(a1, -1, 0, a2, a3);
  if ( v7 < 0 )
    v6 = v7;
  if ( PopSetPowerSettingValue(a1, -1, 1, a2, a3) >= 0 )
    result = v6;
  else
    result = sub_7F2668();
  return result;
}
