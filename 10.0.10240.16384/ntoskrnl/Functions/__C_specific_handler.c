// __C_specific_handler 
 
int __fastcall _C_specific_handler(int *a1, int a2, int a3, int a4)
{
  unsigned int *v5; // r5
  int v6; // r10
  unsigned int v8; // r8
  unsigned int v9; // r6
  unsigned int *v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v14; // r0
  unsigned int v15; // r9
  unsigned int *v16; // r4
  unsigned int v17; // lr
  unsigned int *v18; // r1
  unsigned int v19; // r3
  unsigned int v20; // [sp+8h] [bp-30h]
  int *v21; // [sp+Ch] [bp-2Ch]
  _DWORD v22[10]; // [sp+10h] [bp-28h] BYREF

  v5 = *(unsigned int **)(a4 + 28);
  v6 = *(_DWORD *)(a4 + 4);
  v20 = a2;
  v21 = a1;
  v8 = *(_DWORD *)a4 - v6;
  if ( (*v5 & 0x80000000) != 0 )
    v5 = (unsigned int *)((*v5 & 0x7FFFFFFF) + v6);
  if ( *(_BYTE *)(a4 + 40) )
    v8 -= 2;
  v9 = *(_DWORD *)(a4 + 36);
  if ( (a1[1] & 0x66) != 0 )
  {
    v14 = *v5;
    v15 = *(_DWORD *)(a4 + 16) - v6;
    if ( v9 < *v5 )
    {
      v16 = &v5[4 * v9];
      do
      {
        if ( v8 >= v16[1] && v8 < v16[2] )
        {
          if ( (v21[1] & 0x20) != 0 )
          {
            v17 = 0;
            if ( v14 )
            {
              v18 = v5;
              do
              {
                if ( v15 >= v18[1] && v15 < v18[2] && v18[4] == v16[4] && v18[3] == v16[3] )
                  break;
                ++v17;
                v18 += 4;
              }
              while ( v17 < v14 );
              a2 = v20;
            }
            if ( v17 != v14 )
              return 1;
          }
          v19 = v16[4];
          if ( v19 )
          {
            if ( v15 == v19 )
              return 1;
          }
          else
          {
            *(_DWORD *)(a4 + 36) = v9 + 1;
            _C_ExecuteTerminationHandler(1, a2, (int (*)(void))(v16[3] + v6));
          }
        }
        v14 = *v5;
        ++v9;
        a2 = v20;
        v16 += 4;
      }
      while ( v9 < *v5 );
    }
  }
  else
  {
    v22[0] = a1;
    v22[1] = a3;
    if ( v9 < *v5 )
    {
      v10 = &v5[4 * v9];
      do
      {
        if ( v8 >= v10[1] && v8 < v10[2] && v10[4] )
        {
          v11 = v10[3];
          if ( v11 == 1 )
            goto LABEL_14;
          v12 = _C_ExecuteExceptionFilter((int)v22, a2, (int (*)(void))(v11 + v6));
          if ( v12 < 0 )
            return 0;
          a2 = v20;
          if ( v12 > 0 )
          {
LABEL_14:
            NLG_Notify();
            RtlUnwindEx(v20, v10[4] + v6, (int)a1, *a1, *(_DWORD *)(a4 + 20), *(_DWORD *)(a4 + 32));
            _NLG_Return2();
            a2 = v20;
          }
        }
        ++v9;
        v10 += 4;
      }
      while ( v9 < *v5 );
    }
  }
  return 1;
}
