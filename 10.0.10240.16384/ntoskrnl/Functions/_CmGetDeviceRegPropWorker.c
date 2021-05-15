// _CmGetDeviceRegPropWorker 
 
int __fastcall CmGetDeviceRegPropWorker(int a1, int a2, int a3, int a4, int *a5, int a6, unsigned int *a7, __int16 a8)
{
  int v8; // r8
  int v10; // r6
  int v11; // r9
  unsigned int v12; // r5
  const __int16 *v13; // r0
  int (__cdecl *v14)(int, int, int); // r4
  int v15; // r0
  int v16; // r3
  int v18; // [sp+20h] [bp-A0h] BYREF
  int v19; // [sp+24h] [bp-9Ch]
  unsigned int v20; // [sp+28h] [bp-98h]
  unsigned int v21; // [sp+2Ch] [bp-94h]
  int v22; // [sp+30h] [bp-90h]
  int v23; // [sp+34h] [bp-8Ch]
  int v24; // [sp+38h] [bp-88h]

  v8 = a3;
  v24 = a2;
  v10 = 0;
  v18 = 0;
  v19 = a6;
  v22 = a1;
  v23 = 0;
  v11 = 0;
  if ( a8 || !a7 || !a5 )
    return -1073741811;
  v12 = *a7;
  if ( !*a7 )
  {
    v19 = 0;
    goto LABEL_6;
  }
  if ( !a6 )
    return -1073741811;
LABEL_6:
  *a7 = 0;
  *a5 = 0;
  v20 = v12;
  if ( (unsigned int)(a4 - 1) > 0x24 || !*((_BYTE *)DevicePropertyRead + a4) )
    return -1073741264;
  if ( !a3 )
  {
    v11 = CmOpenDeviceRegKey(a1, a2, 16, 0, 33554433, 0, (int)&v18, 0);
    if ( v11 < 0 )
      goto LABEL_32;
    v10 = v18;
    v12 = v20;
    a1 = v22;
  }
  if ( (a4 >= 15 || a4 < 9) && a4 >= 8 && (a4 >= 20 || a4 < 16) && (unsigned int)(a4 - 8) <= 0x1C )
    __asm { ADD             PC, R3 }
  v13 = MapCmDevicePropertyToRegValue(a1, a4);
  if ( v13 )
  {
    v21 = v12;
    if ( !v8 )
      v8 = v10;
    v14 = *(int (__cdecl **)(int, int, int))(v22 + 168);
    if ( !v14 )
      v14 = PnpRegQueryValueIndirect;
    v15 = v14(v22, v8, (int)v13);
    if ( v15 == -1073741772 || v15 == -1073741444 )
      goto LABEL_23;
    if ( v15 < 0 && v15 != -1073741789 )
    {
      v11 = v15;
      goto LABEL_32;
    }
    v16 = v23;
    if ( v23 == 1 )
    {
      if ( v21 < 2 )
      {
LABEL_23:
        v11 = -1073741275;
LABEL_32:
        v10 = v18;
        goto LABEL_33;
      }
    }
    else if ( v23 == 7 )
    {
      if ( v21 < 2 )
      {
        v11 = -1073741275;
        goto LABEL_32;
      }
    }
    else if ( v21 != 4 && v23 == 4 )
    {
      goto LABEL_23;
    }
    *a7 = v21;
    *a5 = v16;
    if ( v15 || !v20 )
      v11 = -1073741789;
    goto LABEL_32;
  }
  v11 = -1073741264;
LABEL_33:
  if ( !v10 )
    return v11;
  ZwClose();
  return v11;
}
