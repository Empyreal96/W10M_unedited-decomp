// VfPnpTestStartedPdoStack 
 
int __fastcall VfPnpTestStartedPdoStack(int a1)
{
  unsigned int v2; // r4
  unsigned int v4; // [sp+10h] [bp-58h] BYREF
  int v5; // [sp+14h] [bp-54h] BYREF
  int v6; // [sp+18h] [bp-50h] BYREF
  int v7; // [sp+1Ch] [bp-4Ch]
  int v8; // [sp+20h] [bp-48h]
  int v9; // [sp+24h] [bp-44h]
  int v10[16]; // [sp+28h] [bp-40h] BYREF

  memset(v10, 0, 40);
  LOWORD(v10[0]) = -229;
  VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, 0, 0, 0);
  BYTE1(v10[0]) = 7;
  v10[2] = -1;
  VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, 0, 0, 0);
  if ( (MmVerifierData & 0x10) != 0 )
  {
    BYTE1(v10[0]) = 7;
    v10[2] = -1;
    VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, -1, 0, 0);
  }
  BYTE1(v10[0]) = 12;
  v10[2] = -1;
  VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, 0, 0, 0);
  BYTE1(v10[0]) = 19;
  v10[2] = -1;
  VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, 0, 0, 0);
  BYTE1(v10[0]) = 7;
  v10[2] = 4;
  v4 = 0;
  if ( VfIrpSendSynchronousIrp(a1, (int)v10, 0, -1073741637, 0, &v4, &v5) && v5 >= 0 )
  {
    v2 = v4;
    ObfDereferenceObject(*(_DWORD *)(v4 + 4));
    ExFreePoolWithTag(v2);
  }
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  BYTE1(v10[0]) = 8;
  v10[4] = (int)&v6;
  v10[5] = -1;
  v10[3] = 0x1FFFF;
  v10[2] = (int)&GUID_BOGUS_INTERFACE;
  VfIrpSendSynchronousIrp(a1, (int)v10, 1, -1073741637, 0, 0, 0);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  BYTE1(v10[0]) = 8;
  v10[4] = (int)&v6;
  v10[5] = -1;
  v10[3] = 0x1FFFF;
  v10[2] = (int)&GUID_BOGUS_INTERFACE;
  return VfIrpSendSynchronousIrp(a1, (int)v10, 1, 0, 0, 0, 0);
}
