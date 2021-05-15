// MiLoadImportDll 
 
int __fastcall MiLoadImportDll(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  char v6; // r6
  int v7; // r5
  int v8; // r4
  int v9; // r0
  int v11; // [sp+8h] [bp-18h] BYREF
  int v12[5]; // [sp+Ch] [bp-14h] BYREF

  v11 = a3;
  v12[0] = (int)a4;
  v6 = a3;
  v7 = MmLoadSystemImage(a1, a2, 0, a3, &v11, v12);
  if ( v7 >= 0 )
  {
    v8 = v11;
    v9 = v11;
    *(_DWORD *)(v11 + 52) |= 0x4000000u;
    v7 = MmCallDllInitialize(v9, &PsLoadedModuleList);
    if ( v7 < 0 )
      return sub_80C1CC();
    if ( (v6 & 1) == 0 )
      MiFreeDriverInitialization(v8);
    *a4 = v11;
    *a5 = v12[0];
  }
  return v7;
}
