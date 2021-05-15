// ViPendingCompleteAfterWait 
 
unsigned int __fastcall ViPendingCompleteAfterWait(unsigned int a1)
{
  int v2; // r6
  unsigned int *v3; // r5
  char v4; // r7
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r7
  int v8; // r8
  int v9; // r3
  int v10; // r5
  int (__fastcall *v11)(_DWORD, int, _DWORD); // r3

  if ( *(_DWORD *)(a1 + 104) == 1 )
    KeWaitForSingleObject(a1 + 56, 0, 0, 0, 0);
  v2 = *(_DWORD *)a1;
  v3 = (unsigned int *)(*(_DWORD *)a1 + 4);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v5 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  v6 = *(_DWORD *)(v2 + 36);
  *(_BYTE *)(v2 + 8) = v4;
  v7 = *(_DWORD *)v2;
  v8 = *(_DWORD *)(*(_DWORD *)v2 + 96);
  *(_DWORD *)(v2 + 36) = v6 & 0xFFFFFFEF;
  v9 = *(_DWORD *)(v2 + 128);
  if ( !v9 || (v10 = *(_DWORD *)(v9 + 24)) == 0 )
    v10 = 0;
  VfIrpDatabaseEntryDereference(v2, 1);
  VfIrpDatabaseEntryReleaseLock(v2);
  v11 = *(int (__fastcall **)(_DWORD, int, _DWORD))(v8 - 8);
  if ( !v11 || v11(*(_DWORD *)(a1 + 4), v7, *(_DWORD *)(v8 - 4)) != -1073741802 )
    IofCompleteRequest(v7, *(_BYTE *)(a1 + 108));
  if ( v10 )
    ObfDereferenceObject(v10);
  return ExFreePoolWithTag(a1);
}
