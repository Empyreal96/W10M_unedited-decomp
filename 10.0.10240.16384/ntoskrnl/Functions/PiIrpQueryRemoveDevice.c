// PiIrpQueryRemoveDevice 
 
int __fastcall PiIrpQueryRemoveDevice(_DWORD *a1, _DWORD *a2)
{
  int v5; // r5
  int v6; // [sp+10h] [bp-58h] BYREF
  char v7[16]; // [sp+14h] [bp-54h] BYREF
  int v8; // [sp+24h] [bp-44h]
  char v9[64]; // [sp+28h] [bp-40h] BYREF

  memset(v9, 0, 40);
  v9[0] = 27;
  v9[1] = 1;
  if ( PnpFindMountableDevice(a1) )
    return sub_7DEB08();
  v8 = -1073741823;
  v6 = 0;
  KeInitializeEvent((int)v7, 1, 0);
  v5 = PnpAsynchronousCall((int)a1, (int)v9, (int)PnpDiagnosticCompletionRoutine, (int)&v6);
  if ( v5 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v7, 0, 0, 0, 0);
    v5 = v8;
  }
  if ( a2 )
    *a2 = v6;
  return v5;
}
