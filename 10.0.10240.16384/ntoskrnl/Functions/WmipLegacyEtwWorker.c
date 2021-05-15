// WmipLegacyEtwWorker 
 
signed int __fastcall WmipLegacyEtwWorker(_DWORD *a1)
{
  int v2; // r0
  int v3; // r3
  _DWORD *v4; // r6

  WmipReferenceEntry((int)a1);
  v2 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v3 = a1[24];
  if ( v3 )
    v4 = (_DWORD *)(v3 + 12);
  else
    v4 = a1 + 25;
  if ( (_DWORD *)*v4 != v4 )
    return sub_818E14(v2);
  a1[2] &= 0xFFFFFFEF;
  a1[24] = 0;
  KeReleaseMutex((int)&WmipSMMutex);
  return WmipUnreferenceEntry((int *)&WmipGEChunkInfo, a1);
}
