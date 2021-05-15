// ViFilterDeviceUsageNotificationCompletion 
 
int __fastcall ViFilterDeviceUsageNotificationCompletion(int a1, int a2)
{
  _DWORD *v4; // r4
  int v5; // r8
  unsigned int *v6; // r7
  int v7; // r10
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r3
  int v12; // r3
  int vars4; // [sp+24h] [bp+4h]

  if ( *(_BYTE *)(a2 + 33) )
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  v4 = *(_DWORD **)(a1 + 40);
  if ( *(int *)(a2 + 24) >= 0 )
  {
    v5 = *(_DWORD *)(a2 + 96);
    v6 = v4 + 14;
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(v4 + 14));
    }
    else
    {
      do
        v8 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire(v4 + 14);
    }
    v9 = v4[15];
    if ( *(_BYTE *)(v5 + 8) )
    {
      v10 = v9 + 1;
      v4[15] = v10;
      if ( v10 == 1 )
      {
        v11 = *(_DWORD *)(a1 + 28) & 0xFFFFDFFF;
LABEL_14:
        *(_DWORD *)(a1 + 28) = v11;
        goto LABEL_15;
      }
    }
    else
    {
      v12 = v9 - 1;
      v4[15] = v12;
      if ( !v12 )
      {
        v11 = *(_DWORD *)(a1 + 28) | *(_DWORD *)(v4[1] + 28) & 0x2000;
        goto LABEL_14;
      }
    }
LABEL_15:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4 + 14, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v7);
  }
  IoReleaseRemoveLockEx((int)(v4 + 4), a2, 24);
  return 0;
}
