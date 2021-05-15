// ExGetNextWakeTime 
 
// local variable allocation has failed, the output may be wrong!
BOOL __fastcall ExGetNextWakeTime(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, char a5, unsigned int *a6, unsigned int *a7)
{
  _DWORD *v8; // r6
  __int64 v9; // r0
  unsigned int v10; // r5
  int *v11; // r10
  unsigned int v12; // r5
  int v13; // r4
  unsigned int v14; // r7 OVERLAPPED
  unsigned int v15; // r8 OVERLAPPED
  unsigned int *v16; // r9
  unsigned int v17; // r2
  __int64 v18; // kr00_8
  __int64 v19; // r0
  int v20; // r0
  unsigned int v21; // r3
  int v23; // [sp+0h] [bp-48h]
  unsigned int v24; // [sp+0h] [bp-48h]
  __int64 v26; // [sp+8h] [bp-40h] BYREF
  unsigned int v27; // [sp+10h] [bp-38h]
  unsigned int v28; // [sp+14h] [bp-34h]
  _DWORD *v29; // [sp+18h] [bp-30h]
  __int64 v30[5]; // [sp+20h] [bp-28h] BYREF
  int vars4; // [sp+4Ch] [bp+4h]

  v27 = a2;
  v28 = a1;
  v8 = 0;
  KeQuerySystemTime(v30);
  LODWORD(v9) = KeQueryInterruptTime();
  v10 = 0;
  v26 = v9;
  v11 = (int *)ExpWakeTimerList;
  if ( (int *)ExpWakeTimerList != &ExpWakeTimerList )
  {
    v12 = a3;
    do
    {
      v13 = (int)(v11 - 38);
      v11 = (int *)*v11;
      v14 = 0;
      v15 = 0;
      v16 = (unsigned int *)(v13 + 48);
      v23 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v13 + 48);
      }
      else
      {
        do
          v17 = __ldrex(v16);
        while ( __strex(1u, v16) );
        __dmb(0xBu);
        if ( v17 )
          KxWaitForSpinLockAndAcquire((unsigned int *)(v13 + 48));
      }
      v29 = *(_DWORD **)(v13 + 148);
      if ( !a5 || (*(_BYTE *)(v13 + 144) & 4) != 0 )
      {
        if ( (*(_BYTE *)(v13 + 144) & 2) != 0 )
        {
          if ( *(_BYTE *)(v13 + 145) == 1 )
          {
            v18 = *(_QWORD *)(v13 + 176);
            v14 = 0;
            v15 = 0;
            if ( v18 )
            {
              v15 = (unsigned __int64)(v18 - v30[0] + v26) >> 32;
              v14 = v18 - LODWORD(v30[0]) + v26;
            }
          }
          else
          {
            *(_QWORD *)&v14 = *(_QWORD *)(v13 + 176);
          }
        }
        else
        {
          v19 = KeQueryTimerDueTime(v13);
          v15 = HIDWORD(v19);
          v14 = v19;
        }
        if ( v15 <= v27 && (v15 < v27 || v14 < v28) )
        {
          v14 = 0;
          v15 = 0;
        }
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)(v13 + 48), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      KfLowerIrql(v23);
      if ( __PAIR64__(v15, v14) - 1 < __PAIR64__((v12 != 0) + a4 - 1, v12 - 1) )
      {
        v8 = v29;
        v12 = v14;
        a4 = v15;
      }
    }
    while ( v11 != &ExpWakeTimerList );
    v24 = v12;
    v10 = 0;
    if ( v8 )
    {
      PoStoreDiagnosticContext(v8, 0, (unsigned int *)&v26, (unsigned int)&ExpWakeTimerList);
      v20 = ExAllocatePoolWithTag(1, v26, 1398239828);
      v10 = v20;
      if ( v20 )
      {
        if ( PoStoreDiagnosticContext(v8, v20, (unsigned int *)&v26, v21) < 0 )
        {
          ExFreePoolWithTag(v10);
          v10 = 0;
        }
      }
    }
    a3 = v24;
  }
  *a6 = a3;
  a6[1] = a4;
  *a7 = v10;
  return v8 != 0;
}
