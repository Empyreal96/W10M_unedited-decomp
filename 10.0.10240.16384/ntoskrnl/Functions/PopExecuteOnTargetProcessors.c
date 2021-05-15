// PopExecuteOnTargetProcessors 
 
int __fastcall PopExecuteOnTargetProcessors(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  _DWORD v6[2]; // [sp+8h] [bp-60h] BYREF
  __int16 v7; // [sp+10h] [bp-58h]
  char v8[4]; // [sp+18h] [bp-50h] BYREF
  int v9; // [sp+1Ch] [bp-4Ch]
  int v10[2]; // [sp+20h] [bp-48h] BYREF
  _DWORD v11[5]; // [sp+28h] [bp-40h] BYREF
  int v12; // [sp+3Ch] [bp-2Ch]
  char v13[40]; // [sp+40h] [bp-28h] BYREF

  v8[0] = 1;
  v8[1] = 0;
  v8[2] = 4;
  v9 = 0;
  v10[1] = (int)v10;
  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v10[0] = (int)v10;
  v12 = 0;
  v7 = 0;
  v4 = *(_DWORD *)(a1 + 8);
  v11[4] = v6;
  v6[0] = a1;
  v6[1] = v4;
  v11[3] = v8;
  PopQueueTargetDpc(v13, v11);
  KeWaitForSingleObject(v8, 0, 0);
  return v12;
}
