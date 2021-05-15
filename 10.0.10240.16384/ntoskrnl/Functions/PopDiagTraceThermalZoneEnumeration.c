// PopDiagTraceThermalZoneEnumeration 
 
int __fastcall PopDiagTraceThermalZoneEnumeration(int result, int a2)
{
  _DWORD *v2; // r5
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r7
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  __int16 v8; // [sp+18h] [bp-1B8h]
  int v9; // [sp+28h] [bp-1A8h]
  unsigned int v10; // [sp+2Ch] [bp-1A4h]

  v2 = (_DWORD *)result;
  if ( PopDiagHandleRegistered )
  {
    result = IoGetDeviceAttachmentBaseRef(a2);
    v3 = result;
    if ( result )
      v4 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
    else
      v4 = 0;
    if ( v4 )
    {
      v9 = *(unsigned __int16 *)(v4 + 160) >> 1;
      v8 = *(_WORD *)(v4 + 160) >> 1;
      v5 = v2[5] / 0xAu;
      v6 = v2[7];
      v7 = v2[19];
      v10 = v2[6] / 0xAu;
      if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_ZONE_ENUMERATED) )
        return sub_552038();
      result = PopSqmThermalZoneEnumeration(
                 v4 + 160,
                 v5,
                 v2[1],
                 v2[2],
                 v2[3],
                 v2[9] / 0xAu,
                 v2[10] / 0xAu,
                 v6 / 0xA,
                 v7 / 0xA,
                 v10,
                 v8,
                 v5,
                 v6 / 0xA,
                 v7 / 0xA,
                 v9);
    }
    if ( v3 )
      result = ObfDereferenceObjectWithTag(v3);
  }
  return result;
}
