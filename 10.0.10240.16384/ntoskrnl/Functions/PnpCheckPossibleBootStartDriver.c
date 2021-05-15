// PnpCheckPossibleBootStartDriver 
 
int __fastcall PnpCheckPossibleBootStartDriver(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r4
  _DWORD *v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  v4 = 0;
  if ( IopGetRegistryValue(a1, L"BootFlags", 0, (int *)&v6) >= 0 )
  {
    if ( v6[1] == 4 && v6[3] == 4 && *(_DWORD *)((char *)v6 + v6[2]) )
      v4 = 1;
    ExFreePoolWithTag((unsigned int)v6);
  }
  return v4;
}
