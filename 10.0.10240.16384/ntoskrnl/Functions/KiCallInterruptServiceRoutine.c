// KiCallInterruptServiceRoutine 
 
int __fastcall KiCallInterruptServiceRoutine(int a1, int a2)
{
  unsigned int v4; // r3
  unsigned int v5; // r8
  int v6; // r9
  __int64 v7; // r0
  unsigned int v8; // r10
  unsigned int *v9; // r0
  unsigned int v11; // r2
  int v12; // r7
  _DWORD *v13; // r0
  __int64 v14; // r0
  __int64 v15; // r0
  unsigned int v16; // [sp+0h] [bp-20h]

  if ( *(_BYTE *)(a1 + 49) )
  {
    v4 = (unsigned int)KeGetPcr();
    v5 = (v4 & 0xFFFFF000) + 1408;
    v6 = *(_DWORD *)((v4 & 0xFFFFF000) + 0x124C);
    *(_BYTE *)(a1 + 152) = 1;
    *(_DWORD *)((v4 & 0xFFFFF000) + 0x124C) = a1 + 104;
    LODWORD(v7) = ReadTimeStampCounter();
    v8 = HIDWORD(v7);
    v16 = v7;
    *(_QWORD *)(a1 + 112) = v7;
    if ( a2 )
    {
      v9 = *(unsigned int **)(a1 + 36);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_53FBA4(v9);
      do
        v11 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire(v9);
    }
    v12 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a1, *(_DWORD *)(a1 + 24));
    if ( a2 )
    {
      v13 = *(_DWORD **)(a1 + 36);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v13);
      }
      else
      {
        __dmb(0xBu);
        *v13 = 0;
      }
    }
    LODWORD(v14) = ReadTimeStampCounter();
    *(_QWORD *)(a1 + 104) = *(_QWORD *)(a1 + 104) - *(_QWORD *)(a1 + 112) + v14;
    if ( v6 != 1 )
    {
      v15 = v14 - __PAIR64__(v8, v16);
      if ( *(_BYTE *)(v6 + 48) )
        *(_QWORD *)(v6 + 8) += v15;
      else
        *(_QWORD *)(v6 + 32) += v15;
    }
    *(_DWORD *)(v5 + 3276) = v6;
    *(_BYTE *)(a1 + 152) = 0;
    if ( !v12 )
      return 0;
    ++*(_QWORD *)(a1 + 120);
  }
  else
  {
    v12 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a1, *(_DWORD *)(a1 + 24));
  }
  return v12 != 0;
}
