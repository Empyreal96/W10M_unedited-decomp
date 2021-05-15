// WmipQueryAllDataMultiple 
 
int __fastcall WmipQueryAllDataMultiple(int a1, unsigned int a2, int a3, char a4, int a5, int a6, _DWORD *a7, _DWORD *a8)
{
  _DWORD *v8; // r8
  _DWORD *v9; // r4
  int *v10; // r2
  int v12; // r0
  unsigned int v13; // r6
  _DWORD *v14; // r2
  int v15; // r1
  int v16; // t1
  int v17; // r5
  char *v18; // r0
  int v19; // r10
  char *v20; // r9
  char *v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r8
  int v24; // r6
  unsigned int v25; // r10
  int v27; // r3
  int v28; // r3
  unsigned int v29; // r3
  _DWORD *v30; // r3
  int v31; // [sp+8h] [bp-A0h]
  int *v32; // [sp+Ch] [bp-9Ch] BYREF
  int v33; // [sp+10h] [bp-98h]
  int v34; // [sp+14h] [bp-94h]
  int *v35; // [sp+18h] [bp-90h]
  int v36; // [sp+1Ch] [bp-8Ch]
  int v37; // [sp+20h] [bp-88h]
  int v38; // [sp+24h] [bp-84h]
  _DWORD *v39; // [sp+28h] [bp-80h]
  int v40; // [sp+2Ch] [bp-7Ch]
  int v41; // [sp+30h] [bp-78h]
  _DWORD *v42; // [sp+34h] [bp-74h]
  unsigned int v43; // [sp+38h] [bp-70h]
  char v44[104]; // [sp+40h] [bp-68h] BYREF

  v40 = a4;
  v41 = a3;
  v8 = (_DWORD *)a5;
  v9 = a7;
  v39 = a8;
  v10 = (int *)a2;
  v36 = 0;
  v37 = 0;
  v32 = (int *)a2;
  v42 = (_DWORD *)a5;
  if ( a2 )
  {
    v13 = 0;
    v38 = 0;
  }
  else
  {
    a1 = *a7;
    v12 = ExAllocatePoolWithTag(1, 4 * *a7, 1885957463);
    v13 = v12;
    v38 = v12;
    if ( !v12 )
      return -1073741670;
    if ( a1 )
    {
      v14 = (_DWORD *)v12;
      v15 = a1;
      do
      {
        v16 = v9[2];
        v9 += 2;
        --v15;
        *v14++ = v16;
      }
      while ( v15 );
    }
    v10 = v32;
  }
  v17 = 0;
  v18 = (char *)a5;
  v31 = a5;
  v19 = 0;
  v34 = 0;
  v20 = 0;
  v21 = (char *)a5;
  if ( !a1 )
    goto LABEL_35;
  v22 = a6;
  v23 = (unsigned int)v32;
  v33 = a6;
  v35 = v10;
  v43 = v13 - (_DWORD)v10;
  v24 = 0;
  do
  {
    if ( v21 == v44 || v22 < 0x48 )
    {
      v21 = v44;
      v25 = 72;
      v20 = 0;
    }
    else
    {
      v21 = v18;
      v25 = v22;
    }
    memset(v21, 0, 72);
    *((_DWORD *)v21 + 11) = 1;
    *(_DWORD *)v21 = 48;
    if ( v23 )
      v37 = *v35;
    else
      *((_DWORD *)v21 + 4) = *(int *)((char *)v35 + v43);
    if ( WmipQueryAllData(v37, v41, v40, v21, v25, (unsigned int *)&v32) < 0
      || (v27 = *((_DWORD *)v21 + 11), (v27 & 0x100) != 0) )
    {
      v19 = v34;
      goto LABEL_32;
    }
    ++v36;
    if ( (v27 & 0x20) != 0 )
    {
      v17 += (*((_DWORD *)v21 + 12) + 7) & 0xFFFFFFF8;
      v21 = v44;
LABEL_22:
      v19 = 1;
      v34 = 1;
LABEL_32:
      v18 = (char *)v31;
      v22 = v33;
      goto LABEL_33;
    }
    if ( v21 == v44 )
    {
      v17 += ((unsigned int)v32 + 7) & 0xFFFFFFF8;
      goto LABEL_22;
    }
    if ( v20 )
      *((_DWORD *)v20 + 3) = v24;
    v28 = *((_DWORD *)v21 + 3);
    v20 = v21;
    while ( v28 )
    {
      v20 += v28;
      v28 = *((_DWORD *)v20 + 3);
    }
    v19 = v34;
    v29 = ((unsigned int)v32 + 7) & 0xFFFFFFF8;
    v17 += v29;
    v22 = v33 - v29;
    v18 = (char *)(v31 + v29);
    v31 = (int)v18;
    v24 = v18 - v20;
    v33 -= v29;
LABEL_33:
    ++v35;
    --a1;
  }
  while ( a1 );
  v13 = v38;
  v8 = v42;
LABEL_35:
  if ( v13 )
    ExFreePoolWithTag(v13);
  if ( !v36 )
    return -1073741163;
  if ( v19 )
  {
    v8[11] = 32;
    v8[12] = v17;
    v30 = v39;
    *v8 = 56;
    *v30 = 56;
  }
  else
  {
    *v39 = v17;
  }
  return 0;
}
