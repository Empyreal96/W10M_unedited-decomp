// _CmGetMatchingFilteredDeviceList 
 
int __fastcall CmGetMatchingFilteredDeviceList(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int (__fastcall *v12)(int, _DWORD, int, int, int, int *); // r5
  int v13; // r0
  int v15; // [sp+20h] [bp-50h] BYREF
  _DWORD v16[10]; // [sp+24h] [bp-4Ch] BYREF

  v15 = 0;
  memset(v16, 0, sizeof(v16));
  v12 = *(int (__fastcall **)(int, _DWORD, int, int, int, int *))(a1 + 160);
  v16[6] = a7;
  v16[7] = a8;
  v16[1] = a2;
  v16[2] = a3;
  v16[3] = a4;
  v16[4] = a5;
  v16[5] = a6;
  v16[8] = 0;
  if ( !v12 )
    JUMPOUT(0x7E9288);
  v13 = v12(a1, 0, 1, 16, 1, &v15);
  if ( v13 == -1073741822 )
    return sub_7E926C();
  if ( v13 != -1073741536 )
    JUMPOUT(0x7E9270);
  return v15;
}
