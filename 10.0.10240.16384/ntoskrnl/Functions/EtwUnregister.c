// EtwUnregister 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwUnregister(unsigned int a1)
{
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED
  __int64 v4; // kr00_8
  __int64 v5; // kr08_8
  int v6; // r0

  if ( !a1 )
    return -1073741816;
  if ( (*(_BYTE *)(a1 + 50) & 1) == 0 )
    sub_7D6B68();
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  *(_QWORD *)&v2 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v3 != a1 )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  v4 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v4 + 4) != a1 + 8 || *(_DWORD *)HIDWORD(v4) != a1 + 8 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  KeReleaseMutex((int)&EtwpNotificationMutex);
  v5 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
  if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_PROVIDER_UNREGISTERS) )
    EtwpEventWriteTemplateSessAndProv(v5, HIDWORD(v5), ETW_EVENT_PROVIDER_UNREGISTERS);
  EtwpUnreferenceGuidEntry(*(_DWORD *)(a1 + 16));
  v6 = *(_DWORD *)(a1 + 20);
  if ( v6 )
    EtwpUnreferenceGuidEntry(v6);
  EtwpReleaseProviderTraitsReference(a1);
  ExFreePoolWithTag(a1);
  return 0;
}
