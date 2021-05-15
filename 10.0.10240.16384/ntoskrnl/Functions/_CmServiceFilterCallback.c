// _CmServiceFilterCallback 
 
int __fastcall CmServiceFilterCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r7
  int v7; // r9
  unsigned __int16 *v8; // r1
  int v9; // r0
  int v10; // r4
  int v11; // r1
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r2
  int *v15; // r3
  int v16; // r10
  unsigned int v17; // r8
  int *v18; // r9
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r0
  int v22; // r0
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned __int16 *v25; // r6
  int (__fastcall *v26)(int, int, int, _DWORD); // r4
  unsigned int v28; // [sp+10h] [bp-B0h] BYREF
  int v29; // [sp+14h] [bp-ACh] BYREF
  int v30; // [sp+18h] [bp-A8h]
  int v31; // [sp+1Ch] [bp-A4h]
  int v32; // [sp+20h] [bp-A0h]
  unsigned int v33; // [sp+24h] [bp-9Ch]
  int *v34; // [sp+28h] [bp-98h]
  unsigned __int16 v35[4]; // [sp+30h] [bp-90h] BYREF
  int v36[2]; // [sp+38h] [bp-88h] BYREF
  unsigned __int16 v37[4]; // [sp+40h] [bp-80h] BYREF
  int v38[2]; // [sp+48h] [bp-78h] BYREF
  char v39[76]; // [sp+50h] [bp-70h] BYREF
  __int16 v40; // [sp+9Ch] [bp-24h]

  v5 = a1;
  v6 = 0;
  v28 = 0;
  v29 = 0;
  v30 = a2;
  v31 = a3;
  v7 = a2;
  v32 = a1;
  if ( !a4 )
    return v6;
  v8 = *(unsigned __int16 **)a4;
  if ( !*(_DWORD *)a4 || !*v8 )
  {
    v6 = 1;
LABEL_62:
    v26 = *(int (__fastcall **)(int, int, int, _DWORD))(a4 + 12);
    if ( v26 )
      v6 = v26(v32, v7, a3, *(_DWORD *)(a4 + 16));
    return v6;
  }
  if ( RtlInitUnicodeStringEx((int)v37, v8) < 0 )
    return v6;
  while ( 1 )
  {
    v28 = *(_DWORD *)(a4 + 8);
    v9 = CmGetDeviceRegProp(v5, v7, 0, 5, (int)&v29, *(_DWORD *)(a4 + 4), (int)&v28);
    v10 = v9;
    v11 = v28;
    if ( !v9 && v28 < 2 )
      goto LABEL_13;
    if ( v9 != -1073741789 )
      goto LABEL_24;
    if ( v28 < 2 )
    {
LABEL_13:
      v10 = -1073741811;
      goto LABEL_14;
    }
    v12 = *(_DWORD *)(a4 + 4);
    if ( v12 )
    {
      ExFreePoolWithTag(v12);
      v11 = v28;
    }
    v13 = ExAllocatePoolWithTag(1, v11, 1380994640);
    *(_DWORD *)(a4 + 4) = v13;
    if ( !v13 )
      break;
    *(_DWORD *)(a4 + 8) = v28;
  }
  v10 = -1073741801;
  *(_DWORD *)(a4 + 8) = 0;
LABEL_24:
  if ( !v10 )
  {
    *(_WORD *)(*(_DWORD *)(a4 + 4) + 2 * (*(_DWORD *)(a4 + 8) >> 1) - 2) = 0;
    if ( RtlInitUnicodeStringEx((int)v35, *(unsigned __int16 **)(a4 + 4)) >= 0 )
    {
      if ( RtlEqualUnicodeString(v37, v35, 1) )
      {
        v6 = 1;
LABEL_61:
        a3 = v31;
        goto LABEL_62;
      }
    }
  }
LABEL_14:
  v36[0] = 1;
  v36[1] = 2;
  v33 = 0;
  v38[0] = 18;
  v14 = v29;
  v38[1] = 19;
  v15 = v36;
  while ( 2 )
  {
    v16 = *v15;
    v34 = v15 + 1;
    if ( v16 == 2 )
    {
      v28 = 78;
      v10 = CmGetDeviceRegProp(v5, v7, 0, 9, (int)&v29, (int)v39, (int)&v28);
      if ( v10 < 0 )
        return v6;
      v14 = v29;
      if ( v29 != 1 || v28 < 2 )
        return v6;
      v40 = 0;
    }
    v17 = 0;
    v18 = v38;
    do
    {
      while ( 1 )
      {
        v19 = *(_DWORD *)(a4 + 8);
        v28 = v19;
        if ( v16 == 1 )
        {
          v20 = CmGetDeviceRegProp(v5, v30, 0, *v18, (int)&v29, *(_DWORD *)(a4 + 4), (int)&v28);
LABEL_30:
          v19 = v28;
          v14 = v29;
          v10 = v20;
          goto LABEL_31;
        }
        if ( v16 == 2 )
        {
          v20 = CmGetInstallerClassRegProp(v5, (int)v39, 0, *v18, (int)&v29, *(_DWORD *)(a4 + 4), (int)&v28);
          goto LABEL_30;
        }
LABEL_31:
        if ( !v10 && v19 < 2 )
        {
LABEL_33:
          v10 = -1073741811;
          goto LABEL_56;
        }
        if ( v10 != -1073741789 )
          break;
        if ( v19 < 2 )
          goto LABEL_33;
        v21 = *(_DWORD *)(a4 + 4);
        if ( v21 )
        {
          ExFreePoolWithTag(v21);
          v19 = v28;
        }
        v22 = ExAllocatePoolWithTag(1, v19, 1380994640);
        v14 = v29;
        *(_DWORD *)(a4 + 4) = v22;
        if ( !v22 )
        {
          v10 = -1073741801;
          *(_DWORD *)(a4 + 8) = 0;
          break;
        }
        *(_DWORD *)(a4 + 8) = v28;
      }
      if ( v10 >= 0 && v14 == 7 )
      {
        v23 = *(_DWORD *)(a4 + 8);
        if ( v23 > 2 )
        {
          *(_WORD *)(*(_DWORD *)(a4 + 4) + 2 * (v23 >> 1) - 2) = 0;
          v14 = v29;
        }
        v24 = *(_DWORD *)(a4 + 8);
        if ( v24 > 4 )
        {
          *(_WORD *)(*(_DWORD *)(a4 + 4) + 2 * (v24 >> 1) - 4) = 0;
          v14 = v29;
        }
        v25 = *(unsigned __int16 **)(a4 + 4);
        if ( *v25 )
        {
          while ( RtlInitUnicodeStringEx((int)v35, v25) < 0 || !RtlEqualUnicodeString(v37, v35, 1) )
          {
            v25 += wcslen(v25) + 1;
            if ( !*v25 )
              goto LABEL_53;
          }
          v6 = 1;
LABEL_53:
          v14 = v29;
        }
        if ( v6 )
        {
          v7 = v30;
          goto LABEL_61;
        }
        v5 = v32;
      }
LABEL_56:
      ++v17;
      ++v18;
    }
    while ( v17 < 2 );
    v7 = v30;
    ++v33;
    v15 = v34;
    if ( v33 < 2 )
      continue;
    return v6;
  }
}
