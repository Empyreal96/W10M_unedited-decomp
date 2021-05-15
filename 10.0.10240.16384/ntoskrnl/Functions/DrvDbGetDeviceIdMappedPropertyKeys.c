// DrvDbGetDeviceIdMappedPropertyKeys 
 
int __fastcall DrvDbGetDeviceIdMappedPropertyKeys(int **a1, int a2, int a3, _DWORD *a4, unsigned int a5, unsigned int *a6)
{
  int v7; // r4
  int v8; // r4
  int v9; // r0
  int v11; // [sp+10h] [bp-18h] BYREF
  int v12[5]; // [sp+14h] [bp-14h] BYREF

  v7 = a3;
  *a6 = 0;
  v11 = 0;
  v12[0] = 0;
  if ( !a3 )
  {
    a1 = (int **)DrvDbOpenObjectRegKey(a1, 0, 5, a2, 1, 0, (int)&v11, 0);
    v8 = (int)a1;
    if ( (int)a1 < 0 )
      goto LABEL_7;
    v7 = v11;
  }
  v9 = PnpCtxRegQueryInfoKey((int)a1, v7, 0, (int)v12, (int)v12);
  v8 = v9;
  if ( v9 >= 0 && v12[0] )
    v8 = DrvDbGetCompositeMappedPropertyKeys(v9, (_DWORD **)&off_618D1C, 2u, a4, a5, a6);
LABEL_7:
  if ( v11 )
    ZwClose();
  return v8;
}
