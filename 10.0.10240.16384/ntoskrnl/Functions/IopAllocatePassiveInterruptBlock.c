// IopAllocatePassiveInterruptBlock 
 
int __fastcall IopAllocatePassiveInterruptBlock(_DWORD *a1, int *a2, int a3, int a4)
{
  int v6; // r6
  int v7; // r4
  _BYTE *v9; // r0
  int v10; // r5
  int v11; // r1
  char v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD v16[6]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a3;
  v16[1] = a4;
  if ( *a1 != 1 || a1[2] )
    return -1073741585;
  v6 = a1[3];
  if ( IopFindPassiveInterruptBlock(v6) )
    return 0;
  v9 = (_BYTE *)ExAllocatePoolWithTag(512, 112, 1651077195);
  v10 = (int)v9;
  if ( !v9 )
    return -1073741670;
  memset(v9, 0, 112);
  *(_DWORD *)v10 = v10;
  *(_DWORD *)(v10 + 4) = v10;
  v11 = a1[14];
  *(_DWORD *)(v10 + 8) = v6;
  *(_DWORD *)(v10 + 12) = v11;
  *(_DWORD *)(v10 + 20) = a1[6];
  v12 = off_617A68(0, v11);
  v13 = *a2;
  v14 = a2[1];
  v15 = a2[2];
  *(_BYTE *)(v10 + 16) = v12;
  *(_DWORD *)(v10 + 24) = v13;
  *(_DWORD *)(v10 + 28) = v14;
  *(_DWORD *)(v10 + 32) = v15;
  KeInitializeEvent(v10 + 92, 1, 1);
  KeInitializeDpc(v10 + 60, (int)IopPassiveInterruptDpc, v10);
  *(_DWORD *)(v10 + 36) = 0;
  *(_DWORD *)(v10 + 52) = IopPassiveInterruptWorker;
  *(_DWORD *)(v10 + 56) = v10;
  *(_DWORD *)(v10 + 44) = 0;
  *(_BYTE *)(v10 + 61) = 2;
  v7 = IopInsertPassiveInterruptBlock((_DWORD *)v10, v16);
  if ( v7 >= 0 && LOBYTE(v16[0]) )
    return v7;
  return sub_7DF27C();
}
