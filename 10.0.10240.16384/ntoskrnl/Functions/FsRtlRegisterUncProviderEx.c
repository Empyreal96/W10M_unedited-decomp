// FsRtlRegisterUncProviderEx 
 
int __fastcall FsRtlRegisterUncProviderEx(_DWORD *a1, int a2, int a3, int a4)
{
  __int16 v5[2]; // [sp+0h] [bp-18h] BYREF
  int v6; // [sp+4h] [bp-14h]
  int v7; // [sp+8h] [bp-10h]

  v7 = a4;
  v5[1] = 257;
  v5[0] = 8;
  v6 = a4;
  return FsRtlpRegisterUncProvider(a2, a3, (int)v5, a1);
}
