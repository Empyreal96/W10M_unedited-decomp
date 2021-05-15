// PopDiagTraceThermalZoneThrottleDurationPerfTrack 
 
int __fastcall PopDiagTraceThermalZoneThrottleDurationPerfTrack(int result, int a2)
{
  int v3; // r4
  int v4; // r2
  int v5; // r1
  __int16 v6; // [sp+8h] [bp-48h] BYREF
  _DWORD *v7; // [sp+10h] [bp-40h]
  int v8; // [sp+14h] [bp-3Ch]
  int v9; // [sp+18h] [bp-38h]
  int v10; // [sp+1Ch] [bp-34h]
  __int16 *v11; // [sp+20h] [bp-30h]
  int v12; // [sp+24h] [bp-2Ch]
  int v13; // [sp+28h] [bp-28h]
  int v14; // [sp+2Ch] [bp-24h]
  int v15; // [sp+30h] [bp-20h]
  int v16; // [sp+34h] [bp-1Ch]
  int v17; // [sp+38h] [bp-18h]
  int v18; // [sp+3Ch] [bp-14h]
  _DWORD vars8[2]; // [sp+58h] [bp+8h] BYREF

  vars8[0] = result;
  vars8[1] = a2;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_DURATION_PERFTRACK);
    if ( result )
    {
      result = IoGetDeviceAttachmentBaseRef(a2);
      v3 = result;
      if ( result )
        v4 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v4 = 0;
      if ( v4 )
      {
        v5 = *(unsigned __int16 *)(v4 + 160) >> 1;
        v7 = vars8;
        v8 = 0;
        v9 = 4;
        v10 = 0;
        v11 = &v6;
        v12 = 0;
        v13 = 2;
        v14 = 0;
        v6 = v5;
        v15 = *(_DWORD *)(v4 + 164);
        v16 = 0;
        v17 = 2 * v5;
        v18 = 0;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_DURATION_PERFTRACK, 0);
      }
      if ( v3 )
        result = ObfDereferenceObjectWithTag(v3);
    }
  }
  return result;
}
