// PnpSetBlockedDriverEvent 
 
int __fastcall PnpSetBlockedDriverEvent(_DWORD *a1)
{
  _DWORD *v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3

  if ( dword_630874 )
    return -1073741431;
  v3 = PnpCreateDeviceEventEntry(132);
  if ( !v3 )
    return -1073741670;
  v3[16] = 466123297;
  v3[17] = 1202103295;
  v3[18] = 23964310;
  v3[19] = 1518339593;
  v3[20] = 7;
  v3[23] = 68;
  v4 = a1[1];
  v5 = a1[2];
  v6 = a1[3];
  v3[25] = *a1;
  v3[26] = v4;
  v3[27] = v5;
  v3[28] = v6;
  return PnpInsertEventInQueue(v3);
}
