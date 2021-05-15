// WmipDSCleanup 
 
unsigned int __fastcall WmipDSCleanup(_DWORD *a1)
{
  _DWORD *v2; // r6
  unsigned int i; // r5
  _DWORD *v4; // r1
  unsigned int result; // r0
  _DWORD *v6; // r5
  int v7; // r2

  if ( (a1[2] & 1) == 0 )
    sub_81A5C8();
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v2 = (_DWORD *)a1[5];
  while ( v2 != a1 + 5 )
  {
    v6 = v2 - 5;
    if ( *(v2 - 5) )
    {
      WmipUnlinkInstanceSetFromGuidEntry(v2 - 5);
      v2[3] = 0;
    }
    v7 = v2[2];
    if ( v7 && (*(v2 - 3) & 8) == 0 )
    {
      if ( !memcmp(v7 + 40, (unsigned int)WmipBinaryMofGuid, 16) )
      {
        KeReleaseMutex((int)&WmipSMMutex);
        WmipGenerateBinaryMofNotification((int)(v2 - 5), &GUID_MOF_RESOURCE_REMOVED_NOTIFICATION);
        KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      }
      WmipUnreferenceEntry((int *)&WmipGEChunkInfo, (_DWORD *)v2[2]);
    }
    v2[2] = 0;
    v2 = (_DWORD *)*v2;
    WmipUnreferenceEntry((int *)&WmipISChunkInfo, v6);
  }
  KeReleaseMutex((int)&WmipSMMutex);
  for ( i = 0; i < a1[9]; ++i )
  {
    v4 = *(_DWORD **)(a1[10] + 4 * i);
    if ( v4 )
      WmipUnreferenceEntry((int *)&WmipMRChunkInfo, v4);
  }
  result = a1[10];
  if ( (_DWORD *)result != a1 + 11 )
  {
    result = ExFreePoolWithTag(result);
    a1[10] = 0;
  }
  return result;
}
