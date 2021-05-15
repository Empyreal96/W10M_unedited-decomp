// ViPendingDelayCompletion 
 
int __fastcall ViPendingDelayCompletion(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r6
  int v10; // r0
  unsigned int v11; // r5
  int v12; // r3
  int v13; // r7
  _DWORD *v14; // r0
  int v15; // r3
  int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r1

  v9 = 1;
  v10 = ExAllocatePoolWithTag(512, 112, 1685090889);
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = VfSettingsIrpDeferralTime;
  __dmb(0xBu);
  v13 = -v12;
  v14 = KeInitializeTimerEx((_DWORD *)(v10 + 56), 1);
  *(_DWORD *)(a2 + 36) |= 0x10u;
  *(_DWORD *)v11 = a2;
  *(_DWORD *)(v11 + 4) = a1;
  *(_DWORD *)(v11 + 12) = a4;
  *(_DWORD *)(v11 + 16) = a5;
  *(_DWORD *)(v11 + 8) = a3;
  *(_BYTE *)(v11 + 108) = *(_BYTE *)(a2 + 109);
  v15 = *(_DWORD *)(a2 + 128);
  if ( v15 && (v16 = *(_DWORD *)(v15 + 24)) != 0 )
    v14 = (_DWORD *)ObfReferenceObject(*(_DWORD *)(v15 + 24));
  else
    v16 = 0;
  if ( (unsigned int)KeGetCurrentIrql(v14) >= 2 )
  {
    *(_DWORD *)(v11 + 104) = 2;
    KeInitializeDpc(v11 + 20, (int)ViPendingCompleteAtDPC, v11);
    KiSetTimerEx(v11 + 56, v18, v13, 0, 0, v11 + 20);
  }
  else
  {
    *(_DWORD *)(v11 + 104) = 1;
    KiSetTimerEx(v11 + 56, v17, v13, 0, 0, 0);
    v9 = ViPendingQueuePassiveLevelCompletion(v11);
    if ( !v9 )
    {
      KeCancelTimer(v11 + 56);
      ExFreePoolWithTag(v11);
      *(_DWORD *)(a2 + 36) &= 0xFFFFFFEF;
      if ( v16 )
        ObfDereferenceObject(v16);
    }
  }
  return v9;
}
