// _PnpGetObjectPropertyLocalesWorker 
 
int __fastcall PnpGetObjectPropertyLocalesWorker(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9)
{
  int v9; // r7
  int v13; // r4
  int v14; // r5
  int v15; // r6
  int v17[8]; // [sp+18h] [bp-20h] BYREF

  v9 = a4;
  v17[0] = 0;
  if ( (_WORD)a9 )
    return -1073741811;
  v14 = a6;
  if ( a6 )
  {
    v15 = a7;
    if ( !a7 )
      v14 = 0;
  }
  else
  {
    v15 = 0;
  }
  *a8 = 0;
  v13 = PnpGetMappedPropertyLocalesDispatch(a1, a2, a3, a4, a5, v14, v15, (int)a8, a9);
  if ( v13 == -1073741802 )
  {
    if ( !v9 )
    {
      v13 = PnpOpenObjectRegKey(a1, a2, a3, 33554433, 0, (int)v17, 0, 0);
      if ( v13 < 0 )
        goto LABEL_12;
      v9 = v17[0];
    }
    v13 = PnpGetGenericStorePropertyLocales(a1, v9, a5, v14, v15, a8);
  }
LABEL_12:
  if ( v17[0] )
    ZwClose();
  return v13;
}
