// WmipSendDisableRequest 
 
int __fastcall WmipSendDisableRequest(_DWORD *a1, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  int v5; // r3

  if ( a2 )
  {
    v2 = a1[14];
    v3 = 2;
    if ( !v2 )
      return 0;
    v4 = v2 - 1;
    a1[14] = v4;
  }
  else
  {
    v3 = 4;
    v4 = a1[15] - 1;
    a1[15] = v4;
  }
  if ( !v4 )
  {
    v5 = a1[2];
    if ( (v5 & v3) == 0 )
    {
      a1[2] = v5 | v3;
      return WmipDoDisableRequest(a1, a2, v3);
    }
  }
  return 0;
}
