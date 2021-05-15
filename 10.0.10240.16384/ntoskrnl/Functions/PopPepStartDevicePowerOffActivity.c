// PopPepStartDevicePowerOffActivity 
 
int __fastcall PopPepStartDevicePowerOffActivity(int a1, int a2, int a3)
{
  int v3; // r3
  int result; // r0

  *(_BYTE *)(a1 + 88) = 0;
  *(_DWORD *)a3 = 2;
  v3 = *(_DWORD *)(a1 + 24);
  *(_BYTE *)(a3 + 8) = 0;
  result = 1;
  *(_DWORD *)(a3 + 4) = v3;
  return result;
}
