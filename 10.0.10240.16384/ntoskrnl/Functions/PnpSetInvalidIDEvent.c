// PnpSetInvalidIDEvent 
 
int __fastcall PnpSetInvalidIDEvent(unsigned __int16 *a1)
{
  int v3; // r3
  int v4; // r8
  _DWORD *v5; // r0
  _DWORD *v6; // r6

  if ( dword_630874 )
    return -1073741431;
  v3 = *a1;
  v4 = v3 + 70;
  v5 = PnpCreateDeviceEventEntry(v3 + 134);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  v5[16] = 1470405427;
  v5[17] = 1316326277;
  v5[18] = 1813414304;
  v5[19] = 133448162;
  v5[20] = 8;
  v5[23] = v4;
  memmove((int)(v5 + 25), *((_DWORD *)a1 + 1), *a1);
  *((_WORD *)v6 + (*a1 >> 1) + 50) = 0;
  *((_WORD *)v6 + (*a1 >> 1) + 51) = 0;
  return PnpInsertEventInQueue(v6);
}
