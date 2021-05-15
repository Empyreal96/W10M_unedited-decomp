// PpForEachDeviceInstanceDriver 
 
int __fastcall PpForEachDeviceInstanceDriver(unsigned __int16 *a1, int a2, int a3)
{
  unsigned __int16 *v5; // r5
  int v6; // r4
  int v7; // r7
  int v8; // r2
  int *v9; // r6
  unsigned int v10; // r8
  int v11; // r1
  int v12; // r0
  int v14; // [sp+10h] [bp-98h] BYREF
  unsigned int v15; // [sp+14h] [bp-94h] BYREF
  int v16; // [sp+18h] [bp-90h] BYREF
  unsigned int v17; // [sp+1Ch] [bp-8Ch] BYREF
  int v18; // [sp+20h] [bp-88h] BYREF
  int v19; // [sp+24h] [bp-84h] BYREF
  int v20[4]; // [sp+28h] [bp-80h] BYREF
  unsigned __int16 v21[56]; // [sp+38h] [bp-70h] BYREF

  v14 = 0;
  v18 = 0;
  v19 = 0;
  v5 = 0;
  v6 = PnpUnicodeStringToWstr(&v19, 0, a1);
  if ( v6 >= 0 )
  {
    v7 = v19;
    v6 = CmOpenDeviceRegKey(PiPnpRtlCtx, v19, 16, 0, 131097, 0, (int)&v18, 0);
    if ( v6 < 0 )
    {
LABEL_32:
      v8 = v14;
    }
    else
    {
      v17 = 78;
      v6 = CmGetDeviceRegProp(PiPnpRtlCtx, v7, v18, 9, (int)&v16, (int)v21, (int)&v17);
      if ( v6 >= 0 && v16 == 1 && v17 )
        v6 = CmOpenInstallerClassRegKey((int *)PiPnpRtlCtx, v21, 0, (int)&v14, 131097, 0, (int)&v14, 0);
      v20[1] = (int)PiProcessDriverInstance;
      v20[2] = a3;
      v17 = 170;
      v20[0] = (int)a1;
      v5 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 170, 538996816);
      v8 = v14;
      if ( v5 )
      {
        v9 = &dword_40B458;
        v10 = 0;
        while ( 1 )
        {
          v11 = *((unsigned __int8 *)v9 + 4);
          if ( !*((_BYTE *)v9 + 4) || v8 )
          {
            v15 = v17;
            if ( v11 )
              v12 = CmGetInstallerClassRegProp(PiPnpRtlCtx, v21, v8, *v9, &v16, v5, &v15);
            else
              v12 = CmGetDeviceRegProp(PiPnpRtlCtx, v7, v18, *v9, (int)&v16, (int)v5, (int)&v15);
            v6 = v12;
            if ( v12 == -1073741789 )
              return sub_7CB5E4();
            if ( v12 == -1073741275 )
            {
              v6 = 0;
            }
            else
            {
              if ( v12 < 0 )
                goto LABEL_32;
              v6 = PiForEachDriverQueryRoutine(v16, v5, v15, v20);
              if ( v6 < 0 )
                goto LABEL_32;
            }
            v8 = v14;
          }
          ++v10;
          v9 += 2;
          if ( v10 >= 5 )
            goto LABEL_18;
        }
      }
      v6 = -1073741670;
    }
LABEL_18:
    if ( v7 )
    {
      PnpUnicodeStringToWstrFree(v7, (int)a1);
      v8 = v14;
    }
    if ( v5 )
    {
      ExFreePoolWithTag((unsigned int)v5);
      v8 = v14;
    }
    if ( v8 )
      ZwClose();
    if ( v18 )
      ZwClose();
  }
  return v6;
}
