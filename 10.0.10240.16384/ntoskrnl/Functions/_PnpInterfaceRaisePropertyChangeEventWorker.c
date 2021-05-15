// _PnpInterfaceRaisePropertyChangeEventWorker 
 
int __fastcall PnpInterfaceRaisePropertyChangeEventWorker(int a1, int a2, int a3, int a4, int a5, void (__fastcall *a6)(int, int, int, int, _DWORD *))
{
  _DWORD v9[8]; // [sp+10h] [bp-20h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v9[2] = a5;
  a6(a1, a2, 3, 4, v9);
  return PnpNotifyDerivedKeys(a1, a2, 3, a5, &off_401E98, 2, v9, a6);
}
