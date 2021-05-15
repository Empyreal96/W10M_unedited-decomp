// -StDmDeviceIoTransfer@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@PAU_ST_DEVICE_IO@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmDeviceIoTransfer(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  _DWORD *v5; // r7
  int v8; // r5
  unsigned int v9; // r4
  int v10; // r3
  int result; // r0

  v3 = (_DWORD *)a3[1];
  v5 = v3 + 3;
  v8 = (((unsigned int)&v3[4 * *v3 + 2] + a1[22] + 3) & ~(a1[22] - 1))
     + 16 * (v3[3] & a1[24])
     - (~(a1[22] - 1) & (16 * (v3[3] & a1[24])));
  if ( v3 + 3 >= &v3[4 * *v3 + 3] )
    return 0;
  v9 = (unsigned int)&v3[4 * *v3 + 3];
  while ( 1 )
  {
    v10 = a2 ? *(_DWORD *)(a2 + 8) : *a3;
    result = ST_STORE<SM_TRAITS>::StDmSinglePageTransfer(
               a1,
               a1[60],
               v8 + 16 * (*v5 - a3[2]),
               (a3[3] >> 4) & 1 | a2,
               v10,
               v5,
               0);
    if ( result < 0 )
      break;
    v5 += 4;
    if ( (unsigned int)v5 >= v9 )
      return 0;
  }
  return result;
}
