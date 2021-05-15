// MiDeprioritizeVad 
 
int __fastcall MiDeprioritizeVad(int a1, unsigned int a2, int a3)
{
  _DWORD *v3; // r9
  int result; // r0
  int v8; // r3
  int v9; // r10
  unsigned int v10; // r8
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r8
  unsigned int *v15; // r4
  int v16; // r9
  unsigned int v17; // r1
  int v18; // r3
  unsigned __int8 *v19; // r3
  unsigned int v20; // r0
  unsigned int v21; // [sp+0h] [bp-20h]

  v3 = *(_DWORD **)(a3 + 116);
  --*(_WORD *)(a3 + 310);
  if ( MiTryLockVad(a3, a1) )
  {
    if ( !MiVadDeleted(a1) )
    {
      v9 = *(_DWORD *)(a1 + 12);
      v10 = ((a2 >> 12) - v9) >> 8;
      v21 = v10;
      if ( (*(_DWORD *)(a1 + 40) & 0x2000000) != 0 )
      {
        v11 = **(_DWORD **)(a1 + 44);
        v12 = MI_REFERENCE_CONTROL_AREA_FILE(v11);
        v13 = *(_DWORD *)(v12 + 12);
        MI_DEREFERENCE_CONTROL_AREA_FILE(v11, v12);
        if ( (v3[48] & 0x4000) != 0 )
          v14 = PfCheckDeprioritizeFile(v3[102], v13, v10 << 8);
        else
          v14 = 0;
        v15 = v3 + 123;
        v16 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v15);
        }
        else
        {
          v19 = (unsigned __int8 *)v15 + 3;
          do
            v17 = __ldrex(v19);
          while ( __strex(v17 | 0x80, v19) );
          __dmb(0xBu);
          if ( v17 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v15);
          while ( 1 )
          {
            v20 = *v15;
            if ( (*v15 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v20 & 0x40000000) == 0 )
            {
              do
                v17 = __ldrex(v15);
              while ( v17 == v20 && __strex(v20 | 0x40000000, v15) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v18 = *(_DWORD *)(a1 + 40);
        if ( v14 == 1 )
        {
          if ( (v18 & 0x2000000) != 0 )
            MiDeprioritizeVARange((v9 + (v21 << 8) - 256) << 12, v17, v15, 50);
        }
        else
        {
          *(_DWORD *)(a1 + 40) = v18 & 0xFDFFFFFF;
        }
        MiUnlockWorkingSetExclusive((int)v15, v16);
      }
    }
    result = MiUnlockAndDereferenceVad(a1);
  }
  else
  {
    result = MiDereferenceVadUnsafe(a1);
    if ( result == 1 )
      result = ExFreePoolWithTag(a1);
    v8 = (__int16)(*(_WORD *)(a3 + 310) + 1);
    *(_WORD *)(a3 + 310) = v8;
    if ( !v8 && *(_DWORD *)(a3 + 100) != a3 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
