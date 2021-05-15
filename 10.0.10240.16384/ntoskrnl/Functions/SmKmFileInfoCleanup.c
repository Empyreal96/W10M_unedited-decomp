// SmKmFileInfoCleanup 
 
BOOL __fastcall SmKmFileInfoCleanup(_DWORD *a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0

  v2 = IoSetThreadHardErrorMode(0);
  v3 = a1[4];
  if ( v3 )
    PnpUnregisterPlugPlayNotification(v3, 0);
  v4 = a1[2];
  if ( v4 )
    ObfDereferenceObject(v4);
  v5 = a1[5];
  if ( v5 )
  {
    IoReuseIrp(v5, 0);
    SmKmSendUsageNotification(a1[5], a1[1], 1);
    IoFreeIrp(a1[5]);
  }
  v6 = a1[1];
  if ( v6 )
    ObfDereferenceObject(v6);
  if ( *a1 )
    ZwClose();
  v7 = a1[6];
  if ( v7 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v7);
  return IoSetThreadHardErrorMode(v2);
}
