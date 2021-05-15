// IopLiveDumpCallRemovePagesCallbacks 
 
int __fastcall IopLiveDumpCallRemovePagesCallbacks(int *a1)
{
  int v1; // r5
  char *v2; // r9
  int result; // r0
  int v4; // r4
  int *v5; // r8
  int v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r0
  int v10; // r1
  int *v11; // r5
  int v12; // r0
  int v13; // r10
  int v14; // r3
  int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18; // r1
  int v19; // [sp+0h] [bp-A8h]
  int *v20; // [sp+4h] [bp-A4h]
  int v21; // [sp+8h] [bp-A0h]
  int *v22; // [sp+Ch] [bp-9Ch] BYREF
  int v23; // [sp+10h] [bp-98h]
  int v24; // [sp+14h] [bp-94h]
  int v25; // [sp+18h] [bp-90h]
  int v26; // [sp+1Ch] [bp-8Ch]
  int *v27; // [sp+20h] [bp-88h]
  int v28; // [sp+28h] [bp-80h] BYREF
  int v29; // [sp+2Ch] [bp-7Ch]
  int v30; // [sp+30h] [bp-78h]
  unsigned int v31; // [sp+34h] [bp-74h]
  int v32; // [sp+38h] [bp-70h]
  int *v33; // [sp+3Ch] [bp-6Ch]
  int *v34; // [sp+40h] [bp-68h]
  unsigned int v35; // [sp+44h] [bp-64h]
  _DWORD v36[4]; // [sp+48h] [bp-60h] BYREF
  _DWORD v37[2]; // [sp+58h] [bp-50h] BYREF
  _DWORD v38[2]; // [sp+60h] [bp-48h] BYREF
  _DWORD *v39; // [sp+68h] [bp-40h]
  int v40; // [sp+6Ch] [bp-3Ch]
  int v41; // [sp+70h] [bp-38h]
  char *v42; // [sp+78h] [bp-30h] BYREF
  int v43; // [sp+7Ch] [bp-2Ch]
  int v44; // [sp+80h] [bp-28h]
  int v45; // [sp+84h] [bp-24h]

  v27 = a1;
  v36[1] = a1;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v38[0] = 0;
  v38[1] = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v35 = 257;
  v36[3] = 257;
  v1 = 1;
  v25 = 1;
  v2 = (char *)&dword_6A12F0;
  v22 = &dword_6A12F0;
  result = IopLiveDumpIsTracingEnabled();
  v4 = result;
  v26 = result;
  LOBYTE(v23) = result;
  if ( result )
  {
    v20 = 0;
    v19 = 0;
    result = EtwWrite(
               IopLiveDumpEtwRegHandle,
               SHIDWORD(IopLiveDumpEtwRegHandle),
               (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_REMOVEPAGES_CALLBACKS_START,
               0);
    v4 = v26;
  }
  v5 = (int *)KeBugCheckAddRemovePagesCallbackListHead;
  v36[0] = &KeBugCheckAddRemovePagesCallbackListHead;
  while ( 1 )
  {
    v34 = v5;
    if ( v5 == &KeBugCheckAddRemovePagesCallbackListHead )
      break;
    v33 = v5;
    v36[2] = v5;
    result = KeValidateBugCheckCallbackRecord((int)v5, 6, v36);
    if ( result )
    {
      if ( v4 )
      {
        v9 = v5[3];
        if ( v9
          && MmIsAddressValid(v9, v6, v7, v8)
          && ((v2 = (char *)v5[3], v11 = 0, v22 = 0, !v2) || v35 > 0x7FFFFFFF ? (v12 = -1073741811) : (v12 = sub_56522C(v2, v10, (int *)&v22), v11 = v22),
              v12 >= 0) )
        {
          v22 = (int *)v2;
          v1 = (int)v11 + 1;
        }
        else
        {
          v1 = 1;
          v22 = &dword_6A12F0;
          v2 = (char *)&dword_6A12F0;
        }
        v25 = v1;
        v42 = v2;
        v43 = 0;
        v44 = v1;
        v45 = 0;
        v20 = (int *)&v42;
        v19 = 1;
        EtwWrite(
          IopLiveDumpEtwRegHandle,
          SHIDWORD(IopLiveDumpEtwRegHandle),
          (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_REMOVEPAGES_CALLBACK_START,
          0);
      }
      v28 = 0;
      v30 = *v27;
      v24 = 0;
      do
      {
        v31 = 0;
        v29 = 0;
        v32 = 0;
        v13 = 0;
        LOBYTE(v21) = 0;
        ((void (__fastcall *)(int, int *, int *, int, int, int *, int, int *, int))v33[2])(
          6,
          v33,
          &v28,
          20,
          v19,
          v20,
          v21,
          v22,
          v23);
        v15 = v24;
        result = 0x80000000;
        if ( v24 >= 0 && v32 )
        {
          v16 = v29;
          v14 = v29 & 0x80000003;
          if ( (v29 & 0x80000003) != 0 )
          {
            if ( (v29 & 0x80000000) != 0 )
            {
              v13 = 1;
              v16 = v29 & 0x7FFFFFFF;
              v29 &= 0x7FFFFFFFu;
            }
            else
            {
              v13 = 0;
            }
            v14 = v16 - 1;
            if ( ((v16 - 1) & v16) != 0 )
            {
              result = -1073741811;
            }
            else
            {
              if ( (v16 & 1) != 0 )
              {
                v17 = 0;
                v18 = v31;
              }
              else
              {
                v17 = 2;
                v18 = v31 >> 12;
              }
              v37[0] = v27[59];
              v37[1] = v27[60];
              v39 = v37;
              result = IoFreeDumpRange(v38, v18, v32, v17);
            }
            if ( result < 0 )
            {
              v13 = 0;
              result = IopLiveDumpTraceRemovePagesCallbackFailure((int)v2, v1, result, v14);
            }
          }
          v15 = v24;
        }
      }
      while ( v13 );
      if ( v15 < 0 )
        result = IopLiveDumpTraceRemovePagesCallbackFailure((int)v2, v1, v15, v14);
      v4 = v26;
      if ( v26 )
      {
        v42 = v2;
        v43 = 0;
        v44 = v1;
        v45 = 0;
        v20 = (int *)&v42;
        v19 = 1;
        result = EtwWrite(
                   IopLiveDumpEtwRegHandle,
                   SHIDWORD(IopLiveDumpEtwRegHandle),
                   (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_REMOVEPAGES_CALLBACK_END,
                   0);
      }
    }
    else if ( !v36[0] )
    {
      break;
    }
    v5 = (int *)*v5;
  }
  if ( v4 )
    result = EtwWrite(
               IopLiveDumpEtwRegHandle,
               SHIDWORD(IopLiveDumpEtwRegHandle),
               (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_REMOVEPAGES_CALLBACKS_END,
               0);
  return result;
}
