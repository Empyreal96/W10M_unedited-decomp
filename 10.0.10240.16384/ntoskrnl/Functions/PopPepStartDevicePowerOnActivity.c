// PopPepStartDevicePowerOnActivity 
 
int __fastcall PopPepStartDevicePowerOnActivity(int a1, int a2, int a3)
{
  *(_DWORD *)a3 = 2;
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(a1 + 24);
  *(_BYTE *)(a3 + 8) = 1;
  return 1;
}
