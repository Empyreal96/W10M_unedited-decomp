// _CmGetMatchingDeviceInterfaceList 
 
int __fastcall CmGetMatchingDeviceInterfaceList(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r8
  int (__fastcall *v12)(int, _DWORD, int, int, int, int *); // r5
  int v13; // r1
  int v14; // r2
  int v16; // r4
  int v17; // [sp+18h] [bp-50h] BYREF
  _DWORD v18[10]; // [sp+1Ch] [bp-4Ch] BYREF

  v8 = a6;
  v17 = 0;
  memset(v18, 0, sizeof(v18));
  v12 = *(int (__fastcall **)(int, _DWORD, int, int, int, int *))(a1 + 160);
  v13 = a5;
  v14 = a7;
  v18[3] = a4;
  v18[4] = a5;
  v18[5] = a6;
  v18[6] = a7;
  v18[1] = a2;
  v18[2] = a3;
  if ( v12 )
  {
    if ( v12(a1, 0, 3, 4, 1, &v17) != -1073741822 )
      return sub_81B7F8();
    a2 = v18[1];
    a3 = v18[2];
    a4 = v18[3];
    v13 = v18[4];
    v8 = v18[5];
    v14 = v18[6];
  }
  if ( (_WORD)v14 )
    v16 = -1073741811;
  else
    v16 = CmGetMatchingFilteredDeviceInterfaceList(a1, 0, 0, 0, a2, a3, a4, v13, v8, v14);
  return v16;
}
