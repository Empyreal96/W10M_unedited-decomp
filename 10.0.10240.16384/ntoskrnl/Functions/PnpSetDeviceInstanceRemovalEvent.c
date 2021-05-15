// PnpSetDeviceInstanceRemovalEvent 
 
int __fastcall PnpSetDeviceInstanceRemovalEvent(int a1)
{
  int v3; // r3
  int v4; // r8
  _DWORD *v5; // r0
  _DWORD *v6; // r6
  int v7; // r1

  if ( dword_630874 )
    return -1073741431;
  v3 = *(unsigned __int16 *)(a1 + 20);
  v4 = v3 + 70;
  v5 = (_DWORD *)PnpCreateDeviceEventEntry(v3 + 134);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  v5[2] = 0;
  v5[3] = 0;
  v5[6] = 0;
  v5[7] = 0;
  v5[16] = 1917771117;
  v5[17] = 1182975281;
  v5[18] = -173508198;
  v5[19] = -1024061299;
  v5[20] = 10;
  v5[21] = 0;
  v5[22] = 0;
  v5[23] = v4;
  v5[24] = 0;
  v7 = *(_DWORD *)(a1 + 24);
  if ( v7 )
    memmove((int)(v5 + 25), v7, *(unsigned __int16 *)(a1 + 20));
  *((_WORD *)v6 + (*(unsigned __int16 *)(a1 + 20) >> 1) + 50) = 0;
  return PnpInsertEventInQueue(v6);
}
