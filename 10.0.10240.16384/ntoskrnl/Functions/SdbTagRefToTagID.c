// SdbTagRefToTagID 
 
int __fastcall SdbTagRefToTagID(int a1, unsigned int a2, _DWORD *a3, int *a4)
{
  int v4; // r9
  _DWORD *v5; // r1
  _DWORD *v6; // lr
  int v8; // r3
  _DWORD *v9; // r6
  int v10; // r7
  int v12; // r1
  int v13; // r3
  int v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r3
  _DWORD v19[12]; // [sp+10h] [bp-30h] BYREF

  v4 = a2 & 0xFFFFFFF;
  v5 = (_DWORD *)(a1 + 24 * (a2 >> 28));
  v6 = v5 + 5;
  v8 = v5[10];
  v9 = 0;
  v10 = 1;
  if ( (v8 & 2) != 0 )
  {
    v12 = v5[6];
    v13 = v6[2];
    v14 = v6[3];
    v9 = (_DWORD *)v6[4];
    v9[5] = *v6;
    v9[6] = v12;
    v9[7] = v13;
    v9[8] = v14;
    goto LABEL_5;
  }
  if ( (v8 & 1) != 0 )
  {
    v15 = v5[6];
    v16 = v6[2];
    v17 = v6[3];
    v19[0] = *v6;
    v19[1] = v15;
    v19[2] = v16;
    v19[3] = v17;
    v6[5] = 0;
    v9 = 0;
    v10 = SdbpOpenLocalDatabaseEx(a1, v19);
LABEL_5:
    if ( v9 )
      goto LABEL_7;
  }
  v10 = 0;
LABEL_7:
  if ( !v10 )
  {
    v9 = 0;
    v4 = 0;
  }
  if ( a3 )
    *a3 = v9;
  if ( a4 )
    *a4 = v4;
  return v10;
}
