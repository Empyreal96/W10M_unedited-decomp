// PopUmpoSendPowerRequestOverrideQuery 
 
int __fastcall PopUmpoSendPowerRequestOverrideQuery(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r6
  _BYTE *v7; // r0
  _DWORD *v8; // r4
  int v9; // r5
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *(_DWORD *)(a1 + 60);
  v11[0] = 0;
  PoStoreRequester(v5, 0, v11, 1);
  v6 = v11[0];
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, v11[0] + 8, 1869638997);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  memset(v7, 0, v6 + 8);
  v9 = PoStoreRequester(*(_DWORD *)(a1 + 60), v8 + 2, v11, 1);
  if ( v9 >= 0 )
  {
    *v8 = 9;
    v8[1] = *(_DWORD *)(a1 + 20);
    if ( (PoDebug & 0x10000000) != 0 )
      return sub_529538();
    v9 = PopUmpoSendPowerMessage(v8, v6 + 8);
  }
  ExFreePoolWithTag(v8, 1869638997);
  return v9;
}
