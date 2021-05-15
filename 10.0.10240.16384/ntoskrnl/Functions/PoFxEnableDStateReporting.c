// PoFxEnableDStateReporting 
 
int __fastcall PoFxEnableDStateReporting(int a1)
{
  int v2; // r4
  int v3; // r2
  int v4; // r3
  int v6; // [sp+18h] [bp-78h]
  char v7[32]; // [sp+20h] [bp-70h] BYREF
  int v8[12]; // [sp+40h] [bp-50h] BYREF
  char v9[32]; // [sp+70h] [bp-20h] BYREF

  if ( !a1 )
    return -1073741811;
  memset(v7, 0, 28);
  memset(v8, 0, sizeof(v8));
  v8[7] = 1;
  memset(v9, 0, 24);
  v8[8] = (int)v9;
  v2 = ((int (__fastcall *)(int, char *, int *, int, _DWORD))PopFxRegisterDevice)(a1, v7, v8, 1, 0);
  if ( v2 >= 0 )
  {
    v3 = v6;
    v4 = *(_DWORD *)(v6 + 384) | 1;
    __dmb(0xBu);
    *(_DWORD *)(v3 + 384) = v4;
    PoFxStartDevicePowerManagement(v6);
  }
  return v2;
}
