// MiEmptyPageAccessLog 
 
int __fastcall MiEmptyPageAccessLog(_DWORD *a1)
{
  unsigned int v1; // r10
  unsigned int v2; // r4
  _DWORD *v3; // r8
  unsigned int v4; // lr
  _DWORD *v5; // r9
  int v6; // r5
  unsigned int *v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // r0
  unsigned int v10; // t1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r1
  int v15; // r5
  int v16; // r2
  int v17; // r3
  bool v18; // cf
  unsigned int v19; // r4
  _DWORD *v20; // r0
  __int64 v21; // r0
  int v22; // r3
  unsigned int v23; // r2
  int **v24; // r6
  unsigned int v25; // r7
  unsigned int i; // r10
  int v27; // r5
  int v28; // r0
  int *v29; // r4
  int result; // r0
  unsigned int v31; // [sp+0h] [bp-50h]
  unsigned int v32; // [sp+4h] [bp-4Ch]
  unsigned int v33; // [sp+8h] [bp-48h]
  int v34; // [sp+8h] [bp-48h]
  int v35; // [sp+10h] [bp-40h]
  unsigned int v36; // [sp+14h] [bp-3Ch]
  __int16 v37; // [sp+18h] [bp-38h]
  _DWORD *v38; // [sp+1Ch] [bp-34h]
  unsigned int v39; // [sp+20h] [bp-30h]
  int v40[10]; // [sp+28h] [bp-28h]

  v1 = a1[11];
  v40[0] = 0;
  v2 = 0;
  v40[1] = 3;
  v3 = a1;
  v31 = 0;
  v39 = v1;
  if ( v1 > 1 && v1 != PsInitialSystemProcess )
    MmGetSessionIdEx(v1);
  v4 = 0;
  v32 = 0;
  v33 = 0;
  while ( 1 )
  {
    v5 = (_DWORD *)*v3;
    v6 = 0;
    v7 = (unsigned int *)(v3[8] - 8);
    v8 = (unsigned int)(v3 + 14);
    v9 = 0;
    v38 = (_DWORD *)*v3;
    v35 = 0;
    if ( v7 >= v3 + 14 )
    {
      while ( 1 )
      {
        v10 = *v7;
        v7 -= 2;
        v11 = (v10 >> 9) & 1;
        v12 = v10 & 0x1FF;
        v34 = v12;
        v37 = v11;
        if ( (v10 & 0x1FF) == 0 )
          break;
        if ( v1 > 1 )
        {
          v14 = v7[3];
          v36 = v14;
          if ( v12 == v6 )
          {
            v15 = (v4 >> 10) & 1;
            v16 = __PAIR64__((int)(v14 - v9) >> 31, (int)(v14 - v9) >> 2) << 12 << v40[v15] >> 32;
            v17 = (int)(v14 - v9) >> 2 << 12 << v40[v15];
            v18 = __CFADD__(v4, v17);
            v4 += v17;
            v6 = v35;
            v19 = v16 + v18 + v32;
          }
          else
          {
            v20 = *(_DWORD **)(v3[10] - 4 * v12);
            v31 = v2 ^ ((unsigned __int16)v2 ^ (unsigned __int16)(32 * *(_WORD *)(*v20 + 28))) & 0x400;
            LODWORD(v21) = MiStartingOffset(v20, v14);
            v22 = v40[(v31 >> 10) & 1];
            v19 = (unsigned __int64)(v21 << v22) >> 32;
            v8 = (unsigned int)(v3 + 14);
            v6 = v34;
            v35 = v34;
            v4 = v34 & 0x1FF | ((_DWORD)v21 << v22) & 0xFFFFFA00 | v31 & 0x400;
          }
          v9 = v36;
          v32 = v19;
          v7[2] = v4;
          v7[3] = v19;
          v2 = v31;
          v13 = v4 ^ ((unsigned __int16)v4 ^ (unsigned __int16)(v37 << 9)) & 0x200;
          goto LABEL_13;
        }
LABEL_14:
        if ( (unsigned int)v7 < v8 )
        {
          v5 = v38;
          v33 = v4;
          goto LABEL_16;
        }
      }
      v13 = (v11 & 1 ^ (2 * v7[3])) << 9;
LABEL_13:
      v7[2] = v13;
      goto LABEL_14;
    }
LABEL_16:
    if ( v1 > 1 )
    {
      v23 = v3[10] - 4;
      v24 = (int **)(v3[9] + 4);
      v25 = (unsigned int)v24 > v23 ? 0 : (v23 - v3[9]) >> 2;
      if ( v25 )
      {
        for ( i = 1; i <= v25; ++i )
        {
          v27 = **v24;
          v28 = MI_REFERENCE_CONTROL_AREA_FILE(v27);
          v29 = *(int **)(v28 + 12);
          MI_DEREFERENCE_CONTROL_AREA_FILE(v27, v28);
          *v24++ = v29;
        }
        v1 = v39;
      }
      if ( !ObReferenceObjectSafeWithTag(v1) )
        break;
    }
    result = MiQueuePageAccessLog(v3);
    v3 = v5;
    if ( !v5 )
      return result;
    v4 = v33;
    v2 = v31;
  }
  result = (int)v3;
  while ( 1 )
  {
    ExFreePoolWithTag(result);
    result = (int)v5;
    if ( !v5 )
      break;
    v5 = (_DWORD *)*v5;
  }
  return result;
}
