// PiDqPnPGetObjectProperty 
 
int __fastcall PiDqPnPGetObjectProperty(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r4
  int v8; // r5
  int v9; // r6
  int v10; // r7
  int v12; // r8
  unsigned int v13; // r9
  int v14; // r4
  int v15; // r4
  int v16; // r4
  int result; // r0
  unsigned int v18; // r0
  int v19; // [sp+20h] [bp-30h] BYREF
  unsigned int v20; // [sp+24h] [bp-2Ch] BYREF
  _DWORD *v21; // [sp+28h] [bp-28h]
  int v22; // [sp+2Ch] [bp-24h]
  int v23; // [sp+30h] [bp-20h]

  v20 = 512;
  v21 = a4;
  v7 = *a4;
  v8 = a4[1];
  v9 = a4[2];
  v10 = a4[3];
  v19 = 0;
  v22 = a3;
  v23 = a1;
  v12 = 0;
  *a7 = v7;
  a7[1] = v8;
  a7[2] = v9;
  a7[3] = v10;
  v13 = 0;
  v14 = a4[4];
  a7[7] = 0;
  a7[8] = 0;
  a7[9] = 0;
  a7[4] = v14;
  a7[5] = a5;
  v15 = PnpAllocatePWSTR(a6, 0x7FFFFFFF, 1483763280, a7 + 6);
  if ( v15 >= 0 )
  {
    do
    {
      v16 = v20;
      if ( v20 > v13 )
      {
        v13 = v20;
        if ( v12 )
          ExFreePoolWithTag(v12);
        v12 = ExAllocatePoolWithTag(1, v16, 1483763280);
        if ( !v12 )
        {
          v15 = -1073741670;
          goto LABEL_16;
        }
      }
      v20 = 0;
      if ( !a2 )
        return sub_7C67B4(PiPnpRtlCtx);
      result = PnpGetObjectProperty(PiPnpRtlCtx, v23, a2, v22, a6, v21, &v19, v12, v13, &v20, 0);
      v15 = result;
    }
    while ( result == -1073741789 );
    if ( result >= 0 )
    {
      a7[7] = v19;
      a7[8] = v20;
      a7[9] = v12;
      return result;
    }
    if ( v12 )
      ExFreePoolWithTag(v12);
  }
  if ( v15 == -1073741275 )
    return 0;
LABEL_16:
  v18 = a7[6];
  if ( v18 )
    ExFreePoolWithTag(v18);
  return v15;
}
