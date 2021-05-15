// PiPnpRtlServiceFilterCallback 
 
int __fastcall PiPnpRtlServiceFilterCallback(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r6
  int v7; // r7
  int v8; // r9
  int v9; // r8
  unsigned __int16 *v10; // r2
  int v11; // r4
  int v12; // r4
  unsigned int v13; // r0
  unsigned int v14; // r3
  int v15; // r2
  int *v16; // r3
  int v17; // r10
  unsigned int v18; // r8
  int *v19; // r9
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r0
  unsigned int v24; // r3
  unsigned int v25; // r3
  unsigned int v26; // r3
  unsigned __int16 *v27; // r6
  int (__fastcall *v28)(int, int, int, _DWORD); // r4
  int v30; // [sp+10h] [bp-B0h] BYREF
  unsigned int v31; // [sp+14h] [bp-ACh] BYREF
  char v32[4]; // [sp+18h] [bp-A8h] BYREF
  int v33; // [sp+1Ch] [bp-A4h]
  unsigned __int16 *v34; // [sp+20h] [bp-A0h]
  int v35; // [sp+24h] [bp-9Ch]
  unsigned int v36; // [sp+28h] [bp-98h]
  unsigned __int16 v37[4]; // [sp+30h] [bp-90h] BYREF
  int *v38; // [sp+38h] [bp-88h]
  int v39[2]; // [sp+40h] [bp-80h] BYREF
  int v40[2]; // [sp+48h] [bp-78h] BYREF
  char v41[76]; // [sp+50h] [bp-70h] BYREF
  __int16 v42; // [sp+9Ch] [bp-24h]

  v5 = *(unsigned __int8 *)(a4 + 4);
  v6 = a1;
  v7 = 0;
  v8 = a3;
  v34 = a2;
  v35 = a3;
  v9 = (int)a2;
  v33 = a1;
  v32[0] = 0;
  v31 = 0;
  if ( v5 && (CmIsDevicePresent(a1, a2, v32) < 0 || !v32[0]) )
    return v7;
  v10 = *(unsigned __int16 **)a4;
  if ( !*(_DWORD *)a4 || *v10 < 2u || !**((_WORD **)v10 + 1) )
  {
    v7 = 1;
LABEL_63:
    v28 = *(int (__fastcall **)(int, int, int, _DWORD))(a4 + 16);
    if ( v28 )
      v7 = v28(v6, v9, v8, *(_DWORD *)(a4 + 20));
    return v7;
  }
  while ( 1 )
  {
    v31 = *(_DWORD *)(a4 + 12);
    v11 = CmGetDeviceRegProp(v6, v9, 0, 5, (int)&v30, *(_DWORD *)(a4 + 8), (int)&v31);
    if ( !v11 && v31 < 2 )
      goto LABEL_15;
    if ( v11 != -1073741789 )
      goto LABEL_26;
    if ( v31 < 2 )
    {
LABEL_15:
      v11 = -1073741811;
      goto LABEL_16;
    }
    v12 = ExAllocatePoolWithTag(1, v31, 1198550608);
    if ( !v12 )
      break;
    v13 = *(_DWORD *)(a4 + 8);
    if ( v13 )
      ExFreePoolWithTag(v13);
    v14 = v31;
    *(_DWORD *)(a4 + 8) = v12;
    *(_DWORD *)(a4 + 12) = v14;
  }
  v11 = -1073741670;
LABEL_26:
  if ( !v11 )
  {
    *(_WORD *)(*(_DWORD *)(a4 + 8) + 2 * (*(_DWORD *)(a4 + 12) >> 1) - 2) = 0;
    if ( RtlInitUnicodeStringEx((int)v37, *(unsigned __int16 **)(a4 + 8)) >= 0 )
    {
      if ( RtlEqualUnicodeString(*(unsigned __int16 **)a4, v37, 1) )
      {
        v7 = 1;
LABEL_62:
        v8 = v35;
        goto LABEL_63;
      }
    }
  }
LABEL_16:
  v39[0] = 1;
  v39[1] = 2;
  v36 = 0;
  v40[0] = 18;
  v15 = v30;
  v40[1] = 19;
  v16 = v39;
  while ( 2 )
  {
    v17 = *v16;
    v38 = v16 + 1;
    if ( v17 == 2 )
    {
      v31 = 78;
      v11 = CmGetDeviceRegProp(v6, v9, 0, 9, (int)&v30, (int)v41, (int)&v31);
      if ( v11 < 0 )
        return v7;
      v15 = v30;
      if ( v30 != 1 || v31 < 2 )
        return v7;
      v42 = 0;
    }
    v18 = 0;
    v19 = v40;
    do
    {
      while ( 1 )
      {
        v20 = *(_DWORD *)(a4 + 12);
        v31 = v20;
        if ( v17 == 1 )
        {
          v21 = CmGetDeviceRegProp(v6, (int)v34, 0, *v19, (int)&v30, *(_DWORD *)(a4 + 8), (int)&v31);
LABEL_32:
          v15 = v30;
          v20 = v31;
          v11 = v21;
          goto LABEL_33;
        }
        if ( v17 == 2 )
        {
          v21 = CmGetInstallerClassRegProp(v6, (int)v41, 0, *v19, (int)&v30, *(_DWORD *)(a4 + 8), (int)&v31);
          goto LABEL_32;
        }
LABEL_33:
        if ( !v11 && v20 < 2 )
        {
LABEL_35:
          v11 = -1073741811;
          goto LABEL_57;
        }
        if ( v11 != -1073741789 )
          break;
        if ( v20 < 2 )
          goto LABEL_35;
        v22 = ExAllocatePoolWithTag(1, v20, 1198550608);
        if ( !v22 )
        {
          v11 = -1073741670;
          v15 = v30;
          break;
        }
        v23 = *(_DWORD *)(a4 + 8);
        if ( v23 )
          ExFreePoolWithTag(v23);
        v15 = v30;
        v24 = v31;
        *(_DWORD *)(a4 + 8) = v22;
        *(_DWORD *)(a4 + 12) = v24;
        v6 = v33;
      }
      if ( v11 >= 0 && v15 == 7 )
      {
        v25 = *(_DWORD *)(a4 + 12);
        if ( v25 > 2 )
        {
          *(_WORD *)(*(_DWORD *)(a4 + 8) + 2 * (v25 >> 1) - 2) = 0;
          v15 = v30;
        }
        v26 = *(_DWORD *)(a4 + 12);
        if ( v26 > 4 )
        {
          *(_WORD *)(*(_DWORD *)(a4 + 8) + 2 * (v26 >> 1) - 4) = 0;
          v15 = v30;
        }
        v27 = *(unsigned __int16 **)(a4 + 8);
        if ( *v27 )
        {
          while ( RtlInitUnicodeStringEx((int)v37, v27) < 0 || !RtlEqualUnicodeString(*(unsigned __int16 **)a4, v37, 1) )
          {
            v27 += wcslen(v27) + 1;
            if ( !*v27 )
              goto LABEL_55;
          }
          v7 = 1;
LABEL_55:
          v15 = v30;
        }
        if ( v7 )
        {
          v6 = v33;
          v9 = (int)v34;
          goto LABEL_62;
        }
      }
LABEL_57:
      ++v18;
      v6 = v33;
      ++v19;
    }
    while ( v18 < 2 );
    v6 = v33;
    v9 = (int)v34;
    ++v36;
    v16 = v38;
    if ( v36 < 2 )
      continue;
    return v7;
  }
}
