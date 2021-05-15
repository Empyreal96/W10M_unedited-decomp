// PiQueueDeviceRequest 
 
int __fastcall PiQueueDeviceRequest(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r4
  int v8; // r0
  int *v9; // r5
  char *v10; // r3
  int v11; // r4
  char v13[40]; // [sp+8h] [bp-28h] BYREF

  v5 = (int)a5;
  if ( a5 )
    *a5 = 0;
  v8 = PnpDeviceObjectFromDeviceInstance(a1);
  v9 = (int *)v8;
  if ( !v8 )
    return -1073741810;
  if ( *(_DWORD *)(*(_DWORD *)(v8 + 176) + 20) )
  {
    if ( a4 )
      KeInitializeEvent((int)v13, 0, 0);
    else
      v5 = 0;
    if ( a4 )
      v10 = v13;
    else
      v10 = 0;
    v11 = PnpRequestDeviceAction(v9, a2, 0, 0, (int)v10, v5);
    if ( v11 >= 0 && a4 )
      v11 = KeWaitForSingleObject((unsigned int)v13, 0, 0, 0, 0);
  }
  else
  {
    v11 = -1073741810;
  }
  ObfDereferenceObject((int)v9);
  return v11;
}
