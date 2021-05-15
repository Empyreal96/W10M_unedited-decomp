// IoValidateDeviceIoControlAccess 
 
int __fastcall IoValidateDeviceIoControlAccess(int a1, int a2)
{
  _BYTE *v2; // r2
  char v4; // r3
  BOOL v5; // r2
  int v6; // r3

  if ( (a2 & 3) == 0 )
    return -1073741811;
  v2 = *(_BYTE **)(a1 + 96);
  if ( *v2 != 14 )
    return sub_555B14();
  if ( *(_BYTE *)(a1 + 32) )
  {
    v4 = v2[2];
    v5 = (v4 & 1) != 0;
    v6 = (v4 & 4) != 0 ? 2 : 0;
    if ( ((v6 | v5) & a2) != a2 )
      return -1073741790;
  }
  return 0;
}
