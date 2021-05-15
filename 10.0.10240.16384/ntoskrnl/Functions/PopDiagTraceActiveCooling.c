// PopDiagTraceActiveCooling 
 
int __fastcall PopDiagTraceActiveCooling(int result, int a2, int a3, int a4)
{
  int v7; // r9
  __int64 v8; // kr00_8
  int v9; // r5
  int v10; // r1
  int v11; // r2
  char *v12; // r7
  char *v13; // r0
  int v14; // r8
  int *v15; // r2
  _BOOL2 v16; // [sp+8h] [bp-158h] BYREF
  __int16 v17; // [sp+Ah] [bp-156h] BYREF
  __int64 v18; // [sp+10h] [bp-150h] BYREF
  unsigned int v19; // [sp+18h] [bp-148h] BYREF
  int v20[18]; // [sp+20h] [bp-140h] BYREF
  char v21; // [sp+68h] [bp-F8h] BYREF
  unsigned int *v22; // [sp+108h] [bp-58h]
  int v23; // [sp+10Ch] [bp-54h]
  int v24; // [sp+110h] [bp-50h]
  int v25; // [sp+114h] [bp-4Ch]
  char v26[72]; // [sp+118h] [bp-48h] BYREF

  v7 = result;
  if ( PopDiagHandleRegistered )
  {
    v8 = *(_QWORD *)&PopDiagHandle;
    if ( (a4
       || (result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_ACTIVE_COOLING_DIAGNOSTIC)) != 0)
      && (a4 != 1 || (result = EtwEventEnabled(v8, SHIDWORD(v8), (int)POP_ETW_EVENT_ACTIVE_COOLING_OPERATIONAL)) != 0)
      && (!a4 || a4 == 1) )
    {
      result = IoGetDeviceAttachmentBaseRef(a2);
      v9 = result;
      if ( result )
        v10 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
      else
        v10 = 0;
      if ( v10 )
      {
        v11 = *(unsigned __int16 *)(v10 + 160) >> 1;
        v20[2] = (int)&v17;
        v20[3] = 0;
        v20[4] = 2;
        v20[5] = 0;
        v17 = v11;
        v20[6] = *(_DWORD *)(v10 + 164);
        v20[7] = 0;
        v20[8] = 2 * v11;
        v20[9] = 0;
        v18 = 0i64;
        KeQuerySystemTime(&v18);
        ExSystemTimeToLocalTime(&v18, v20);
        v20[10] = (int)v20;
        v20[11] = 0;
        v20[12] = 8;
        v20[13] = 0;
        v16 = a3 != 0;
        v20[14] = (int)&v16;
        v20[15] = 0;
        v20[16] = 2;
        v20[17] = 0;
        v12 = v26;
        v13 = &v21;
        v14 = 10;
        do
        {
          *(_DWORD *)v12 = *(_DWORD *)&v12[v7 - (_DWORD)v26 + 36] / 0xAu;
          *((_DWORD *)v13 + 1) = 0;
          *((_DWORD *)v13 + 2) = 4;
          *(_DWORD *)v13 = v12;
          *((_DWORD *)v13 + 3) = 0;
          v13 += 16;
          v12 += 4;
          --v14;
        }
        while ( v14 );
        v19 = *(_DWORD *)(v7 + 16) / 0xAu;
        v22 = &v19;
        v23 = 0;
        v24 = 4;
        v25 = 0;
        if ( a4 )
          v15 = POP_ETW_EVENT_ACTIVE_COOLING_OPERATIONAL;
        else
          v15 = POP_ETW_EVENT_ACTIVE_COOLING_DIAGNOSTIC;
        result = EtwWrite(PopDiagHandle, dword_61E154, (int)v15, 0);
      }
      if ( v9 )
        result = ObfDereferenceObject(v9);
    }
  }
  return result;
}
