// PnpSetDeviceClassChange 
 
int __fastcall PnpSetDeviceClassChange(_DWORD *a1, _DWORD *a2, unsigned __int16 *a3)
{
  int v7; // r3
  int v8; // r6
  _DWORD *v9; // r0
  _DWORD *v10; // r5
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3

  if ( dword_630874 )
    return -1073741431;
  v7 = *a3;
  v8 = v7 + 68;
  v9 = PnpCreateDeviceEventEntry(v7 + 132);
  v10 = v9;
  if ( !v9 )
    return -1073741801;
  v11 = a1[1];
  v12 = a1[2];
  v13 = a1[3];
  v9[16] = *a1;
  v9[17] = v11;
  v9[18] = v12;
  v9[19] = v13;
  v9[20] = 2;
  v9[23] = v8;
  v14 = a2[1];
  v15 = a2[2];
  v16 = a2[3];
  v9[25] = *a2;
  v9[26] = v14;
  v9[27] = v15;
  v9[28] = v16;
  memmove((int)(v9 + 29), *((_DWORD *)a3 + 1), *a3);
  *((_WORD *)v10 + (*a3 >> 1) + 58) = 0;
  return PnpInsertEventInQueue(v10);
}
