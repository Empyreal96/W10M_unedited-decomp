// sub_813024 
 
void __fastcall sub_813024(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r4
  int v9; // r6
  unsigned int v10; // r3
  int v11; // r4
  int v12; // r7
  unsigned int v13; // r7
  int *v14; // r4
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r1
  int v18; // r3
  int v19; // r0
  _BYTE *v20; // r0
  _BYTE *v21; // r5
  unsigned int v22; // r4
  unsigned int v23; // r0
  _BYTE *v24; // r0
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r0
  int v28; // r4
  int v29; // r6
  _BYTE *v30; // r0
  _DWORD *v31; // r5
  int v32; // r3
  int v33; // r0
  int v34; // r0
  _BYTE *v35; // r0
  _BYTE *v36; // r0
  _DWORD *v37; // r5

  if ( a1 == 1 )
  {
    if ( a2 < 0x14 )
      goto LABEL_49;
    v36 = (_BYTE *)ExAllocatePoolWithTag(1, 72, 1262764866);
    v37 = v36;
    if ( v36 )
    {
      memset(v36, 0, 72);
      *v37 = 5;
      v37[2] = 72;
    }
    goto LABEL_51;
  }
  if ( a1 == 3 )
  {
    if ( a2 < 0x2E )
      goto LABEL_49;
    v34 = *(_DWORD *)(v9 + 20);
    if ( !v34 )
      goto LABEL_49;
    a8 = 0;
    if ( BiConvertNtFilePathToBootEnvironment(v34 + v9, a2 - v34, v9 + 24, v8) < 0 )
      goto LABEL_51;
    v28 = a8;
    v29 = *(_DWORD *)(a8 + 4) + 20;
    v35 = (_BYTE *)ExAllocatePoolWithTag(1, v29, 1262764866);
    v31 = v35;
    if ( v35 )
    {
      memset(v35, 0, v29);
      *v31 = 0;
      v32 = 5;
      v33 = (int)(v31 + 5);
      goto LABEL_39;
    }
  }
  else
  {
    if ( a1 != 4 )
    {
      if ( a1 != 5 )
      {
        if ( a1 == 8 )
        {
          v10 = *(_DWORD *)(v9 + 24);
          if ( a2 >= 0x22 && a2 > v10 )
          {
            v11 = 30;
            v12 = 0;
            if ( !v10 )
            {
LABEL_19:
              if ( *(_DWORD *)(v9 + 20) == 1 )
                v11 += 2 * wcslen((unsigned __int16 *)(v9 + 32));
              v20 = (_BYTE *)ExAllocatePoolWithTag(1, v11, 1262764866);
              v21 = v20;
              if ( v20 )
              {
                memset(v20, 0, v11);
                *(_DWORD *)v21 = 8;
                *((_DWORD *)v21 + 2) = v11;
                if ( *(_DWORD *)(v9 + 20) )
                {
                  *((_DWORD *)v21 + 4) = 1;
                  v23 = wcslen((unsigned __int16 *)(v9 + 32));
                  wcscpy_s(v21 + 28, v23 + 1, (char *)(v9 + 32));
                  v22 = 2 * (wcslen((unsigned __int16 *)(v9 + 32)) + 15);
                }
                else
                {
                  *((_DWORD *)v21 + 4) = 0;
                  v22 = 30;
                  *((_DWORD *)v21 + 5) = *(_DWORD *)(v9 + 28);
                }
                if ( a7 )
                {
                  *(_DWORD *)&v21[v22] = 0;
                  v24 = &v21[v22];
                  *((_DWORD *)v24 + 2) = *(_DWORD *)(a7 + 8) + v12;
                  *((_DWORD *)v24 + 4) = 6;
                  memmove((int)&v21[v22 + v12], a7, *(_DWORD *)(a7 + 8));
                  *((_DWORD *)v21 + 6) = v22;
                }
                JUMPOUT(0x7A479E);
              }
              goto LABEL_51;
            }
            v13 = a2 - v10;
            v14 = (int *)(v10 + v9);
            if ( *(_DWORD *)(v10 + v9) == 3 && v13 >= 0x2E )
            {
              v15 = v14[5];
              v16 = v13 - v15;
              v17 = (int)v14 + v15;
              v18 = *(int *)((char *)v14 + v15);
              if ( v18 == 2 )
              {
                if ( v16 >= 0x16 )
                {
                  v19 = BiGetPartitionVhdFilePath((unsigned __int16 *)(v17 + 20), v17, v16, 2);
                  if ( v19 )
                  {
                    ExFreePoolWithTag(v19);
                    goto LABEL_51;
                  }
                  goto LABEL_17;
                }
              }
              else if ( v18 == 8 && v16 >= 0x22 )
              {
LABEL_17:
                if ( BiConvertNtDeviceToBootEnvironment(v14, v13, 0, &a7) < 0 )
                  goto LABEL_51;
                v12 = 40;
                v11 = *(_DWORD *)(a7 + 8) + 70;
                goto LABEL_19;
              }
            }
          }
        }
LABEL_49:
        JUMPOUT(0x7A47B2);
      }
      if ( a2 < 0x15 )
        goto LABEL_49;
      if ( a2 < 0x20 )
        goto LABEL_49;
      v25 = *(_DWORD *)(v9 + 28);
      if ( v25 > 0x100000 )
        goto LABEL_49;
      v26 = ExAllocatePoolWithTag(1, v25, 1262764866);
      if ( v26 )
        memmove(v26, v9 + 20, *(_DWORD *)(v9 + 28));
LABEL_51:
      JUMPOUT(0x7A47A0);
    }
    if ( a2 < 0x2E )
      goto LABEL_49;
    v27 = *(_DWORD *)(v9 + 20);
    if ( !v27 )
      goto LABEL_49;
    a8 = 0;
    if ( BiConvertNtFilePathToBootEnvironment(v27 + v9, a2 - v27, v9 + 24, 0) < 0 )
      goto LABEL_51;
    v28 = a8;
    v29 = *(_DWORD *)(a8 + 4) + 40;
    v30 = (_BYTE *)ExAllocatePoolWithTag(1, v29, 1262764866);
    v31 = v30;
    if ( v30 )
    {
      memset(v30, 0, v29);
      *v31 = 0;
      v31[1] = 1;
      v32 = 3;
      v33 = (int)(v31 + 10);
LABEL_39:
      v31[2] = v29;
      v31[4] = v32;
      memmove(v33, v28, *(_DWORD *)(v28 + 4));
      ExFreePoolWithTag(v28);
      goto LABEL_51;
    }
  }
  ExFreePoolWithTag(v28);
  goto LABEL_51;
}
