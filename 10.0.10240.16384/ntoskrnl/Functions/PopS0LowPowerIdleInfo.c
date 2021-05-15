// PopS0LowPowerIdleInfo 
 
int __fastcall PopS0LowPowerIdleInfo(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  char v7; // r2
  int v8; // r3
  char v9; // r2
  int v10; // r3
  char v11; // r2
  int v12; // r3
  char v13; // r5
  bool v14; // r3
  int v16[4]; // [sp+0h] [bp-10h] BYREF

  v16[0] = a4;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v5 = 0;
  if ( !PopPlatformAoAc )
    return -1073741637;
  PopAcquirePolicyLock();
  v6 = PopDisconnectedStandbyEnabled(v16);
  *(_DWORD *)a1 = v16[0];
  v7 = (*(_BYTE *)(a1 + 4) ^ (PopCsDeviceCompliance == 1)) & 1 ^ *(_BYTE *)(a1 + 4);
  v8 = dword_641718;
  *(_BYTE *)(a1 + 4) = v7;
  v9 = v7 ^ (v7 ^ (2 * (v8 == 1))) & 2;
  v10 = dword_64171C;
  *(_BYTE *)(a1 + 4) = v9;
  v11 = v9 ^ (v9 ^ (4 * (v10 == 1))) & 4;
  v12 = dword_641724;
  *(_BYTE *)(a1 + 4) = v11;
  *(_BYTE *)(a1 + 4) = (v11 ^ (8 * (v12 == 1))) & 8 ^ v11;
  v13 = (*(_BYTE *)(a1 + 5) ^ (dword_61EC58 == 1)) & 1 ^ *(_BYTE *)(a1 + 5);
  *(_BYTE *)(a1 + 5) = v13;
  v14 = PopEnforceDisconnectedStandby || !PopConnectedStandbyComplianceChecks(v6);
  *(_BYTE *)(a1 + 5) = (v13 ^ (2 * v14)) & 2 ^ v13;
  PopReleasePolicyLock();
  return v5;
}
