// PopSetNewPolicyValue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopSetNewPolicyValue(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r7 OVERLAPPED
  unsigned int v10; // r8 OVERLAPPED
  _DWORD v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v5 = 0;
  v6 = RtlStringFromGUIDEx(a1 + 20, v12, 1);
  if ( v6 >= 0 )
  {
    if ( (PoDebug & 0x10000000) != 0 )
      return sub_7C3D8C(v6, v7, v8, PoDebug);
    RtlFreeAnsiString(v12);
  }
  if ( !PopStateIsSessionSpecific(a1 + 20) )
  {
    *(_QWORD *)&v9 = *(_QWORD *)(a1 + 52);
    if ( memcmp(a1 + 36, (unsigned int)&GUID_PROCESSOR_SETTINGS_SUBGROUP, 16) )
      goto LABEL_7;
    v5 = PpmSetProfilePolicySetting(a1 + 4, a1 + 20, v9, a1 + 60, v10);
    if ( v5 == -1073741275 )
      v5 = 0;
    if ( !memcmp(a1 + 4, (unsigned int)&NullGuid, 16) )
    {
LABEL_7:
      v5 = PopSetPowerSettingValue((int *)(a1 + 20), -1, v9, v10, a1 + 60);
      if ( v5 < 0 && (PoDebug & 1) != 0 )
        DbgPrint("%s: PopSetPowerSettingValue() 0x%x\n", "PopSetNewPolicyValue", v5);
    }
  }
  return v5;
}
