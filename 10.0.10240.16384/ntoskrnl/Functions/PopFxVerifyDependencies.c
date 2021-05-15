// PopFxVerifyDependencies 
 
int __fastcall PopFxVerifyDependencies(int *a1, int a2, unsigned int a3)
{
  int v4; // r8
  int v6; // lr
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r6
  int *v10; // r9
  int v11; // t1
  _DWORD *v12; // r4
  unsigned int v13; // r1
  int *v14; // r0
  int *v15; // r8
  int v16; // r1
  unsigned int v17; // r4
  int v18; // t1
  unsigned int v19; // r3
  unsigned int v20; // r3
  int v21; // r3
  int v22; // r1
  unsigned int v23; // r5
  int v24; // r0
  int v25; // t1
  int v26; // r3

  v4 = a2;
  v6 = ExAllocatePoolWithTag(1, 4 * a3, 1297630800);
  if ( !v6 )
    return -1073741670;
  v8 = 0;
  v9 = 0;
  if ( a3 )
  {
    v10 = a1;
    while ( 1 )
    {
      v11 = *v10;
      v10 += 3;
      if ( !v11 )
      {
        *(_DWORD *)(v6 + 4 * v8++) = v9;
        if ( v8 )
          break;
      }
LABEL_24:
      if ( ++v9 >= a3 )
        goto LABEL_25;
    }
    while ( 1 )
    {
      v12 = (_DWORD *)(v6 + 4 * v8);
      v13 = *(v12 - 1);
      if ( v13 >= a3 )
        break;
      v14 = &a1[3 * v13];
      if ( *v14 == 2 )
        break;
      v15 = *(int **)(*(_DWORD *)(*(_DWORD *)(v4 + 392) + 4 * v13) + 124);
      if ( *v14 == 1 )
      {
        *v14 = 2;
        --v8;
        v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 392) + 4 * v13) + 120);
        if ( v16 )
        {
          v17 = v14[1];
          do
          {
            v18 = *v15;
            v15 += 2;
            v19 = a1[3 * v18 + 1];
            if ( v19 > v17 )
            {
              v17 = v19;
              v14[1] = v19;
            }
            --v16;
          }
          while ( v16 );
          v20 = v14[1] + 1;
          v14[1] = v20;
          if ( v20 > 4 )
            break;
        }
      }
      else
      {
        *v14 = 1;
        v21 = *(_DWORD *)(*(_DWORD *)(a2 + 392) + 4 * v13);
        v22 = 0;
        v23 = *(_DWORD *)(v21 + 120);
        if ( v23 )
        {
          do
          {
            v25 = *v15;
            v15 += 2;
            v24 = v25;
            v26 = a1[3 * v25];
            if ( v26 == 1 )
              goto LABEL_16;
            if ( !v26 )
            {
              if ( v8 >= a3 )
                goto LABEL_16;
              *v12 = v24;
              ++v8;
              ++v12;
            }
          }
          while ( ++v22 < v23 );
        }
      }
      v4 = a2;
      if ( !v8 )
        goto LABEL_24;
    }
LABEL_16:
    v7 = -1073741811;
  }
  else
  {
LABEL_25:
    v7 = 0;
  }
  ExFreePoolWithTag(v6);
  return v7;
}
