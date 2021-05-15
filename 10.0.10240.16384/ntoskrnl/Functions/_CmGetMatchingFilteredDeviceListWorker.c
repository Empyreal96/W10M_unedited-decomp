// _CmGetMatchingFilteredDeviceListWorker 
 
int __fastcall CmGetMatchingFilteredDeviceListWorker(int *a1, unsigned __int16 *a2, int a3, int (__fastcall *a4)(int a1, int a2, int a3, int a4), int a5, _WORD *a6, unsigned int a7, unsigned int *a8, __int16 a9)
{
  int v9; // r6
  int v10; // r4
  _DWORD *v13; // [sp+0h] [bp-48h]
  _DWORD v14[4]; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 *v15; // [sp+20h] [bp-28h] BYREF
  unsigned int v16; // [sp+24h] [bp-24h]
  int v17; // [sp+28h] [bp-20h]
  int (__fastcall *v18)(int, int, int, int); // [sp+2Ch] [bp-1Ch]
  int v19; // [sp+30h] [bp-18h]

  v9 = 0;
  *a8 = 0;
  if ( a7 )
    *a6 = 0;
  if ( (a3 & 0xFFFFFE00) != 0 || a9 )
    return -1073741811;
  if ( (a3 & 0x100) != 0 )
    v9 = 1;
  if ( (a3 & 0x7C) != 0 )
  {
    if ( !a2 )
      return -1073741811;
    return CmGetDeviceRelationsList((int)a1, a2, a3, (int)a6, a7, (int)a8);
  }
  if ( (a3 & 2) == 0 )
  {
    if ( (a3 & 0x80) != 0 )
    {
      if ( !a2 )
        return -1073741811;
      v14[0] = a2;
      v14[1] = a4;
      v14[2] = a5;
      v13 = v14;
      a4 = CmClassFilterCallback;
      return CmGetMatchingDeviceListForSubkey(a1, 0, v9, (int)a4, (int)v13, a6, a7, a8);
    }
    if ( (a3 & 1) == 0 )
    {
      v13 = (_DWORD *)a5;
      return CmGetMatchingDeviceListForSubkey(a1, 0, v9, (int)a4, (int)v13, a6, a7, a8);
    }
    if ( !a2 )
      return -1073741811;
    return CmGetMatchingDeviceListForSubkey(a1, (int)a2, v9, (int)a4, a5, a6, a7, a8);
  }
  if ( !a2 )
    return -1073741811;
  v16 = 0;
  v17 = 0;
  v15 = a2;
  v18 = a4;
  v19 = a5;
  v10 = CmGetMatchingDeviceListForSubkey(a1, 0, v9, (int)CmServiceFilterCallback, (int)&v15, a6, a7, a8);
  if ( v16 )
    ExFreePoolWithTag(v16);
  return v10;
}
