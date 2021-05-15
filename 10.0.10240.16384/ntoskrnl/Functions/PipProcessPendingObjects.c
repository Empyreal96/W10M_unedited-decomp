// PipProcessPendingObjects 
 
int __fastcall PipProcessPendingObjects(int a1, int (__fastcall *a2)(char *, int, _DWORD, char *, int, int *), int a3, int (__fastcall *a4)(char *, int, int, _DWORD))
{
  unsigned __int16 *v6; // r4
  unsigned int v7; // r6
  int v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r0
  char v13; // [sp+8h] [bp-240h] BYREF
  char v14[3]; // [sp+9h] [bp-23Fh] BYREF
  int v15; // [sp+Ch] [bp-23Ch] BYREF
  int v16; // [sp+10h] [bp-238h] BYREF
  int v17; // [sp+14h] [bp-234h] BYREF
  int (__fastcall *v18)(char *, int, int, _DWORD); // [sp+18h] [bp-230h]
  int i; // [sp+1Ch] [bp-22Ch]
  char v20[552]; // [sp+20h] [bp-228h] BYREF

  v18 = a4;
  v16 = 0;
  v17 = 0;
  v15 = 260;
  v6 = 0;
  v7 = 0;
  v8 = 1;
  v9 = PnpCtxRegEnumKey(a1, a1, 0, (int)v20, (unsigned int *)&v15);
  for ( i = -2147483622; v9 != i; v9 = PnpCtxRegEnumKey(v10, a1, v8++, (int)v20, (unsigned int *)&v15) )
  {
    if ( v9 == -1073741444 )
      break;
    if ( v9 < 0 )
      goto LABEL_28;
    v10 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, a1, (int)v20, 0);
    if ( v10 >= 0 )
    {
      if ( !a2 )
        goto LABEL_8;
      v13 = 0;
      v10 = a2(v20, v16, 0, &v13, 1, &v16);
      v9 = v10;
      if ( v10 < 0 )
        goto LABEL_28;
      if ( !v13 )
      {
LABEL_8:
        v15 = v7;
        v10 = PnpCtxRegQueryValue(v10, v16, L"DependOnFirmware", &v17, (int)v6, (unsigned int *)&v15);
        if ( v10 == -1073741789 || v10 == -2147483643 )
        {
          if ( v6 )
            ExFreePoolWithTag((unsigned int)v6);
          v7 = v15;
          v11 = ExAllocatePoolWithTag(1, v15, 1114664528);
          v6 = (unsigned __int16 *)v11;
          if ( !v11 )
            return -1073741670;
          v10 = PnpCtxRegQueryValue(v11, v16, L"DependOnFirmware", &v17, v11, (unsigned int *)&v15);
        }
        if ( v10 == -1073741772 )
        {
          if ( !v6 )
            goto LABEL_24;
          if ( v7 >= 2 )
            *v6 = 0;
        }
        else if ( v10 < 0 )
        {
          goto LABEL_26;
        }
        if ( !v6 || v7 < 2 || !*v6 || (v14[0] = 0, v10 = PnpCheckDriverDependencies(v6, v14, 0), v10 >= 0) && v14[0] )
        {
LABEL_24:
          v10 = v18(v20, a1, v16, 0);
          if ( v10 >= 0 )
            --v8;
          goto LABEL_26;
        }
      }
    }
LABEL_26:
    v15 = 260;
  }
  v9 = 0;
LABEL_28:
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  return v9;
}
