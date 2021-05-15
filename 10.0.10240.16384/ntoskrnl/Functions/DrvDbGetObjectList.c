// DrvDbGetObjectList 
 
int __fastcall DrvDbGetObjectList(int **a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7, int a8)
{
  int v10; // lr
  int *v11; // r1
  int v12; // r5
  int v13; // r4
  int v15; // r10
  int v16; // r0
  unsigned int v17; // r2
  int **v18; // r8
  int v19; // r0
  int v20; // r2
  int v21; // r2
  unsigned int v22; // r3
  int v24; // [sp+10h] [bp-38h] BYREF
  int v25; // [sp+14h] [bp-34h] BYREF
  int v26; // [sp+18h] [bp-30h]
  int v27; // [sp+1Ch] [bp-2Ch]
  int v28; // [sp+20h] [bp-28h]
  int v29; // [sp+24h] [bp-24h]

  v27 = a4;
  v28 = a3;
  v25 = 0;
  v26 = 0;
  v10 = a2;
  *a7 = 0;
  v29 = a2;
  v11 = a1[6];
  v12 = 0;
  v13 = 0;
  v24 = 0;
  v15 = 0;
  if ( v11 )
  {
    v15 = (int)v11;
    v16 = DrvDbAcquireDatabaseNodeBaseKey(a1, v11, v10, &v24);
    v13 = v16;
    if ( v16 >= 0 )
    {
      v13 = DrvDbGetObjectSubKeyList(*a1, v24, a3, a4, a5, a6, a7, a8);
      goto LABEL_6;
    }
    v12 = v24;
    if ( v16 == -1073740697 )
      v13 = -1073741766;
    goto LABEL_27;
  }
  v18 = (int **)a1[3];
  v17 = a6;
  if ( v18 == a1 + 3 )
    goto LABEL_22;
  while ( 1 )
  {
    v15 = (int)v18;
    v19 = DrvDbAcquireDatabaseNodeBaseKey(a1, v18, v10, &v24);
    v13 = v19;
    if ( v19 == -1073740697 )
    {
      v12 = v24;
      v13 = 0;
      goto LABEL_18;
    }
    if ( v19 < 0 )
      break;
    v13 = DrvDbGetObjectSubKeyList(*a1, v24, v28, v27, a5 + 2 * v26, a6 - v26, &v25, a8);
    DrvDbReleaseDatabaseNodeBaseKey((int)a1, (int)v18, v20, v24);
    v21 = v25;
    v12 = 0;
    v24 = 0;
    if ( v25 )
      v21 = --v25;
    if ( a5 && v26 + v21 < a6 )
      v26 += v21;
    *a7 += v21;
    if ( v13 != -1073741789 && v13 < 0 )
      goto LABEL_21;
LABEL_18:
    v18 = (int **)*v18;
    v10 = v29;
    if ( v18 == a1 + 3 )
      goto LABEL_21;
  }
  v12 = v24;
LABEL_21:
  v17 = a6;
LABEL_22:
  v22 = *a7 + 1;
  *a7 = v22;
  if ( v13 >= 0 )
  {
    if ( a5 && v22 <= v17 )
    {
      *(_WORD *)(a5 + 2 * v22 - 2) = 0;
LABEL_6:
      v12 = v24;
    }
    else
    {
      v13 = -1073741789;
    }
  }
LABEL_27:
  if ( v12 )
    DrvDbReleaseDatabaseNodeBaseKey((int)a1, v15, v17, v12);
  return v13;
}
