// EtwpRegisterProvider 
 
int __fastcall EtwpRegisterProvider(unsigned int a1, int a2, void (__fastcall *a3)(int, int, int *, int), int a4, int a5, _DWORD *a6)
{
  int v11; // r4
  int v12; // r5
  int v13; // r6
  __int64 v14; // kr00_8
  int v15; // r0
  int v16; // r3
  _DWORD *v17; // r7
  __int64 v18; // kr08_8
  unsigned __int8 v19; // r3
  unsigned int v20; // r7
  int v21; // r0
  int v22; // r8
  int v23; // r0
  int v24[4]; // [sp+18h] [bp-60h] BYREF
  int v25; // [sp+28h] [bp-50h] BYREF
  unsigned __int8 v26; // [sp+2Ch] [bp-4Ch]
  int v27; // [sp+48h] [bp-30h] BYREF
  __int64 v28; // [sp+4Ch] [bp-2Ch]
  int v29; // [sp+54h] [bp-24h]

  v24[1] = a1;
  v24[2] = a4;
  *a6 = 0;
  a6[1] = 0;
  v24[0] = 0;
  if ( !memcmp(a1, (unsigned int)SecurityProviderGuid, 16) )
    return sub_807B0C();
  if ( !a3 && a4 || a2 != 3 && (a2 != 2 || !a3) )
    return -1073741811;
  v11 = EtwpFindGuidEntryByGuid(a1, 0);
  if ( !v11 )
  {
    v11 = EtwpAddGuidEntry(a1, 0);
    if ( !v11 )
      return -1073741801;
  }
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v12 = EtwpAddKmRegEntry(v11, a2, a3, a4, v24);
  if ( v12 >= 0 )
  {
    v13 = v24[0];
    *(_DWORD *)(v24[0] + 24) = a5;
    *(_QWORD *)a6 = v13;
    if ( *(_DWORD *)(v11 + 56) )
      EtwpUpdateEnableMask(v11, (*(_BYTE *)(v13 + 50) & 8) != 0, 0, (_BYTE *)(v13 + 51));
    EtwpComputeRegEntryEnableInfo(v13, &v25);
    if ( (*(_BYTE *)(v13 + 50) & 8) != 0 && (*(_BYTE *)(v11 + 51) & 1) != 0 )
    {
      v15 = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(v11 + 48), 0);
      v17 = (_DWORD *)v15;
      if ( v15 )
      {
        EtwpProviderArrivalCallback(v15, 0, v13, v16);
        EtwpReleaseLoggerContext(v17, 0);
      }
    }
    if ( a3 )
    {
      if ( (*(_BYTE *)(v13 + 50) & 8) != 0 )
      {
        if ( (*(_BYTE *)(v11 + 51) & 1) != 0 )
        {
          v18 = *(_QWORD *)(v11 + 40);
          LOWORD(v27) = *(_WORD *)(v11 + 48);
          v19 = *(_BYTE *)(v11 + 50);
          v28 = v18;
          v29 = 0;
          HIWORD(v27) = v19;
          a3(v11 + 12, 1, &v27, a4);
        }
      }
      else if ( v25 )
      {
        v20 = 0;
        v21 = EtwpGetSchematizedFilterSize(v11);
        v22 = v21;
        if ( v21 )
        {
          v23 = ExAllocatePoolWithTag(1, v21, 1182233669);
          v20 = v23;
          if ( v23 )
          {
            v27 = v23;
            LODWORD(v28) = 0;
            HIDWORD(v28) = v22;
            v29 = 0x80000000;
            EtwpCopySchematizedFilters(v23, v11, *(unsigned __int8 *)(v13 + 51));
          }
        }
        ((void (__fastcall *)(GUID *, int, _DWORD))a3)(&NullGuid, 1, v26);
        if ( v20 )
          ExFreePoolWithTag(v20);
      }
    }
    v14 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_PROVIDER_REGISTER) )
      EtwpEventWriteTemplateSessAndProv(v14, HIDWORD(v14), ETW_EVENT_PROVIDER_REGISTER);
  }
  KeReleaseMutex((int)&EtwpNotificationMutex);
  EtwpUnreferenceGuidEntry(v11);
  return v12;
}
