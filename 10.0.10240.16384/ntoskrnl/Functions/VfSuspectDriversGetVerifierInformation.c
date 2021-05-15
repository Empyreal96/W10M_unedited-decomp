// VfSuspectDriversGetVerifierInformation 
 
int __fastcall VfSuspectDriversGetVerifierInformation(int a1, unsigned int a2, _DWORD *a3, int a4, int a5)
{
  int v5; // r8
  unsigned int v6; // r9
  int v7; // r5
  int v8; // r4
  int v9; // r6
  int v10; // r1
  unsigned int v11; // r9
  unsigned int v12; // r0
  unsigned int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r0
  int v23; // [sp+0h] [bp-48h]
  int v26; // [sp+Ch] [bp-3Ch]
  unsigned int v28; // [sp+14h] [bp-34h]
  char v29[8]; // [sp+18h] [bp-30h] BYREF
  int v30; // [sp+20h] [bp-28h]
  int v31; // [sp+24h] [bp-24h]
  int v32; // [sp+28h] [bp-20h]

  v26 = a1;
  if ( a5 )
    v5 = 188;
  else
    v5 = 104;
  *a3 = 0;
  v6 = 0;
  v7 = 0;
  v8 = a1;
  VfDriverLock();
  v9 = VfSuspectDriversList;
  if ( (int *)VfSuspectDriversList != &VfSuspectDriversList )
  {
    while ( 1 )
    {
      v10 = v9;
      v8 += v6;
      v11 = *(unsigned __int16 *)(v9 + 16);
      v9 = *(_DWORD *)v9;
      v12 = (v11 + v5 + 5) & 0xFFFFFFFC;
      v23 = v10;
      v28 = v12;
      v13 = *a3 + v12;
      *a3 = v13;
      if ( v13 > a2 )
        break;
      *(_DWORD *)v8 = v12;
      *(_DWORD *)(v8 + 4) = MmVerifierData;
      v14 = dword_620D84;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 16) = v14;
      v15 = dword_620D88;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 20) = v15;
      *(_DWORD *)(v8 + 68) = dword_620DB8;
      v16 = dword_620D8C;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 24) = v16;
      v17 = dword_620D90;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 28) = v17;
      v18 = dword_620D94;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 32) = v18;
      v19 = dword_620D98;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 36) = v19;
      *(_DWORD *)(v8 + 40) = dword_620D9C;
      *(_DWORD *)(v8 + 44) = dword_620DA0;
      *(_DWORD *)(v8 + 48) = dword_620DA4;
      *(_DWORD *)(v8 + 52) = dword_620DA8;
      v20 = dword_620DAC;
      __dmb(0xBu);
      *(_DWORD *)(v8 + 56) = v20;
      *(_DWORD *)(v8 + 60) = *(_DWORD *)(v10 + 8);
      *(_DWORD *)(v8 + 64) = *(_DWORD *)(v10 + 12);
      if ( *(_DWORD *)(v10 + 8) <= *(_DWORD *)(v10 + 12) )
      {
        VfTargetDriversGetZeroCounters((_DWORD *)v8, a5);
      }
      else
      {
        VfTargetDriversGetZeroCounters((_DWORD *)v8, a5);
        v30 = v23;
        v31 = v8;
        v32 = a5;
        v21 = VfAvlInitializeLockContext((int)v29, 1);
        VfAvlEnumerateNodes(v21, v29);
        VfAvlCleanupLockContext((int)v29);
      }
      *(_WORD *)(v8 + 10) = v11 + 2;
      *(_WORD *)(v8 + 8) = v11;
      *(_DWORD *)(v8 + 12) = v8 + v5;
      memmove(v8 + v5, *(_DWORD *)(v23 + 20), v11);
      *(_WORD *)(*(_DWORD *)(v8 + 12) + 2 * (v11 >> 1)) = 0;
      v6 = v28;
      *(_DWORD *)(v8 + 12) = *(_DWORD *)(v8 + 12) - v26 + a4;
      if ( (int *)v9 == &VfSuspectDriversList )
        goto LABEL_12;
    }
    v7 = -1073741820;
  }
LABEL_12:
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  if ( v7 >= 0 )
    *(_DWORD *)v8 = 0;
  return v7;
}
