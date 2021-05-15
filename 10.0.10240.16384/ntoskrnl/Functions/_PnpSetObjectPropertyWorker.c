// _PnpSetObjectPropertyWorker 
 
int __fastcall PnpSetObjectPropertyWorker(int *a1, int a2, int a3, int a4, char *a5, int a6, int a7, int a8, unsigned int a9, int a10)
{
  int v13; // r7
  int v14; // r4
  int v15; // r0
  int v16; // r1
  char *v17; // r7
  int v18; // r0
  int v20; // [sp+4h] [bp-3Ch]
  int v22[9]; // [sp+1Ch] [bp-24h] BYREF

  v22[0] = 0;
  if ( (_WORD)a10 )
    return -1073741811;
  v13 = a8;
  if ( a8 )
  {
    if ( a9 )
      goto LABEL_4;
    goto LABEL_19;
  }
  if ( a9 )
    return -1073741811;
LABEL_19:
  v13 = 0;
LABEL_4:
  v14 = PnpValidatePropertyData(v13, a9, a7, a10);
  if ( v14 < 0 )
    goto LABEL_15;
  v15 = PnpSetMappedPropertyDispatch(a1, a2, a3, a4, a5, a6, a7, v13, a9, a10);
  v14 = v15;
  if ( v15 < 0 || a3 < 6 )
  {
    if ( v15 == -1073741802 )
    {
      if ( a4 )
      {
        v16 = a4;
        goto LABEL_9;
      }
      v14 = PnpOpenObjectRegKey((int)a1, a2, a3, 33554439, 0, (int)v22, 0, 0);
      if ( v14 >= 0 )
      {
        v16 = v22[0];
LABEL_9:
        if ( a7 )
        {
          v20 = v13;
          v17 = a5;
          v18 = PnpSetPropertyWorker(a1, v16, a5, a6, a7, v20, a9);
        }
        else
        {
          v17 = a5;
          v18 = PnpDeletePropertyWorker(a1, v16, a5, a6, 0);
        }
        v14 = v18;
        if ( v18 >= 0 )
        {
          if ( !a4 )
            a4 = v22[0];
          PnpObjectRaisePropertyChangeEvent(a1, a2, a3, a4, v17, a6);
        }
        goto LABEL_15;
      }
    }
LABEL_15:
    if ( v22[0] )
      ZwClose();
    return v14;
  }
  return sub_7C8CC0();
}
