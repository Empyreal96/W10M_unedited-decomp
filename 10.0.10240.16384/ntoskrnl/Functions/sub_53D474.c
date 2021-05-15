// sub_53D474 
 
void sub_53D474()
{
  int v0; // r7
  _DWORD *v1; // r10
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3

  v2 = *(int **)(v0 + 68);
  v3 = *v2;
  v4 = v2[1];
  v5 = v2[2];
  v6 = v2[3];
  v2 += 4;
  *v1 = v3;
  v1[1] = v4;
  v1[2] = v5;
  v1[3] = v6;
  v7 = *v2;
  v8 = v2[1];
  v9 = v2[2];
  v10 = v2[3];
  v2 += 4;
  v1[4] = v7;
  v1[5] = v8;
  v1[6] = v9;
  v1[7] = v10;
  v11 = *v2;
  v12 = v2[1];
  v13 = v2[2];
  v14 = v2[3];
  v2 += 4;
  v1[8] = v11;
  v1[9] = v12;
  v1[10] = v13;
  v1[11] = v14;
  v15 = v2[1];
  v16 = v2[2];
  v17 = v2[3];
  v1[12] = *v2;
  v1[13] = v15;
  v1[14] = v16;
  v1[15] = v17;
  memset(*(_BYTE **)(v0 + 68), 0, 64);
  JUMPOUT(0x4A2C1C);
}
