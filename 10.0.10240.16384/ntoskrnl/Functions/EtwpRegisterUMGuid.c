// EtwpRegisterUMGuid 
 
int __fastcall EtwpRegisterUMGuid(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  int v6; // r4
  int v7; // r8
  int v8; // r7
  int v9; // r5
  int v10; // r7
  int v11; // r0
  unsigned __int8 v12; // r3
  int v13; // r8
  int v14; // r0
  int v15; // r3
  __int64 v16; // kr00_8
  int v18; // r0
  int v19; // r8
  unsigned __int8 v20; // r3
  int v21; // r2
  int v22; // [sp+0h] [bp-48h]
  int v23; // [sp+4h] [bp-44h]
  int v24; // [sp+8h] [bp-40h]
  char v25[4]; // [sp+10h] [bp-38h] BYREF
  int v26; // [sp+14h] [bp-34h] BYREF
  int v27; // [sp+18h] [bp-30h] BYREF
  int v28; // [sp+20h] [bp-28h]

  v27 = 0;
  v6 = 0;
  v7 = *(_DWORD *)(a1 + 16);
  v28 = *(_DWORD *)(a1 + 20);
  v26 = 0;
  if ( !memcmp(a1, (unsigned int)SecurityProviderGuid, 16) )
    return sub_7C5018();
  v8 = v7 != 3 && v7 != 2;
  v9 = EtwpFindGuidEntryByGuid(a1, v8);
  if ( !v9 )
  {
    v9 = EtwpAddGuidEntry(a1, v8);
    if ( !v9 )
      return -1073741801;
  }
  v10 = EtwpAccessCheck(*(_DWORD *)(v9 + 36), 2048, 0);
  if ( v10 >= 0 )
  {
    KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
    *a3 = 160;
    v11 = EtwpGetSchematizedFilterSize(v9, 255);
    if ( v11 )
      *a3 = v11 + 176;
    if ( *a3 > a2 )
    {
      v10 = -1073741789;
    }
    else
    {
      v10 = EtwpAddUmRegEntry(v9, v7, v28, *(_DWORD *)(a1 + 32), &v26, (int)&v27);
      v6 = v26;
      if ( v10 >= 0 )
      {
        *(_QWORD *)(a1 + 24) = v27;
        if ( *(_DWORD *)(v9 + 56) )
        {
          if ( (*(_BYTE *)(v6 + 50) & 8) != 0 )
            EtwpUpdateEnableMask(v9, 1, 1, v6 + 51, v22);
          else
            EtwpUpdateEnableMask(v9, 0, 1, v6 + 51, v22);
        }
        v25[0] = *(_BYTE *)(v6 + 51);
        EtwpApplyScopeFilters(v6, (*(_BYTE *)(v6 + 50) & 8) != 0, 0, v25, v22, v23, v24);
        v12 = v25[0];
        if ( (*(_BYTE *)(v6 + 50) & 8) == 0 )
          v12 = v25[0] & *(_BYTE *)(v6 + 51);
        v13 = v12;
        *(_BYTE *)(v6 + 51) = v12;
        if ( v12 )
        {
          EtwpComputeRegEntryEnableInfo(v6, a1 + 112);
          *(_DWORD *)(a1 + 152) = *(_BYTE *)(v9 + 51) & 1;
          v20 = *(_BYTE *)(v9 + 50);
          LOWORD(v28) = *(_WORD *)(v9 + 48);
          HIWORD(v28) = v20;
          v21 = *(_DWORD *)(v9 + 40);
          *(_DWORD *)(a1 + 144) = v28;
          *(_DWORD *)(a1 + 148) = v21;
        }
        else
        {
          memset((_BYTE *)(a1 + 112), 0, 32);
          *(_DWORD *)(a1 + 152) = 0;
          *(_DWORD *)(a1 + 144) = 0;
          *(_DWORD *)(a1 + 148) = 0;
        }
        *a3 = 160;
        v14 = EtwpGetSchematizedFilterSize(v9, v13);
        if ( v14 )
        {
          *a3 = v14 + 176;
          *(_DWORD *)(a1 + 168) = v14;
          *(_DWORD *)(a1 + 172) = 0x80000000;
          *(_DWORD *)(a1 + 160) = 136;
          *(_DWORD *)(a1 + 164) = 0;
          EtwpCopySchematizedFilters(a1 + 176, v9, v13);
          v15 = 1;
        }
        else
        {
          v15 = 0;
        }
        *(_DWORD *)(a1 + 156) = v15;
        *(_DWORD *)(a1 + 44) = *a3;
        if ( (*(_BYTE *)(v6 + 50) & 8) != 0 )
        {
          if ( v13 )
          {
            v18 = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(v9 + 48), 0);
            v19 = v18;
            if ( v18 )
            {
              EtwpProviderArrivalCallback(v18, 1, v6);
              EtwpReleaseLoggerContext(v19, 0);
            }
          }
        }
        v16 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
        if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_PROVIDER_REGISTER) )
          EtwpEventWriteTemplateSessAndProv(v16, HIDWORD(v16), ETW_EVENT_PROVIDER_REGISTER);
      }
    }
    KeReleaseMutex((int)&EtwpNotificationMutex);
    if ( v6 )
      ObfDereferenceObject(v6);
  }
  EtwpUnreferenceGuidEntry(v9);
  return v10;
}
