// EtwpLogGroupMask 
 
int __fastcall EtwpLogGroupMask(int a1, int *a2, int a3)
{
  int v6; // r0
  int v7; // r2
  int v8; // r4
  int v9; // r5
  int v10; // r2
  int v11; // r4
  int v12; // r5
  int v14[4]; // [sp+8h] [bp-48h] BYREF
  _DWORD v15[14]; // [sp+18h] [bp-38h] BYREF

  v6 = *a2;
  v7 = a2[1];
  v8 = a2[2];
  v9 = a2[3];
  a2 += 4;
  v15[0] = v6;
  v15[1] = v7;
  v15[2] = v8;
  v15[3] = v9;
  v10 = a2[1];
  v11 = a2[2];
  v12 = a2[3];
  v15[4] = *a2;
  v15[5] = v10;
  v15[6] = v11;
  v15[7] = v12;
  v15[8] = 60;
  v14[0] = (int)v15;
  v14[1] = 0;
  v14[2] = 36;
  v14[3] = 0;
  return EtwpLogKernelEvent(v14, a1, 1, a3, 4200450);
}
