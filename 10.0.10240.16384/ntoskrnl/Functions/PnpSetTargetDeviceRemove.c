// PnpSetTargetDeviceRemove 
 
int __fastcall PnpSetTargetDeviceRemove(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, _DWORD *a10, int a11, int a12, _DWORD *a13)
{
  int v13; // r6
  int v18; // r3
  int v19; // r5
  int v20; // r0
  _BYTE *v21; // r0
  _DWORD *v22; // r4

  v13 = a3;
  if ( a10 )
    *a10 = 259;
  if ( dword_630874 )
    return sub_7DF28C();
  if ( a1 )
    v18 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v18 = 0;
  v19 = *(unsigned __int16 *)(v18 + 20);
  if ( a2 )
    v20 = 3;
  else
    v20 = 0;
  v21 = (_BYTE *)PnpAllocateCriticalMemory(v20, 1, v19 + 134, 1265659472);
  v22 = v21;
  if ( !v21 )
    return -1073741670;
  memset(v21, 0, v19 + 134);
  PnpInitializeTargetDeviceRemoveEvent(v22, v19 + 134, a1, a2, v13, a4, a5, a6, a7, a10, a11, a12, a3);
  v22[4] = a8;
  v22[5] = a9;
  if ( a13 )
  {
    *a13 = v22;
    ++v22[8];
  }
  return PnpInsertEventInQueue(v22);
}
