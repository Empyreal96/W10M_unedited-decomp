// PnpSetHwProfileChangeEvent 
 
int __fastcall PnpSetHwProfileChangeEvent(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3

  if ( dword_630874 )
    return -1073741431;
  v10 = PnpCreateDeviceEventEntry(132);
  if ( !v10 )
    return -1073741670;
  v10[3] = a2;
  v10[6] = a4;
  v10[7] = a5;
  v10[20] = 0;
  v11 = a1[1];
  v12 = a1[2];
  v13 = a1[3];
  v10[16] = *a1;
  v10[17] = v11;
  v10[18] = v12;
  v10[19] = v13;
  v10[23] = 68;
  v10[21] = a3;
  return PnpInsertEventInQueue(v10);
}
