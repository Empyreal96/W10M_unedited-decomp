// KitLogFeatureUsage 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KitLogFeatureUsage(int a1, unsigned int a2, int a3)
{
  int v4; // r7 OVERLAPPED
  int v5; // r8 OVERLAPPED
  int v8; // r3
  const __int16 *v9; // r2
  _BYTE *v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v15; // [sp+8h] [bp-270h] BYREF
  char *v16; // [sp+Ch] [bp-26Ch]
  __int16 v17; // [sp+10h] [bp-268h] BYREF
  int v18[17]; // [sp+14h] [bp-264h] BYREF
  char v19[544]; // [sp+58h] [bp-220h] BYREF

  *(_QWORD *)&v4 = KitEtwHandle;
  v15 = 0;
  v16 = 0;
  v18[0] = a3;
  if ( KitEtwHandle && EtwEventEnabled(KitEtwHandle, SHIDWORD(KitEtwHandle), (int)KitFeatureIdUsedEvent) )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        a2 = *(_DWORD *)(a2 + 12);
      }
      else
      {
        if ( a3 != 2 )
          goto LABEL_10;
        v8 = *(_DWORD *)(a2 + 8);
        if ( !v8 )
          goto LABEL_10;
        a2 = *(_DWORD *)(v8 + 12);
      }
    }
    if ( a2 )
    {
      v10 = memset(v19, 0, 510);
      v15 = 33423360;
      v16 = v19;
      v13 = (unsigned int)KeGetCurrentIrql(v10) > 1 ? RtlPcToFileName(a2, (unsigned __int16 *)&v15, v11, v12) : RtlPcToFilePath(a2, &v15);
      *(_QWORD *)&v4 = KitEtwHandle;
      if ( v13 >= 0 )
      {
        v9 = (const __int16 *)v16;
        goto LABEL_16;
      }
    }
LABEL_10:
    v9 = L"Missing";
    v15 = NoCallerIdString;
    v18[0] = 3;
LABEL_16:
    v18[1] = a1;
    v18[2] = 0;
    v18[3] = 16;
    v18[4] = 0;
    v18[5] = (int)v18;
    v18[6] = 0;
    v18[7] = 4;
    v18[8] = 0;
    v17 = (unsigned __int16)v15 >> 1;
    v18[9] = (int)&v17;
    v18[10] = 0;
    v18[11] = 2;
    v18[12] = 0;
    v18[13] = (int)v9;
    v18[14] = 0;
    v18[15] = (unsigned __int16)v15;
    v18[16] = 0;
    return EtwWrite(v4, v5, (int)KitFeatureIdUsedEvent, 0);
  }
  return 0;
}
