// MiFinishVadDeletion 
 
int __fastcall MiFinishVadDeletion(_DWORD *a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  unsigned int v9; // r8
  int v10; // r6
  BOOL v11; // r4
  unsigned int v12; // r0
  int result; // r0
  int v14; // r0
  int v15; // r2
  unsigned int v16; // r2
  unsigned int *v17; // r6
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r3
  _DWORD *v21; // r6
  int v22; // r0
  unsigned int v23; // r2
  unsigned int v24; // r2
  int v25; // r7
  unsigned int v26; // r4
  unsigned int *v27; // r9
  unsigned int v28; // r1
  __int16 v29; // r3
  _DWORD *v30; // r4
  int v31; // r3

  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_DWORD *)(v9 + 116);
  v11 = (int)a1[7] < 0;
  if ( (*(_BYTE *)(v10 + 607) & 2) == 0 )
  {
    v12 = MiClearVadBits(a4, a5, a2, a3);
    if ( (a1[8] & 0x7FFFFFFFu) >= 0x7FFFE )
      return sub_5447D0(v12);
    MiReturnPageTablePageCommitment(a4, a5, v10, a2, a3, a1, a6);
  }
  if ( v11 )
    v14 = MiUpdateVadHint(a1);
  else
    v14 = 0;
  if ( a5 <= *(_DWORD *)(v10 + 392) )
    *(_DWORD *)(v10 + 228) = *(_DWORD *)(v10 + 228) - a5 + a4 - 1;
  v15 = a1[7];
  if ( (v15 & 7) == 2 && (v15 & 0x20000) != 0 )
    --MEMORY[0xC0402148];
  if ( v11 )
  {
    do
      v16 = __ldrex((unsigned int *)0xC0402120);
    while ( __strex(v16 + 1, (unsigned int *)0xC0402120) );
    MiReturnVadQuota(a1, v10, v14);
    MiRemoveVadCharges(a1, v10);
  }
  v17 = (unsigned int *)(v10 + 252);
  *(_BYTE *)(v9 + 968) &= 0xFEu;
  __dmb(0xBu);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
    ExfTryToWakePushLock(v17);
  v19 = KeAbPostRelease((unsigned int)v17);
  v20 = (__int16)(*(_WORD *)(v9 + 310) + 1);
  *(_WORD *)(v9 + 310) = v20;
  if ( !v20 && *(_DWORD *)(v9 + 100) != v9 + 100 )
    KiCheckForKernelApcDelivery(v19);
  v21 = 0;
  if ( v11 )
  {
    v22 = MiGetVadWakeList(a1, 1);
    a1[2] = -1;
    v21 = (_DWORD *)v22;
    do
    {
      v23 = __ldrex((unsigned int *)0xC0402120);
      v24 = v23 - 1;
    }
    while ( __strex(v24, (unsigned int *)0xC0402120) );
    __dmb(0xBu);
    if ( !v24 )
      KeSetEvent(MEMORY[0xC0402128], 0, 0);
    if ( v21 )
      --*(_WORD *)(v9 + 308);
  }
  v25 = MiDereferenceVad(a1);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = a1 + 6;
  *(_BYTE *)(v26 + 0x3C8) &= 0x7Fu;
  __dmb(0xBu);
  do
    v28 = __ldrex(v27);
  while ( __strex(v28 - 1, v27) );
  if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 6);
  result = KeAbPostRelease((unsigned int)(a1 + 6));
  v29 = *(_WORD *)(v26 + 310) + 1;
  *(_WORD *)(v26 + 310) = v29;
  if ( !v29 && *(_DWORD *)(v26 + 100) != v26 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  if ( v25 == 1 )
    result = ExFreePoolWithTag(a1, 0);
  if ( v21 )
  {
    do
    {
      v30 = (_DWORD *)*v21;
      result = KeSignalGate((int)(v21 + 2), 1);
      v21 = v30;
    }
    while ( v30 );
    v31 = (__int16)(*(_WORD *)(v9 + 308) + 1);
    *(_WORD *)(v9 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
