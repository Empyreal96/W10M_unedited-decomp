// BiVerifyBootPartition 
 
int __fastcall BiVerifyBootPartition(int *a1, _DWORD *a2, _DWORD *a3, int a4, unsigned int *a5, int *a6)
{
  int v6; // r4
  unsigned int v7; // r5
  unsigned int v8; // r6
  bool v9; // zf
  _DWORD *v10; // lr
  int v11; // r10
  _DWORD *v13; // r7
  _DWORD *v14; // r9
  int v15; // r4
  int v16; // r4
  int v17; // r3
  unsigned int v18; // r2
  bool v19; // cf
  int *v20; // r4
  unsigned __int16 *v21; // r4
  unsigned int v22; // r0
  unsigned int v23; // r5
  int v24; // r0
  _DWORD *v25; // [sp+8h] [bp-38h] BYREF
  unsigned int v26; // [sp+Ch] [bp-34h] BYREF
  unsigned int v27; // [sp+10h] [bp-30h]
  unsigned int v28; // [sp+14h] [bp-2Ch]
  _DWORD *v29; // [sp+18h] [bp-28h]
  _DWORD *v30; // [sp+1Ch] [bp-24h]
  _DWORD *v31; // [sp+20h] [bp-20h]

  v6 = *a1;
  v7 = 0;
  v8 = 0;
  v9 = *a1 == 2;
  v10 = (_DWORD *)a4;
  v29 = (_DWORD *)a4;
  v30 = a3;
  v31 = a2;
  v25 = 0;
  v11 = 0;
  if ( v9 )
    return sub_8144A8();
  if ( v6 == 6 )
  {
    v13 = a1 + 4;
    v14 = a1 + 8;
    v15 = 32;
  }
  else
  {
    if ( v6 != 8 )
      return -1073741811;
    v17 = a1[6];
    if ( !v17 )
      return -1073741811;
    v15 = v17 + 16;
    v14 = (int *)((char *)a1 + v17 + 16);
    v13 = 0;
  }
  if ( !*v14 )
  {
LABEL_6:
    v16 = 0;
    if ( a2 )
      *a2 = v13;
    if ( a3 )
      *a3 = 0;
    if ( v10 )
      *v10 = v14;
    if ( a6 )
      *a6 = v11;
    if ( a5 )
    {
      *a5 = v8;
      v8 = 0;
    }
    goto LABEL_16;
  }
  if ( *v14 == 6 )
  {
    v18 = a1[2];
    v11 = v15 + 24;
    v19 = v18 >= v15 + 60;
    v20 = (int *)((char *)a1 + v15 + 24);
    if ( v19 && v18 >= v20[2] + v11 && !*v20 && v20[4] == 5 )
    {
      v16 = BiConvertBootEnvironmentDeviceToNt(v20, 0, 0, &v25, &v26);
      v7 = (unsigned int)v25;
      if ( v16 >= 0 )
      {
        if ( v26 >= 0x2E && *v25 == 3 && (v21 = (unsigned __int16 *)((char *)v25 + v25[5]), *(_DWORD *)v21 == 2) )
        {
          v27 = wcslen(v21 + 10);
          v22 = wcslen((unsigned __int16 *)(v7 + 24));
          v23 = v27;
          v28 = 2 * (v22 + 1);
          v24 = ExAllocatePoolWithTag(1, v28 + 2 * v27, 1262764866);
          v8 = v24;
          if ( v24 )
          {
            memmove(v24, (int)(v21 + 10), 2 * v23);
            memmove(v8 + 2 * v23, (int)(v25 + 6), v28);
            v10 = v29;
            a3 = v30;
            v7 = (unsigned int)v25;
            a2 = v31;
            goto LABEL_6;
          }
          v16 = -1073741801;
          v7 = (unsigned int)v25;
        }
        else
        {
          v16 = -1073741811;
        }
      }
LABEL_16:
      if ( v7 )
        ExFreePoolWithTag(v7);
      if ( v8 )
        ExFreePoolWithTag(v8);
      return v16;
    }
  }
  return -1073741811;
}
