// IoForwardIrpSynchronously 
 
int __fastcall IoForwardIrpSynchronously(int a1, int a2)
{
  int *v4; // r5
  int *v5; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  if ( *(_BYTE *)(a2 + 35) == 1 )
    return 0;
  v4 = *(int **)(a2 + 96);
  v5 = v4 - 10;
  v6 = *v4;
  v7 = v4[1];
  v8 = v4[2];
  v9 = v4[3];
  v4 += 4;
  *v5 = v6;
  v5[1] = v7;
  v5[2] = v8;
  v5[3] = v9;
  v10 = v4[1];
  v11 = v4[2];
  v12 = v4[3];
  v5[4] = *v4;
  v5[5] = v10;
  v5[6] = v11;
  v5[7] = v12;
  *((_BYTE *)v5 + 3) = 0;
  IoSynchronousCallDriver(a1, a2);
  return 1;
}
