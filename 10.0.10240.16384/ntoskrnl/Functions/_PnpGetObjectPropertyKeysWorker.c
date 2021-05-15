// _PnpGetObjectPropertyKeysWorker 
 
int __fastcall PnpGetObjectPropertyKeysWorker(int *a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, unsigned int a8, _DWORD *a9, __int16 a10)
{
  int v10; // r5
  int v14; // r4
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r3
  int v18; // r0
  unsigned int v20; // [sp+18h] [bp-28h] BYREF
  int v21; // [sp+1Ch] [bp-24h] BYREF
  unsigned int v22[8]; // [sp+20h] [bp-20h] BYREF

  v10 = a4;
  v20 = 0;
  v21 = 0;
  v22[0] = 0;
  if ( a10 )
    return -1073741811;
  *a9 = 0;
  if ( a4 || (v14 = PnpOpenObjectRegKey((int)a1, a2, a3, 33554433, 0, (int)&v21, 0, 0), v14 >= 0) )
  {
    v15 = PnpGetMappedPropertyKeysDispatch((int)a1, a2, a3, v10, a5, a6, a7, a8, (int)&v20);
    v14 = v15;
    if ( !v15 || v15 == -1073741789 || v15 == -1073741790 )
    {
      if ( v20 >= a8 )
      {
        v17 = 0;
        v16 = 0;
      }
      else
      {
        v16 = a8 - v20;
        v17 = a7 + 20 * v20;
      }
      if ( !v10 )
        v10 = v21;
      v18 = PnpGetGenericStorePropertyKeys(a1, v10, a5, a6, v17, v16, v22);
      v14 = v18;
      if ( !v18 || v18 == -1073741789 || v18 == -1073741790 )
      {
        v14 = -1073741789;
        if ( v22[0] + v20 <= a8 )
          v14 = 0;
        *a9 = v22[0] + v20;
      }
    }
  }
  if ( v21 )
    ZwClose();
  return v14;
}
