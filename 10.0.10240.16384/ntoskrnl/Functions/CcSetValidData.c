// CcSetValidData 
 
int __fastcall CcSetValidData(int a1, int *a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2
  int v6; // r4
  int v8[2]; // [sp+8h] [bp-30h] BYREF
  int v9[2]; // [sp+10h] [bp-28h] BYREF
  char v10[4]; // [sp+18h] [bp-20h] BYREF
  int v11; // [sp+1Ch] [bp-1Ch]
  int v12[6]; // [sp+20h] [bp-18h] BYREF

  v8[0] = 0;
  v8[1] = 0;
  v9[0] = *a2;
  v9[1] = a2[1];
  v10[0] = 0;
  v10[1] = 0;
  v10[2] = 4;
  v11 = 0;
  v12[1] = (int)v12;
  v12[0] = (int)v12;
  v3 = IoGetRelatedDeviceObject(a1);
  v4 = IoAllocateIrp(*(char *)(v3 + 48), 0);
  if ( !v4 )
    return -1073741670;
  *(_DWORD *)(v4 + 8) = 66;
  *(_DWORD *)(v4 + 40) = v8;
  v5 = *(_DWORD *)(v4 + 96);
  *(_DWORD *)(v4 + 44) = v10;
  *(_BYTE *)(v4 + 32) = 0;
  *(_DWORD *)(v4 + 100) = a1;
  *(_DWORD *)(v4 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v4 + 12) = v9;
  *(_BYTE *)(v5 - 40) = 6;
  *(_DWORD *)(v5 - 32) = 8;
  *(_DWORD *)(v5 - 28) = 20;
  *(_DWORD *)(v5 - 24) = 0;
  *(_BYTE *)(v5 - 19) = 1;
  *(_DWORD *)(v5 - 16) = v3;
  *(_DWORD *)(v5 - 12) = a1;
  v6 = IofCallDriver(v3, v4);
  if ( v6 == 259 )
    KeWaitForSingleObject(v10, 0, 0);
  if ( v6 >= 0 )
    v6 = v8[0];
  return v6;
}
