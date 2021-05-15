// _PnpGetObjectPropertyWorker 
 
int __fastcall PnpGetObjectPropertyWorker(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8, int a9, _DWORD *a10, int a11)
{
  int v11; // r7
  int v15; // r4
  int v16; // r5
  int v17; // r6
  int v19[8]; // [sp+20h] [bp-20h] BYREF

  v11 = a4;
  v19[0] = 0;
  if ( (_WORD)a11 )
    return -1073741811;
  v15 = a8;
  if ( a8 )
  {
    v16 = a9;
    if ( !a9 )
      v15 = 0;
  }
  else
  {
    v16 = 0;
  }
  *a7 = 0;
  *a10 = 0;
  v17 = PnpGetMappedPropertyDispatch(a1, a2, a3, a4, a5, a6, a7, v15, v16, a10, a11);
  if ( v17 == -1073741802 )
  {
    if ( v11 )
      goto LABEL_7;
    v17 = PnpOpenObjectRegKey(a1, a2, a3, 33554433, 0, (int)v19, 0, 0);
    if ( v17 >= 0 )
    {
      v11 = v19[0];
LABEL_7:
      v17 = PnpGetGenericStoreProperty(a1, v11, a5, a6, a7, v15, v16, a10);
      if ( v17 >= 0 )
        v17 = PnpValidatePropertyData(v15, *a10, *a7);
      goto LABEL_9;
    }
  }
LABEL_9:
  if ( v19[0] )
    ZwClose();
  return v17;
}
