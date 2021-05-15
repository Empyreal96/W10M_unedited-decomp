// RtlSetActiveTimeBias 
 
int __fastcall RtlSetActiveTimeBias(int a1, int a2)
{
  int v2; // r4
  int v4; // [sp+0h] [bp-58h]
  unsigned __int16 *v5; // [sp+8h] [bp-50h] BYREF
  int v6; // [sp+Ch] [bp-4Ch] BYREF
  int var48[19]; // [sp+10h] [bp-48h] BYREF
  int vars8; // [sp+60h] [bp+8h]
  int anonymous0; // [sp+64h] [bp+Ch]

  vars8 = a1;
  anonymous0 = a2;
  v6 = 0;
  v2 = RtlpGetRegistryHandle(2, (int)L"TimeZoneInformation", 1, (int *)&v5);
  if ( v2 >= 0 )
  {
    memset(var48, 0, 56);
    var48[1] = 292;
    var48[2] = (int)L"ActiveTimeBias";
    var48[3] = (int)&v6;
    var48[4] = 0x4000000;
    v2 = RtlpQueryRegistryValues(0x40000000, v5, var48, 0, v4, 1u);
    if ( v2 < 0 || v6 != vars8 )
      return sub_80BB08();
    ZwClose();
  }
  return v2;
}
