// PnpSetPowerVetoEvent 
 
int __fastcall PnpSetPowerVetoEvent(int a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6)
{
  int v9; // r4
  int v10; // r2
  int v11; // r3
  int v12; // r9
  _DWORD *v13; // r6
  int v14; // r2
  int v15; // r4
  unsigned int *v16; // r4
  GUID *v17; // r5
  int v18; // r1
  int v19; // r2
  int v20; // r3

  if ( dword_630874 )
    return -1073741431;
  v9 = *(_DWORD *)(*(_DWORD *)(a4 + 176) + 20);
  if ( !v9 )
    return -1073741584;
  if ( a6 )
    v10 = *a6;
  else
    v10 = 0;
  v11 = *(unsigned __int16 *)(v9 + 20) + v10;
  v12 = v11 + 72;
  v13 = PnpCreateDeviceEventEntry(v11 + 136);
  if ( !v13 )
    return -1073741670;
  ObfReferenceObject(a4);
  v13[3] = 0;
  v13[24] = a4;
  v13[25] = a5;
  v13[23] = v12;
  v13[21] = 0;
  memmove((int)(v13 + 26), *(_DWORD *)(v9 + 24), *(unsigned __int16 *)(v9 + 20));
  v14 = *(unsigned __int16 *)(v9 + 20) >> 1;
  *((_WORD *)v13 + v14 + 52) = 0;
  if ( a6 )
  {
    v15 = (int)v13 + 2 * v14 + 106;
    memmove(v15, *((_DWORD *)a6 + 1), *a6);
    *(_WORD *)(v15 + 2 * (*a6 >> 1)) = 0;
  }
  v16 = v13 + 16;
  if ( a1 == 7 )
  {
    v17 = &GUID_DEVICE_WARM_EJECT_VETOED;
  }
  else
  {
    if ( a1 != 3 )
    {
      *v16 = 62004243;
      v13[17] = 299047126;
      v13[18] = -1610556521;
      v13[19] = 777142473;
      goto LABEL_18;
    }
    v17 = &GUID_DEVICE_HIBERNATE_VETOED;
  }
  v18 = *(_DWORD *)&v17->Data2;
  v19 = *(_DWORD *)v17->Data4;
  v20 = *(_DWORD *)&v17->Data4[4];
  *v16 = v17->Data1;
  v13[17] = v18;
  v13[18] = v19;
  v13[19] = v20;
LABEL_18:
  v13[20] = 6;
  return PnpInsertEventInQueue(v13);
}
