// PnpSetDeviceRemovalSafe 
 
int __fastcall PnpSetDeviceRemovalSafe(int a1)
{
  int v3; // r6
  int v4; // r3
  int v5; // r9
  _DWORD *v6; // r7
  int v7; // r1

  if ( dword_630874 )
    return -1073741431;
  if ( a1 )
    v3 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v3 = 0;
  v4 = *(unsigned __int16 *)(v3 + 20);
  v5 = v4 + 70;
  v6 = PnpCreateDeviceEventEntry(v4 + 134);
  if ( !v6 )
    return -1073741670;
  ObfReferenceObject(a1);
  v6[2] = 0;
  v6[3] = 0;
  v6[6] = 0;
  v6[7] = 0;
  v6[16] = -1883309721;
  v6[17] = 299030213;
  v6[18] = -1610566249;
  v6[19] = 777142473;
  v6[20] = 1;
  v6[21] = 0;
  v6[22] = 0;
  v6[23] = v5;
  v6[24] = a1;
  v7 = *(_DWORD *)(v3 + 24);
  if ( v7 )
    memmove((int)(v6 + 25), v7, *(unsigned __int16 *)(v3 + 20));
  *((_WORD *)v6 + (*(unsigned __int16 *)(v3 + 20) >> 1) + 50) = 0;
  return PnpInsertEventInQueue(v6);
}
