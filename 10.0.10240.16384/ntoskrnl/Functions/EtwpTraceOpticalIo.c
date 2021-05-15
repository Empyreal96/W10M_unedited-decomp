// EtwpTraceOpticalIo 
 
int __fastcall EtwpTraceOpticalIo(int result, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  unsigned __int8 *v7; // r2
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r5
  int v14; // r2
  int v15; // r1
  unsigned __int64 v16; // r2
  int v17; // r1
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r5
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r3
  _DWORD v28[6]; // [sp+8h] [bp-68h] BYREF
  int v29; // [sp+20h] [bp-50h] BYREF
  int v30; // [sp+24h] [bp-4Ch]
  int v31; // [sp+28h] [bp-48h]
  int v32; // [sp+2Ch] [bp-44h]
  int v33; // [sp+30h] [bp-40h]
  int v34; // [sp+34h] [bp-3Ch]
  int v35; // [sp+38h] [bp-38h]
  _DWORD *v36; // [sp+3Ch] [bp-34h]
  int v37; // [sp+40h] [bp-30h]
  int v38; // [sp+44h] [bp-2Ch]
  int v39; // [sp+48h] [bp-28h]
  int *v40; // [sp+50h] [bp-20h] BYREF
  int v41; // [sp+54h] [bp-1Ch]
  int v42; // [sp+58h] [bp-18h]
  int v43; // [sp+5Ch] [bp-14h]
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r0 = result;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = (unsigned __int8 *)a3[24];
  v9 = *v7;
  if ( v9 == 3 )
  {
    v17 = 311;
LABEL_25:
    v21 = a3[2];
    v22 = a3[7];
    v29 = a2;
    v30 = v21;
    v36 = a3;
    v31 = v22;
    v33 = *((_DWORD *)v7 + 4);
    v34 = *((_DWORD *)v7 + 5);
    v37 = a5;
    v38 = a6;
    v32 = 0;
    v23 = a3[20];
    if ( v23 )
      v24 = *(_DWORD *)(v23 + 880);
    else
      v24 = -1;
    v39 = v24;
    if ( (result & 0xFFFF0000) == 1448280064 )
    {
      v25 = 1;
    }
    else
    {
      if ( (result & 0xFFFFFF) != 5467492 && (result & 0xFFFFFF) != 5460546 )
      {
LABEL_34:
        if ( (v21 & 8) != 0 )
        {
          v26 = a3[3];
          if ( !v26 )
            goto LABEL_39;
          v27 = *(_DWORD *)(v26 + 100);
        }
        else
        {
          v27 = a3[25];
        }
        if ( v27 )
        {
          v35 = *(_DWORD *)(v27 + 12);
          goto LABEL_41;
        }
LABEL_39:
        v35 = 0;
LABEL_41:
        v41 = 0;
        v20 = 44;
        goto LABEL_42;
      }
      v25 = 2;
    }
    v32 = v25;
    goto LABEL_34;
  }
  if ( v9 == 4 )
  {
    v17 = 312;
    goto LABEL_25;
  }
  if ( v9 != 9 )
  {
    if ( v9 != 14 )
      return result;
    result = EtwpGetScsiPassThroughCdb((int)a3);
    if ( !result )
      return result;
    v13 = *(unsigned __int8 *)result;
    v14 = *(unsigned __int8 *)(result + 5) | ((*(unsigned __int8 *)(result + 4) | ((*(unsigned __int8 *)(result + 3) | (*(unsigned __int8 *)(result + 2) << 8)) << 8)) << 8);
    v15 = v14 >> 31;
    v16 = (unsigned __int64)(unsigned int)v14 << 11;
    result = HIDWORD(v16) | (v15 << 11);
    if ( v13 == 40 )
      goto LABEL_18;
    if ( v13 != 168 && v13 != 42 && v13 != 170 )
    {
      if ( v13 != 53 )
        return result;
      goto LABEL_4;
    }
    if ( v13 == 168 )
LABEL_18:
      v17 = 311;
    else
      v17 = 312;
    HIDWORD(v16) = a3[2];
    v29 = a2;
    v30 = HIDWORD(v16);
    HIDWORD(v16) = a3[7];
    v36 = a3;
    v33 = v16;
    v34 = result;
    v31 = HIDWORD(v16);
    v37 = a5;
    v38 = a6;
    v32 = 0;
    v35 = 0;
    v18 = a3[20];
    if ( v18 )
      v19 = *(_DWORD *)(v18 + 880);
    else
      v19 = -1;
    v39 = v19;
    v41 = 0;
    v20 = 24;
LABEL_42:
    v40 = &v29;
    v42 = v20;
    v43 = 0;
    return (int)EtwTraceKernelEvent((int *)&v40, 1, 0x80000001, v17, 4200451);
  }
LABEL_4:
  v10 = a3[2];
  v28[0] = a2;
  v28[1] = v10;
  v28[4] = a3;
  v28[2] = a5;
  v28[3] = a6;
  v11 = a3[20];
  if ( v11 )
    v12 = *(_DWORD *)(v11 + 880);
  else
    v12 = -1;
  v28[5] = v12;
  v40 = v28;
  v41 = 0;
  v42 = 24;
  v43 = 0;
  return (int)EtwTraceKernelEvent((int *)&v40, 1, 0x80000001, 313, 4200451);
}
