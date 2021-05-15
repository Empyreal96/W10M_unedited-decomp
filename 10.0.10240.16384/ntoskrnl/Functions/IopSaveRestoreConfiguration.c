// IopSaveRestoreConfiguration 
 
int *__fastcall IopSaveRestoreConfiguration(int *result, int a2, _DWORD *a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r8
  int v6; // r9
  int *v7; // r7
  int v9; // r5
  unsigned int v10; // r10
  int v11; // r2
  unsigned int v12; // r6
  int v13; // r2
  int v14; // t1
  int v15; // r4
  _DWORD *v16; // r5
  _DWORD *v17; // r4
  int v18; // r1
  int v19; // r2
  int v20; // r3
  _DWORD *i; // r2
  int *v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h]
  _DWORD *v24; // [sp+8h] [bp-20h]

  v4 = a4;
  v23 = a4;
  v24 = a3;
  v5 = a3;
  v6 = a2;
  v7 = result;
  if ( a2 )
  {
    do
    {
      v9 = v7[6];
      if ( a4 )
        *(_DWORD *)(v9 + 16) = *(_DWORD *)(v9 + 12);
      else
        *(_DWORD *)(v9 + 12) = *(_DWORD *)(v9 + 16);
      v10 = 0;
      v11 = **(_DWORD **)(v9 + 16);
      result = (int *)(v11 + 20);
      if ( v11 + 20 > (unsigned int)(v11 + 4 * (*(_DWORD *)(v11 + 16) + 5)) )
        v12 = 0;
      else
        v12 = (unsigned int)(4 * (*(_DWORD *)(v11 + 16) + 5) - 17) >> 2;
      if ( v12 )
      {
        do
        {
          v14 = *result++;
          v13 = v14;
          v22 = result;
          if ( *(_BYTE *)(v14 + 8) )
          {
            v15 = *(_DWORD *)(v13 + 20);
            if ( a4 )
            {
              memmove(v15 + 96, v15 + 24, 0x38u);
              v16 = (_DWORD *)(v15 + 152);
              v17 = (_DWORD *)(v15 + 80);
            }
            else
            {
              memmove(v15 + 24, v15 + 96, 0x38u);
              v16 = (_DWORD *)(v15 + 80);
              v17 = (_DWORD *)(v15 + 152);
            }
            v18 = v17[1];
            v19 = v17[2];
            v20 = v17[3];
            *v16 = *v17;
            v16[1] = v18;
            v16[2] = v19;
            v16[3] = v20;
            result = v22;
          }
          ++v10;
        }
        while ( v10 < v12 );
      }
      v7 += 10;
      --v6;
    }
    while ( v6 );
    v4 = v23;
    v5 = v24;
  }
  for ( i = (_DWORD *)*v5; i != v5; i = (_DWORD *)*i )
  {
    if ( v4 )
    {
      *(i - 4) = *(i - 6);
      *(i - 3) = *(i - 5);
      *(i - 2) = *i;
      *(i - 1) = i[1];
    }
    else
    {
      *(i - 6) = *(i - 4);
      *(i - 5) = *(i - 3);
      *i = *(i - 2);
      i[1] = *(i - 1);
    }
  }
  return result;
}
