// EtwpSendSessionNotification 
 
int __fastcall EtwpSendSessionNotification(_DWORD *a1, int a2, int a3)
{
  int v4; // r8
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v11[32]; // [sp+8h] [bp-80h] BYREF

  v4 = (unsigned __int16)*a1;
  if ( !(unsigned __int16)*a1 )
    v4 = 0xFFFF;
  memset(v11, 0, 96);
  v11[1] = 96;
  v11[0] = 7;
  v11[10] = 711858267;
  v11[11] = 1338347742;
  v11[12] = 1151298690;
  v11[13] = 665061606;
  v6 = a1[51];
  v7 = a1[52];
  v8 = a1[53];
  v11[14] = a1[50];
  v11[15] = v6;
  v11[16] = v7;
  v11[17] = v8;
  v11[20] = v4;
  v11[21] = 0;
  v11[18] = a2;
  v11[19] = a3;
  return EtwpNotifyGuid(v11, 0);
}
