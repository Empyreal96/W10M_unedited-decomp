// PnpSetCustomTargetEvent 
 
int __fastcall PnpSetCustomTargetEvent(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r8
  _DWORD *v9; // r7
  int v10; // r1
  int v11; // r0
  unsigned int v14; // [sp+4h] [bp-24h]

  if ( a2 )
    return sub_7C16C4();
  if ( dword_630874 )
    return -1073741431;
  if ( a1 )
    v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v8 = 0;
  v14 = *(unsigned __int16 *)(a6 + 2) + ((*(unsigned __int16 *)(v8 + 20) + 73) & 0xFFFFFFFC);
  v9 = (_DWORD *)PnpCreateDeviceEventEntry(v14 + 64);
  if ( !v9 )
    return -1073741670;
  ObfReferenceObject(a1);
  v9[4] = a4;
  v9[5] = a5;
  v9[3] = 0;
  v9[16] = -1398325362;
  v9[17] = 298945827;
  v9[18] = 32172;
  v9[19] = -797870600;
  v9[20] = 3;
  v9[23] = v14;
  v9[24] = a1;
  v9[21] = a3;
  v9[22] = 0;
  v10 = *(_DWORD *)(v8 + 24);
  if ( v10 )
    memmove((int)(v9 + 26), v10, *(unsigned __int16 *)(v8 + 20));
  v11 = (int)v9 + v14 - *(unsigned __int16 *)(a6 + 2) + 64;
  v9[25] = v11;
  memmove(v11, a6, *(unsigned __int16 *)(a6 + 2));
  return PnpInsertEventInQueue(v9);
}
