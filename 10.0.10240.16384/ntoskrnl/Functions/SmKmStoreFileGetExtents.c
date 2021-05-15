// SmKmStoreFileGetExtents 
 
int __fastcall SmKmStoreFileGetExtents(int a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6, int a7, _DWORD *a8, int *a9, unsigned int *a10)
{
  int *v10; // r7
  int v11; // r6
  int v13; // r9
  int v14; // r10
  int *v15; // r4
  int v16; // r5
  int v17; // r2
  int v18; // r8
  int v19; // r1
  unsigned int v20; // r10
  int v21; // lr
  __int64 v22; // kr08_8
  __int64 v23; // kr10_8
  unsigned __int64 v24; // kr18_8
  unsigned int v25; // r1
  int v26; // r5
  __int64 v27; // kr28_8
  unsigned __int64 v28; // kr20_8
  int v29; // r5
  int v30; // r0
  int v31; // r2
  int *v32; // r3
  __int64 v33; // t1
  int *v35; // [sp+18h] [bp-88h]
  int v36; // [sp+1Ch] [bp-84h]
  int v37; // [sp+20h] [bp-80h] BYREF
  unsigned int v38; // [sp+24h] [bp-7Ch]
  int v39; // [sp+28h] [bp-78h]
  int v40; // [sp+2Ch] [bp-74h]
  int v41; // [sp+30h] [bp-70h]
  unsigned int v42; // [sp+34h] [bp-6Ch]
  _DWORD *v43; // [sp+38h] [bp-68h]
  int *v44; // [sp+3Ch] [bp-64h]
  int *v45; // [sp+40h] [bp-60h]
  int v46; // [sp+44h] [bp-5Ch]
  unsigned int *v47; // [sp+48h] [bp-58h]
  unsigned int v48; // [sp+4Ch] [bp-54h] BYREF
  int v49; // [sp+50h] [bp-50h]
  int v50; // [sp+54h] [bp-4Ch]
  int v51; // [sp+58h] [bp-48h]
  int v52[16]; // [sp+60h] [bp-40h] BYREF

  v38 = a4;
  v10 = (int *)a3;
  v11 = 0;
  v43 = a8;
  v44 = (int *)a3;
  v45 = a9;
  v13 = 0x10000;
  v47 = a10;
  v35 = 0;
  v37 = 0;
  v14 = IoSetThreadHardErrorMode(0);
  v36 = v14;
  if ( a7 )
  {
    memset(v52, 0, 32);
    v15 = v52;
    v35 = v52;
    v52[0] = *v10;
    v52[1] = v10[1];
  }
  else
  {
    v16 = ZwFsControlFile();
    if ( v16 == 259 )
    {
      KeWaitForSingleObject(a2 + 92, 0, 0, 0, 0);
      v16 = v51;
    }
    v15 = 0;
    if ( v16 < 0 )
      goto LABEL_32;
  }
  v17 = *v15;
  v48 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  if ( v15[1] | v17 )
  {
    v40 = 0;
    while ( 1 )
    {
      v22 = *(_QWORD *)v15;
      v23 = *((_QWORD *)v15 + 1);
      v24 = __PAIR64__(v21, v19) + *(_QWORD *)v15;
      v21 = HIDWORD(v24);
      v39 = HIDWORD(v24);
      v41 = v24;
      if ( v23 < 0 )
        break;
      if ( v13 )
      {
        if ( v22 >= (unsigned int)v13 )
        {
          v50 = 0;
          v10 = v44;
          v25 = v13;
        }
        else
        {
          v50 = HIDWORD(v22);
          v25 = v22;
        }
        *((_QWORD *)v15 + 1) = v23 + v25;
        *(_QWORD *)v15 = v22 - v25;
        v13 -= v25;
      }
      v26 = *v15;
      v42 = v15[1];
      if ( __SPAIR64__(v42, v26) >= v38 )
      {
        v27 = *((_QWORD *)v15 + 1);
        v28 = a5 - (unsigned __int64)((a5 - 1) & (a5 + (_DWORD)v27 - 1)) + v27 - 1;
        v49 = HIDWORD(v28);
        v46 = v28;
        if ( !v38 )
          __brkdiv0();
        v29 = _rt_udiv64(v38, 1 - (a5 - (unsigned __int64)((a5 - 1) & (a5 + (_DWORD)v27 - 1))) + __PAIR64__(v42, v26));
        if ( v29 )
        {
          v30 = SmArrayGrow(v20, 0x10u, &v48, &v37);
          v11 = v37;
          if ( !v30 )
          {
            v16 = -1073741670;
            goto LABEL_26;
          }
          v31 = v40;
          v18 += v29;
          v32 = (int *)(v40 + v37);
          v32[2] = v46;
          ++v20;
          v32[3] = v49;
          *v32 = v29;
          v40 = v31 + 16;
        }
        v21 = v39;
      }
      v33 = *((_QWORD *)v15 + 2);
      v15 += 4;
      v19 = v41;
      if ( !v33 )
      {
        v15 = v35;
        goto LABEL_23;
      }
    }
    v16 = -1073741453;
LABEL_26:
    v15 = v35;
  }
  else
  {
LABEL_23:
    if ( __SPAIR64__(v21, v19) >= *(_QWORD *)v10 )
    {
      if ( v18 )
      {
        *v43 = v18;
        *v45 = v11;
        v11 = 0;
        v16 = 0;
        *v47 = v20;
      }
      else
      {
        v16 = -1073741672;
      }
    }
    else
    {
      v16 = -1073741453;
    }
  }
  v14 = v36;
LABEL_32:
  if ( v15 && v15 != v52 )
    ExFreePoolWithTag((unsigned int)v15);
  if ( v11 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v11);
  IoSetThreadHardErrorMode(v14);
  return v16;
}
