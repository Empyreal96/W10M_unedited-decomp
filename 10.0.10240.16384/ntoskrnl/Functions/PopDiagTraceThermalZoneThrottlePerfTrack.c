// PopDiagTraceThermalZoneThrottlePerfTrack 
 
int __fastcall PopDiagTraceThermalZoneThrottlePerfTrack(int result, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r2
  int v7; // r1
  __int16 v8; // [sp+8h] [bp-58h] BYREF
  int *v9; // [sp+10h] [bp-50h]
  int v10; // [sp+14h] [bp-4Ch]
  int v11; // [sp+18h] [bp-48h]
  int v12; // [sp+1Ch] [bp-44h]
  int *v13; // [sp+20h] [bp-40h]
  int v14; // [sp+24h] [bp-3Ch]
  int v15; // [sp+28h] [bp-38h]
  int v16; // [sp+2Ch] [bp-34h]
  __int16 *v17; // [sp+30h] [bp-30h]
  int v18; // [sp+34h] [bp-2Ch]
  int v19; // [sp+38h] [bp-28h]
  int v20; // [sp+3Ch] [bp-24h]
  int v21; // [sp+40h] [bp-20h]
  int v22; // [sp+44h] [bp-1Ch]
  int v23; // [sp+48h] [bp-18h]
  int v24; // [sp+4Ch] [bp-14h]
  int varg_r0; // [sp+68h] [bp+8h] BYREF
  int varg_r1[3]; // [sp+6Ch] [bp+Ch] BYREF

  varg_r0 = result;
  varg_r1[0] = a2;
  varg_r1[1] = a3;
  varg_r1[2] = a4;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_PERFTRACK);
    if ( result )
    {
      result = IoGetDeviceAttachmentBaseRef(a3);
      v5 = result;
      if ( result )
        v6 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v6 = 0;
      if ( v6 )
      {
        v7 = *(unsigned __int16 *)(v6 + 160) >> 1;
        v9 = varg_r1;
        v10 = 0;
        v11 = 4;
        v12 = 0;
        v13 = &varg_r0;
        v14 = 0;
        v15 = 4;
        v16 = 0;
        v17 = &v8;
        v18 = 0;
        v19 = 2;
        v20 = 0;
        v8 = v7;
        v21 = *(_DWORD *)(v6 + 164);
        v22 = 0;
        v23 = 2 * v7;
        v24 = 0;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_THERMAL_PERFTRACK, 0);
      }
      if ( v5 )
        result = ObfDereferenceObjectWithTag(v5);
    }
  }
  return result;
}
