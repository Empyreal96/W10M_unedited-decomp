// sub_520A24 
 
void __fastcall sub_520A24(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v5; // r9
  int v6; // lr
  int v7; // r2
  int v8; // r1
  _DWORD *v9; // r8
  _DWORD *v10; // r3
  _DWORD *v11; // r7
  int v12; // r5
  unsigned int v13; // r2
  int v14; // r10
  int v15; // r2
  int v16; // r1
  unsigned int v17; // r8
  int *v18; // r3
  int *v19; // r7
  int v20; // r5
  unsigned int v21; // r2
  int v22; // r10
  int v23; // r3
  _DWORD *v24; // [sp+0h] [bp+0h]
  int *v25; // [sp+0h] [bp+0h]

  if ( a4 == 4 )
  {
    v15 = *(_DWORD *)(a1 + 36);
    v16 = v5 + 7;
    if ( ((v5 + 7) & 0xFFFFFFF8) + 16 * v15 <= v4 )
    {
      v17 = v16 & 0xFFFFFFF8;
      v18 = (int *)(a1 + 44);
      *(_DWORD *)(v6 + 20) = v16 & 0xFFFFFFF8;
      v19 = *(int **)(a1 + 44);
      v20 = (v16 & 0xFFFFFFF8) + 16 * v15;
      v25 = (int *)(a1 + 44);
      while ( v19 != v18 )
      {
        v21 = *((unsigned __int16 *)v19 + 16);
        v22 = v21 + v20;
        if ( v21 + v20 > v4 )
          goto LABEL_19;
        *(_DWORD *)v17 = v19[6];
        v23 = v19[7];
        *(_WORD *)(v17 + 8) = v21;
        *(_WORD *)(v17 + 10) = v21;
        *(_DWORD *)(v17 + 4) = v23;
        *(_DWORD *)(v17 + 12) = v20;
        memmove(v20, v19[9], v21);
        v19 = (int *)*v19;
        v18 = v25;
        v20 = v22;
        v17 += 16;
      }
LABEL_20:
      JUMPOUT(0x453208);
    }
  }
  else
  {
    if ( a4 != 5 )
    {
      if ( a4 == 6 )
        JUMPOUT(0x4531D0);
      if ( a4 != 16 )
        JUMPOUT(0x453278);
    }
    v7 = *(_DWORD *)(a1 + 36);
    v8 = v5 + 3;
    if ( ((v5 + 3) & 0xFFFFFFFC) + 8 * v7 <= v4 )
    {
      v9 = (_DWORD *)(v8 & 0xFFFFFFFC);
      v10 = (_DWORD *)(a1 + 44);
      *(_DWORD *)(v6 + 20) = v8 & 0xFFFFFFFC;
      v11 = *(_DWORD **)(a1 + 44);
      v12 = (v8 & 0xFFFFFFFC) + 8 * v7;
      v24 = (_DWORD *)(a1 + 44);
      while ( v11 != v10 )
      {
        v13 = v11[7];
        v14 = v13 + v12;
        if ( v13 + v12 > v4 )
          goto LABEL_19;
        *v9 = v12;
        v9[1] = v13;
        memmove(v12, v11[6], v13);
        v11 = (_DWORD *)*v11;
        v10 = v24;
        v12 = v14;
        v9 += 2;
      }
      goto LABEL_20;
    }
  }
LABEL_19:
  JUMPOUT(0x453270);
}
