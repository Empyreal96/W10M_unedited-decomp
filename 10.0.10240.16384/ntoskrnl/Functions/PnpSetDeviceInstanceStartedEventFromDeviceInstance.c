// PnpSetDeviceInstanceStartedEventFromDeviceInstance 
 
int __fastcall PnpSetDeviceInstanceStartedEventFromDeviceInstance(unsigned __int16 *a1)
{
  int v2; // r3
  int v3; // r8
  _DWORD *v4; // r0
  _DWORD *v5; // r6
  int v6; // r1

  if ( dword_630874 )
    return -1073741431;
  v2 = *a1;
  v3 = v2 + 70;
  v4 = (_DWORD *)PnpCreateDeviceEventEntry(v2 + 134);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  v4[2] = 0;
  v4[3] = 0;
  v4[6] = 0;
  v4[7] = 0;
  v4[16] = -885374967;
  v4[17] = 298862320;
  v4[18] = 1610649520;
  v4[19] = 1057297303;
  v4[20] = 11;
  v4[21] = 0;
  v4[22] = 0;
  v4[23] = v3;
  v4[24] = 0;
  v6 = *((_DWORD *)a1 + 1);
  if ( v6 )
    memmove((int)(v4 + 25), v6, *a1);
  *((_WORD *)v5 + (*a1 >> 1) + 50) = 0;
  return PnpInsertEventInQueue(v5);
}
