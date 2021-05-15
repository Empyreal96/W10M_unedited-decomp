// pIoQueryDeviceDescription 
 
int __fastcall pIoQueryDeviceDescription(_DWORD **a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r9
  int v8; // r2
  int v9; // r4
  unsigned int *v10; // r3
  unsigned int v11; // r6
  unsigned int v12; // r10
  int v13; // r2
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v19; // r3
  int v20; // r2
  unsigned int *v21; // r3
  unsigned int v22; // r5
  unsigned int v23; // r9
  int v24; // r2
  int v25; // r2
  unsigned int v26; // r3
  int v27; // r2
  int v28; // r3
  int v30; // [sp+20h] [bp-98h] BYREF
  int v31; // [sp+24h] [bp-94h]
  int v32; // [sp+28h] [bp-90h] BYREF
  int v33; // [sp+2Ch] [bp-8Ch] BYREF
  int v34; // [sp+30h] [bp-88h]
  unsigned int v35; // [sp+34h] [bp-84h] BYREF
  unsigned int v36; // [sp+38h] [bp-80h] BYREF
  unsigned __int16 v37[2]; // [sp+40h] [bp-78h] BYREF
  char *v38; // [sp+44h] [bp-74h]
  int v39; // [sp+48h] [bp-70h]
  int v40; // [sp+4Ch] [bp-6Ch]
  int v41; // [sp+50h] [bp-68h]
  unsigned int v42; // [sp+58h] [bp-60h] BYREF
  unsigned int v43; // [sp+5Ch] [bp-5Ch]
  unsigned int v44; // [sp+60h] [bp-58h]
  unsigned int v45; // [sp+68h] [bp-50h] BYREF
  unsigned int v46; // [sp+6Ch] [bp-4Ch]
  unsigned int v47; // [sp+70h] [bp-48h]
  char var40[68]; // [sp+78h] [bp-40h] BYREF
  _DWORD **varg_r0; // [sp+C0h] [bp+8h]
  int varg_r1; // [sp+C4h] [bp+Ch]
  int varg_r2; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r1 = a2;
  varg_r2 = a3;
  v32 = 0;
  v33 = 0;
  v35 = 0;
  v36 = 0;
  v6 = a6;
  v30 = a2;
  v31 = a3;
  v37[1] = 28;
  v38 = var40;
  v34 = a6;
  v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)L"\\", a3, (int)var40);
  if ( v9 >= 0 )
  {
    v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)CmTypeString[*a1[2]], v8, *a1[2]);
    if ( v9 >= 0 )
    {
      v10 = a1[3];
      if ( v10 )
      {
        v11 = *v10;
        v12 = *v10 + 1;
LABEL_8:
        v15 = v30;
        v14 = v31;
        v39 = v30;
        v41 = v31;
        while ( 1 )
        {
          if ( v11 >= v12 )
            return v9;
          v30 = v15;
          v31 = v14;
          v37[0] = 26;
          v9 = RtlIntegerToUnicodeString(v11, 10, v37);
          if ( v9 < 0 )
            return v9;
          v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)L"\\", v16, v17);
          if ( v9 < 0 )
            return v9;
          v9 = RtlAppendUnicodeStringToString((unsigned __int16 *)&v30, v37);
          if ( v9 < 0 )
            return v9;
          v9 = IopOpenRegistryKey((int)&v33, 0, (int)&v30, 131097, 0);
          if ( v9 >= 0 )
          {
            v9 = IopGetRegistryValues(v33, (int *)&v42);
            ZwClose();
            v33 = 0;
            if ( v9 >= 0 )
              break;
          }
LABEL_46:
          v15 = v39;
          v14 = v41;
          ++v11;
        }
        v19 = (int)a1[4];
        if ( !v19 )
        {
          v9 = ((int (__fastcall *)(_DWORD *, int *, _DWORD, int, int, _DWORD, unsigned int, unsigned int *, _DWORD, _DWORD, _DWORD))a1[6])(
                 a1[7],
                 &v30,
                 **a1,
                 a5,
                 v6,
                 *a1[2],
                 v11,
                 &v42,
                 0,
                 0,
                 0);
          goto LABEL_39;
        }
        v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)L"\\", v18, v19);
        if ( v9 >= 0 )
        {
          v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)CmTypeString[*a1[4]], v20, *a1[4]);
          if ( v9 >= 0 )
          {
            v21 = a1[5];
            if ( v21 )
            {
              v22 = *v21;
              v23 = *v21 + 1;
            }
            else
            {
              if ( IopOpenRegistryKey((int)&v32, 0, (int)&v30, 131097, 0) < 0
                || (v9 = IopGetRegistryKeyInformation(v32, (int *)&v36, v24), ZwClose(), v32 = 0, v9 < 0) )
              {
                v9 = 0;
                goto LABEL_39;
              }
              v22 = 0;
              v23 = *(_DWORD *)(v36 + 20);
              ExFreePoolWithTag(v36);
              v36 = 0;
            }
            v26 = v30;
            v25 = v31;
            v35 = v30;
            v40 = v31;
            while ( v22 < v23 )
            {
              v30 = v26;
              v31 = v25;
              v37[0] = 26;
              v9 = RtlIntegerToUnicodeString(v22, 10, v37);
              if ( v9 < 0 )
                break;
              v9 = RtlAppendUnicodeToString((unsigned __int16 *)&v30, (int)L"\\", v27, v28);
              if ( v9 < 0 )
                break;
              v9 = RtlAppendUnicodeStringToString((unsigned __int16 *)&v30, v37);
              if ( v9 < 0 )
                break;
              v9 = IopOpenRegistryKey((int)&v32, 0, (int)&v30, 131097, 0);
              if ( v9 >= 0 )
              {
                v9 = IopGetRegistryValues(v32, (int *)&v45);
                ZwClose();
                v32 = 0;
                if ( v9 >= 0 )
                {
                  v9 = ((int (__fastcall *)(_DWORD *, int *, _DWORD, int, int, _DWORD, unsigned int, unsigned int *, _DWORD, unsigned int, unsigned int *))a1[6])(
                         a1[7],
                         &v30,
                         **a1,
                         a5,
                         v34,
                         *a1[2],
                         v11,
                         &v42,
                         *a1[4],
                         v22,
                         &v45);
                  if ( v45 )
                  {
                    ExFreePoolWithTag(v45);
                    v45 = 0;
                  }
                  if ( v46 )
                  {
                    ExFreePoolWithTag(v46);
                    v46 = 0;
                  }
                  if ( v47 )
                  {
                    ExFreePoolWithTag(v47);
                    v47 = 0;
                  }
                  if ( v9 < 0 )
                    break;
                }
              }
              v26 = v35;
              v25 = v40;
              ++v22;
            }
            v6 = v34;
          }
        }
LABEL_39:
        if ( v42 )
        {
          ExFreePoolWithTag(v42);
          v42 = 0;
        }
        if ( v43 )
        {
          ExFreePoolWithTag(v43);
          v43 = 0;
        }
        if ( v44 )
        {
          ExFreePoolWithTag(v44);
          v44 = 0;
        }
        if ( v9 < 0 )
          return v9;
        goto LABEL_46;
      }
      v9 = IopOpenRegistryKey((int)&v33, 0, (int)&v30, 131097, 0);
      if ( v9 >= 0 )
      {
        v9 = IopGetRegistryKeyInformation(v33, (int *)&v35, v13);
        ZwClose();
        v33 = 0;
        if ( v9 >= 0 )
        {
          v11 = 0;
          v12 = *(_DWORD *)(v35 + 20);
          ExFreePoolWithTag(v35);
          goto LABEL_8;
        }
      }
    }
  }
  return v9;
}
