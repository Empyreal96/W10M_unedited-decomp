// WmipDoDisableRequest 
 
int __fastcall WmipDoDisableRequest(_DWORD *a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r6
  int v8; // r3
  int v9; // r0

  do
  {
    if ( a2 )
      v6 = 5;
    else
      v6 = 7;
    v7 = WmipSendEnableDisableRequest(v6, a1, a2);
    if ( a2 )
      v8 = a1[14];
    else
      v8 = a1[15];
    if ( !v8 )
      break;
    v9 = a2 ? 4 : 6;
    v7 = WmipSendEnableDisableRequest(v9, a1, a2);
  }
  while ( !(a2 ? a1[14] : a1[15]) );
  a1[2] &= ~a3;
  if ( !a2 )
    WmipReleaseCollectionEnabled((int)a1);
  return v7;
}
