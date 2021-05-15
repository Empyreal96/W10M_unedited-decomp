// WmipGenerateRegistrationNotification 
 
signed int __fastcall WmipGenerateRegistrationNotification(_DWORD *a1, int a2)
{
  _DWORD *v4; // r4
  int v5; // r1
  unsigned int v6; // r5
  int v7; // r5
  int v8; // r0
  int v10; // [sp+8h] [bp-28h] BYREF
  unsigned int v11; // [sp+Ch] [bp-24h] BYREF
  int v12[8]; // [sp+10h] [bp-20h] BYREF

  WmipReferenceEntry((int)a1);
  v4 = (_DWORD *)a1[5];
  v5 = 0;
  v6 = 0;
  v10 = 0;
  v11 = 0;
  v12[0] = 0;
  if ( v4 != a1 + 5 )
  {
    do
    {
      if ( (*(v4 - 3) & 8) == 0 )
      {
        v7 = v4[2];
        v8 = WmipCachePtrs(v7 + 40, v4 - 5, &v10, v12, &v11);
        if ( a2 != 1 )
          return sub_7CBBB0(v8);
        WmipEnableCollectionForNewGuid(v7 + 40, v4 - 5);
      }
      v4 = (_DWORD *)*v4;
    }
    while ( v4 != a1 + 5 );
    v5 = v10;
    v6 = v11;
  }
  WmipSendGuidUpdateNotifications(a2, v5, v6);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return WmipUnreferenceEntry((int *)&WmipDSChunkInfo, a1);
}
