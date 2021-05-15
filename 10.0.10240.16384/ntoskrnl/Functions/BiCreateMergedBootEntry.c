// BiCreateMergedBootEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BiCreateMergedBootEntry(_DWORD *a1, unsigned __int16 *a2, _DWORD *a3, unsigned __int16 *a4, _DWORD *a5)
{
  unsigned __int16 *v7; // r8
  int v8; // r5
  unsigned __int16 *v9; // r7
  unsigned int v10; // r9
  unsigned __int16 *v12; // r3
  unsigned __int16 *v13; // r10
  unsigned __int16 *v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r4 OVERLAPPED
  int v17; // r0
  int v18; // r3
  unsigned __int16 *v19; // r4
  int v20; // r4
  unsigned int v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r4
  unsigned int v24; // r2
  int v25; // r0
  _BYTE *v26; // r0
  _DWORD *v27; // r10
  int v28; // r1
  unsigned int v29; // r2
  int v30; // r3
  unsigned int v31; // [sp+0h] [bp-38h] BYREF
  unsigned __int16 *v32; // [sp+4h] [bp-34h]
  unsigned __int16 *v33; // [sp+8h] [bp-30h] BYREF
  unsigned __int16 *v34; // [sp+Ch] [bp-2Ch] BYREF
  int v35; // [sp+10h] [bp-28h]
  int v36; // [sp+14h] [bp-24h]
  char v37[32]; // [sp+18h] [bp-20h] BYREF

  v7 = 0;
  v8 = 0;
  v9 = 0;
  v35 = 0;
  v36 = 0;
  v10 = 0;
  v31 = 0;
  v32 = a2;
  v33 = 0;
  v34 = 0;
  if ( a3 )
  {
    if ( *a3 != 2 )
      return sub_813498();
    v12 = (unsigned __int16 *)(a3 + 5);
  }
  else
  {
    v30 = a1[5];
    if ( !a4 )
    {
      v8 = (int)a1 + v30;
LABEL_12:
      if ( !a2 )
      {
        a2 = (unsigned __int16 *)((char *)a1 + a1[4]);
        v32 = a2;
      }
      v21 = wcslen(a2);
      v22 = a1[6];
      v23 = v21 + 1;
      v24 = v22 + 2 * (v21 + 1);
      if ( v24 >= v22 )
      {
        v25 = *(_DWORD *)(v8 + 4);
        if ( v25 + v24 + 36 >= v24 )
        {
          v31 = (v22 + 31) & 0xFFFFFFFC;
          v33 = (unsigned __int16 *)((v31 + 2 * v23 + 3) & 0xFFFFFFFC);
          v34 = (unsigned __int16 *)((char *)v33 + v25);
          v26 = (_BYTE *)ExAllocatePoolWithTag(1, (int)v33 + v25, 1262764866);
          v27 = v26;
          if ( v26 )
          {
            memset(v26, 0, (int)v34);
            *v27 = 1;
            v29 = v31;
            v28 = (int)v32;
            v27[1] = v34;
            v27[2] = a1[2];
            v27[3] = a1[3];
            v27[4] = v29;
            v27[5] = v33;
            v27[6] = a1[6];
            memmove((int)v27 + v29, v28, 2 * v23);
            memmove((int)v27 + (_DWORD)v33, v8, *(_DWORD *)(v8 + 4));
            memmove((int)(v27 + 7), (int)(a1 + 7), a1[6]);
            v20 = 0;
            *a5 = v27;
            goto LABEL_18;
          }
LABEL_27:
          v20 = -1073741670;
          goto LABEL_18;
        }
      }
LABEL_28:
      v20 = -1073741675;
      goto LABEL_18;
    }
    v8 = (int)a1 + v30;
    v31 = (unsigned int)a1 + v30;
    v20 = BiGetDeviceFromEfiPath((char *)a1 + v30 + 12, &v34, v37);
    v7 = v34;
    if ( v20 < 0 )
      goto LABEL_18;
    v12 = v34 + 10;
  }
  v34 = v12;
  if ( a4 )
  {
    v9 = a4;
  }
  else
  {
    v31 = (unsigned int)a1 + a1[5];
    v8 = v31;
    v20 = BiGetFilePathFromEfiPath(v31 + 12, &v33, v37);
    v9 = v33;
    if ( v20 < 0 )
      goto LABEL_18;
    v36 = 1;
  }
  v13 = v34;
  v14 = (unsigned __int16 *)(wcslen(v34) + 1);
  v34 = v14;
  v33 = (unsigned __int16 *)(2 * (wcslen(v9) + 1));
  v15 = (unsigned int)&v33[(_DWORD)v14];
  if ( v15 < 2 * (int)v14 )
    goto LABEL_28;
  v16 = v15 + 12;
  if ( v15 + 12 < v15 )
    goto LABEL_28;
  v17 = ExAllocatePoolWithTag(1, v15 + 12, 1262764866);
  v10 = v17;
  if ( !v17 )
    goto LABEL_27;
  v18 = 1;
  *(_QWORD *)v17 = *(_QWORD *)(&v16 - 1);
  v19 = v34;
  *(_DWORD *)(v17 + 8) = 3;
  memmove(v17 + 12, (int)v13, 2 * (_DWORD)v19);
  memmove(v10 + 2 * (_DWORD)v19 + 12, (int)v9, (unsigned int)v33);
  v20 = BiTranslateFilePath(v10, 4, &v31);
  v8 = v31;
  if ( v20 >= 0 )
  {
    a2 = v32;
    v35 = 1;
    goto LABEL_12;
  }
LABEL_18:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  if ( v35 )
    ExFreePoolWithTag(v8);
  if ( v36 )
    ExFreePoolWithTag((unsigned int)v9);
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v20;
}
