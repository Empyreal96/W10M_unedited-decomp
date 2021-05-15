// _PnpInstallerClassRaisePropertyChangeEventWorker 
 
int __fastcall PnpInstallerClassRaisePropertyChangeEventWorker(int a1, int a2, int a3, int a4, unsigned int a5, int (__fastcall *a6)(int, int, int, int, int))
{
  _DWORD v9[8]; // [sp+10h] [bp-20h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v9[2] = a5;
  a6(a1, a2, 2, 4, (int)v9);
  return PnpNotifyDerivedKeys(a1, a2, 2, a5, (int)&off_41E1DC, 1, (int)v9, a6);
}
