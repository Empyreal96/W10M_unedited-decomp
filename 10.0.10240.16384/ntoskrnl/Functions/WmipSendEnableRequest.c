// WmipSendEnableRequest 
 
int __fastcall WmipSendEnableRequest(_DWORD *a1, int a2)
{
  int v4; // r2
  int v5; // r6
  int v6; // r7
  int v8; // r0
  int v9; // r3

  if ( a2 )
  {
    v4 = a1[14];
    v5 = 2;
    a1[14] = v4 + 1;
  }
  else
  {
    v4 = a1[15];
    v5 = 4;
    a1[15] = v4 + 1;
  }
  if ( v4 || (a1[2] & v5) != 0 )
  {
    if ( !a2 && (a1[2] & v5) != 0 )
      WmipWaitForCollectionEnabled(a1);
    return 0;
  }
  WmipReferenceEntry((int)a1);
  a1[2] |= v5;
  if ( a2 )
    v8 = 4;
  else
    v8 = 6;
  v6 = WmipSendEnableDisableRequest(v8, a1, a2);
  if ( a2 )
    v9 = a1[14];
  else
    v9 = a1[15];
  if ( v9 )
  {
    a1[2] &= ~v5;
    if ( !a2 )
      WmipReleaseCollectionEnabled(a1);
    WmipUnreferenceEntry((int *)&WmipGEChunkInfo, a1);
    return v6;
  }
  return sub_815A34();
}
