// PiDqOpenUserObjectRegKey 
 
int __fastcall PiDqOpenUserObjectRegKey(int a1, int a2, int a3, int a4, int *a5, _DWORD *a6, _DWORD *a7, int a8)
{
  unsigned int v8; // r7
  unsigned int v9; // r6
  int v10; // r4
  int v12; // r0
  int v13; // r0
  int v14; // r0
  unsigned int v15; // [sp+14h] [bp-A4h] BYREF
  unsigned int v16; // [sp+18h] [bp-A0h] BYREF
  int v17; // [sp+1Ch] [bp-9Ch] BYREF
  _DWORD *v18; // [sp+20h] [bp-98h]
  unsigned __int16 v19; // [sp+28h] [bp-90h] BYREF
  _BYTE v20[6]; // [sp+2Ah] [bp-8Eh]
  int v21; // [sp+30h] [bp-88h]
  int v22; // [sp+34h] [bp-84h]
  int v23; // [sp+38h] [bp-80h]
  int v24; // [sp+3Ch] [bp-7Ch]
  char v25[104]; // [sp+50h] [bp-68h] BYREF

  v24 = a4;
  v21 = a3;
  v18 = a6;
  v19 = 0;
  *(_DWORD *)v20 = 0;
  *(_WORD *)&v20[4] = 0;
  *a6 = 0;
  v8 = 0;
  v9 = 0;
  v22 = a1;
  v23 = a2;
  v15 = 0;
  v16 = 0;
  v10 = PnpValidateObjectName(PiPnpRtlCtx, a1, a2, a8);
  if ( v10 >= 0 )
  {
    if ( !a5 )
      return sub_7C905C();
    if ( *a5 )
      v12 = *a5;
    else
      v12 = a5[2];
    SeQueryUserSidToken(v12, (int)v25, 0x44u, 0);
    v10 = RtlConvertSidToUnicodeString(&v19, v25, 1);
    if ( v10 >= 0 )
    {
      v10 = PnpConcatPWSTR(0x7FFFFFFF, 1483763280, &v16, 2, L"\\REGISTRY\\USER\\", *(_DWORD *)&v20[2]);
      v8 = v16;
      if ( v10 >= 0 )
      {
        v10 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, 0, v16, 0);
        if ( v10 >= 0 )
        {
          v10 = PiDqGetRelativeObjectRegPath(v22, v23, &v15);
          if ( v10 < 0 )
          {
            v9 = v15;
          }
          else
          {
            if ( v24 )
            {
              v9 = v15;
              v14 = PnpCtxRegCreateTree(PiPnpRtlCtx, 0, v15, 0, v21, 0, v18, &v17);
            }
            else
            {
              v17 = 2;
              if ( PiPnpRtlCtx )
                v13 = *(_DWORD *)PiPnpRtlCtx;
              else
                v13 = 0;
              v9 = v15;
              v14 = SysCtxRegOpenKey(v13, 0, v15, 0, v21);
            }
            v10 = v14;
            if ( v14 >= 0 && a7 )
              *a7 = v17;
          }
        }
      }
    }
  }
  if ( v10 == -1073741444 )
    v10 = -1073741772;
  if ( v9 )
    ExFreePoolWithTag(v9);
  if ( v8 )
    ExFreePoolWithTag(v8);
  RtlFreeAnsiString(&v19);
  return v10;
}
