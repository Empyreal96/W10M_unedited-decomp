// PiDevCfgResolveVariable 
 
int __fastcall PiDevCfgResolveVariable(int a1, unsigned __int16 *a2, unsigned int **a3)
{
  int v4; // r3
  int v5; // r5
  unsigned __int16 *v6; // r7
  int v7; // r6
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r8
  unsigned int v12; // r10
  int v13; // r0
  int v14; // r4
  int *v15; // r8
  int v16; // t1
  int *v17; // r8
  int v18; // t1
  int v19; // r4
  int (__fastcall *v20)(int, _DWORD, unsigned int *); // r8
  unsigned int v21; // r4
  int v22; // r0
  unsigned int *v23; // r5
  int v24; // r0
  unsigned int v25; // r3
  int v26; // r3
  int v28; // r10
  __int16 **v29; // r3
  int v30; // r3
  int v31; // r2
  unsigned __int16 *v32; // r0
  int v34; // r8
  unsigned __int16 *v35; // r0
  int v36; // r1
  int v37; // r0
  unsigned int *v38; // r0
  unsigned int **v39; // r2
  unsigned __int16 *v40; // [sp+4h] [bp-54h] BYREF
  int v41; // [sp+8h] [bp-50h]
  unsigned __int16 *v42; // [sp+Ch] [bp-4Ch]
  unsigned int v43; // [sp+10h] [bp-48h] BYREF
  unsigned int **v44; // [sp+14h] [bp-44h]
  unsigned __int16 v45[4]; // [sp+18h] [bp-40h] BYREF
  int v46; // [sp+20h] [bp-38h]
  int v47; // [sp+24h] [bp-34h]
  unsigned __int16 *v48; // [sp+28h] [bp-30h]
  int v49; // [sp+2Ch] [bp-2Ch]
  int v50; // [sp+30h] [bp-28h]
  int v51; // [sp+34h] [bp-24h]

  v4 = *a2;
  v5 = a1;
  v6 = 0;
  v7 = 0;
  v44 = a3;
  v40 = 0;
  v41 = a1;
  v42 = 0;
  if ( !v4 )
    return sub_7EB488();
  *a3 = 0;
  RtlInitUnicodeString((unsigned int)v45, a2);
  if ( RtlHashUnicodeString(v45, 1, 0, &v43) < 0 )
    v9 = 0;
  else
    v9 = v43;
  v10 = *(_DWORD *)(v5 + 12);
  v11 = *(_DWORD *)(v10 + 8 * (v9 % 0x7F));
  v12 = v10 + 8 * (v9 % 0x7F);
  v43 = v12;
  if ( v11 != v12 )
  {
    do
    {
      v23 = (unsigned int *)v11;
      if ( RtlEqualUnicodeString(v45, (unsigned __int16 *)(v11 + 8), 1) )
        break;
      v11 = *(_DWORD *)v11;
      v23 = 0;
    }
    while ( v11 != v12 );
    if ( v23 )
    {
LABEL_68:
      *v44 = v23;
      v23 = 0;
LABEL_69:
      if ( v23 )
        ExFreePoolWithTag((unsigned int)v23);
      goto LABEL_13;
    }
    v5 = v41;
  }
  v46 = 24;
  v47 = *(_DWORD *)(v5 + 8);
  v49 = 576;
  v48 = v45;
  v50 = 0;
  v51 = 0;
  v13 = ZwOpenKey();
  v7 = v13;
  if ( v13 >= 0 )
  {
    v7 = IopGetRegistryValue(0, &dword_8CA6A8, 0, &v40);
    v6 = v40;
    if ( v7 < 0 )
      goto LABEL_13;
    if ( *((_DWORD *)v40 + 1) != 1
      || ((v25 = *((_DWORD *)v40 + 3), v25 < 2)
       || *(unsigned __int16 *)((char *)&v40[(v25 >> 1) - 1] + *((_DWORD *)v40 + 2)) ? (v26 = 0) : (v26 = 1),
          !v26) )
    {
      v7 = -1073741823;
      goto LABEL_13;
    }
    v28 = *((_DWORD *)v40 + 2);
    v19 = 0;
    v17 = (int *)&off_8C6D50;
    while ( 1 )
    {
      v18 = *v17;
      v17 += 2;
      if ( !wcsicmp(v18, (unsigned __int16 *)((char *)v6 + v28)) )
        break;
      if ( (unsigned int)++v19 >= 8 )
        goto LABEL_20;
    }
    v20 = (int (__fastcall *)(int, _DWORD, unsigned int *))*(&off_8C6D50 + 2 * v19 + 1);
    if ( !v20 )
    {
LABEL_20:
      v7 = -1073741772;
      goto LABEL_13;
    }
    v12 = v43;
    v21 = 0;
LABEL_23:
    v22 = ExAllocatePoolWithTag(1, 28, 1667526736);
    v23 = (unsigned int *)v22;
    if ( v22 )
    {
      if ( RtlCreateUnicodeString(v22 + 8, a2) )
      {
        if ( v20 )
        {
          v24 = v20(v41, 0, v23);
          v7 = v24;
          if ( v24 < 0 )
          {
            if ( v24 == -1073741772 )
              v7 = -1073741823;
            goto LABEL_69;
          }
          goto LABEL_65;
        }
        v34 = (int)v42;
        if ( v42 )
        {
          v35 = v42;
          v23[4] = 1;
          v36 = 2 * (wcslen(v35) + 1);
          v23[5] = v36;
          v37 = ExAllocatePoolWithTag(1, v36, 1667526736);
          v23[6] = v37;
          if ( v37 )
          {
            memmove(v37, v34, v23[5]);
LABEL_65:
            v39 = *(unsigned int ***)(v12 + 4);
            *v23 = v12;
            v23[1] = (unsigned int)v39;
            if ( *v39 != (unsigned int *)v12 )
              __fastfail(3u);
            *v39 = v23;
            *(_DWORD *)(v12 + 4) = v23;
            goto LABEL_68;
          }
        }
        else
        {
          v23[4] = 4;
          v23[5] = 4;
          v38 = (unsigned int *)ExAllocatePoolWithTag(1, 4, 1667526736);
          v23[6] = (unsigned int)v38;
          if ( v38 )
          {
            *v38 = v21;
            goto LABEL_65;
          }
        }
      }
      v7 = -1073741670;
      goto LABEL_69;
    }
    v7 = -1073741670;
LABEL_13:
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
    return v7;
  }
  if ( v13 == -1073741772 )
  {
    v7 = 0;
    v14 = 0;
    v15 = (int *)&off_8C6D20;
    while ( 1 )
    {
      v16 = *v15;
      v15 += 3;
      if ( !wcsicmp(v16, a2) )
        break;
      if ( (unsigned int)++v14 >= 4 )
        goto LABEL_48;
    }
    v29 = &(&off_8C6D20)[3 * v14];
    if ( v29 )
    {
      v21 = (unsigned int)v29[2];
      v42 = (unsigned __int16 *)v29[1];
      goto LABEL_28;
    }
LABEL_48:
    if ( *a2 == 48 && ((v30 = a2[1], v30 == 120) || v30 == 88) )
    {
      v31 = 16;
      v32 = a2 + 2;
    }
    else
    {
      v31 = 10;
      v32 = a2;
    }
    v21 = wcstoul(v32, &v40, v31);
    if ( !v40 || *v40 )
      return -1073741772;
LABEL_28:
    v20 = 0;
    goto LABEL_23;
  }
  return v7;
}
