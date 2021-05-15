// PiDevCfgCopyDeviceKeys 
 
int __fastcall PiDevCfgCopyDeviceKeys(int a1, int a2, int a3, int a4)
{
  int v7; // r10
  int v8; // r5
  int *v9; // r0
  int *v10; // r4
  int **v12; // r1
  unsigned int v13; // r0
  int *v14; // r3
  __int64 v15; // kr00_8
  int v16; // r2
  int v17; // r2
  __int64 v18; // kr10_8
  int v19; // [sp+10h] [bp-48h]
  int *v21; // [sp+18h] [bp-40h] BYREF
  int **v22; // [sp+1Ch] [bp-3Ch]
  int v23; // [sp+20h] [bp-38h]
  int v24; // [sp+24h] [bp-34h]
  int *v25; // [sp+28h] [bp-30h]
  int v26; // [sp+2Ch] [bp-2Ch]
  int v27; // [sp+30h] [bp-28h]
  int v28; // [sp+34h] [bp-24h]

  v22 = &v21;
  v7 = 0;
  v21 = (int *)&v21;
  v19 = 0;
  v8 = 0;
  v9 = (int *)ExAllocatePoolWithTag(1, 20, 1667526736);
  v10 = v9;
  if ( !v9 )
    return sub_7E4960();
  v9[4] = a3;
  if ( a3 >= 0 )
  {
    v9[2] = a1;
    v9[3] = a2;
LABEL_5:
    v12 = v22;
    *v10 = (int)&v21;
    v10[1] = (int)v12;
    if ( *v12 != (int *)&v21 )
      __fastfail(3u);
    *v12 = v10;
    v22 = (int **)v10;
    v13 = (unsigned int)v10;
    v10 = 0;
    goto LABEL_7;
  }
  v23 = 24;
  v24 = a1;
  v27 = 0;
  v28 = 0;
  v25 = &PiDevCfgEmptyString;
  v26 = 512;
  v8 = ZwOpenKey();
  if ( v8 >= 0 )
  {
    v23 = 24;
    v24 = a2;
    v27 = 0;
    v28 = 0;
    v25 = &PiDevCfgEmptyString;
    v26 = 512;
    v8 = ZwOpenKey();
    if ( v8 >= 0 )
    {
      v10[4] |= 0x40000000u;
      goto LABEL_5;
    }
    ZwClose();
  }
  v13 = (unsigned int)v22;
LABEL_7:
  if ( v10 )
  {
    ExFreePoolWithTag((unsigned int)v10);
    v13 = (unsigned int)v22;
  }
  if ( v8 < 0 )
  {
    v14 = v21;
  }
  else
  {
    while ( 1 )
    {
      v14 = v21;
      if ( v21 == (int *)&v21 )
      {
        v16 = 0;
      }
      else
      {
        v15 = *(_QWORD *)v13;
        if ( *(int ***)v13 != &v21 || *(_DWORD *)HIDWORD(v15) != v13 )
          __fastfail(3u);
        v22 = *(int ***)(v13 + 4);
        *(_DWORD *)HIDWORD(v15) = &v21;
        v7 = *(_DWORD *)(v13 + 8);
        a3 = *(_DWORD *)(v13 + 16);
        v19 = *(_DWORD *)(v13 + 12);
        ExFreePoolWithTag(v13);
        v14 = v21;
        v13 = (unsigned int)v22;
        v16 = 1;
      }
      if ( !v16 )
        break;
      v8 = PiDevCfgCopyDeviceKey(v7, v19, 0, 0, a3, &v21, a4);
      if ( (a3 & 0x40000000) != 0 )
      {
        ZwClose();
        ZwClose();
      }
      v13 = (unsigned int)v22;
      if ( v8 < 0 )
      {
        v14 = v21;
        break;
      }
    }
  }
  while ( 1 )
  {
    if ( v14 == (int *)&v21 )
    {
      v17 = 0;
    }
    else
    {
      v18 = *(_QWORD *)v13;
      if ( *(int ***)v13 != &v21 || *(_DWORD *)HIDWORD(v18) != v13 )
        __fastfail(3u);
      v22 = *(int ***)(v13 + 4);
      *(_DWORD *)HIDWORD(v18) = &v21;
      a3 = *(_DWORD *)(v13 + 16);
      ExFreePoolWithTag(v13);
      v14 = v21;
      v13 = (unsigned int)v22;
      v17 = 1;
    }
    if ( !v17 )
      break;
    if ( (a3 & 0x40000000) != 0 )
    {
      ZwClose();
      ZwClose();
      v14 = v21;
      v13 = (unsigned int)v22;
    }
  }
  return v8;
}
