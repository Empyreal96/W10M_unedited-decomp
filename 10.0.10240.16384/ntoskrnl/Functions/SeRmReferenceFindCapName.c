// SeRmReferenceFindCapName 
 
int __fastcall SeRmReferenceFindCapName(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r9
  int v5; // r4
  int v7; // r7
  int v8; // r5
  int v9; // r6
  int v10; // r0
  int v11; // r2
  int v12; // r1
  unsigned int v13; // r3
  int v14; // r0
  int v15; // r3
  unsigned int v16; // r10
  int v17; // r9
  unsigned __int16 *v18; // r7
  int v19; // r8
  unsigned int v20; // r3
  unsigned int v21; // t1
  int v22; // r3
  int v24; // [sp+0h] [bp-28h] BYREF
  _DWORD *v25; // [sp+4h] [bp-24h]
  int *v26; // [sp+8h] [bp-20h]
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  _DWORD *varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (_DWORD *)a2;
  v25 = (_DWORD *)a2;
  v26 = a3;
  v5 = 0;
  varg_r0 = a1;
  v24 = 0;
  v7 = 0;
  v8 = 0;
  v9 = SepValidateCAPIDs();
  if ( v9 >= 0 )
  {
    v9 = SepRmReferenceFindCap(a1, &v24);
    v5 = v24;
    if ( v9 >= 0 )
    {
      v10 = *(_DWORD *)(v24 + 32);
      if ( v10 )
      {
        v11 = v24;
        v12 = *(_DWORD *)(v24 + 32);
        do
        {
          v13 = **(unsigned __int16 **)(v11 + 36);
          if ( v13 <= 2 )
            v13 = 0;
          v7 += v13;
          v11 += 4;
          --v12;
        }
        while ( v12 );
      }
      v14 = ExAllocatePoolWithTag(1, v7 + 8 * v10);
      v8 = v14;
      if ( v14 )
      {
        v15 = *(_DWORD *)(v5 + 32);
        v16 = 0;
        v17 = v14 + 8 * v15;
        if ( v15 )
        {
          v18 = (unsigned __int16 *)v14;
          v19 = v5;
          do
          {
            *((_DWORD *)v18 + 1) = v17;
            v20 = **(unsigned __int16 **)(v19 + 36);
            if ( v20 <= 2 )
              v20 = 0;
            v18[1] = v20;
            *v18 = v20;
            memmove(v17, *(_DWORD *)(*(_DWORD *)(v19 + 36) + 4), v20);
            v21 = *v18;
            v18 += 4;
            ++v16;
            v19 += 4;
            v17 += 2 * (v21 >> 1);
          }
          while ( v16 < *(_DWORD *)(v5 + 32) );
        }
        v4 = v25;
      }
      else
      {
        v9 = -1073741801;
      }
    }
  }
  *v26 = v8;
  if ( v5 )
    v22 = *(_DWORD *)(v5 + 32);
  else
    v22 = 0;
  *v4 = v22;
  return v9;
}
