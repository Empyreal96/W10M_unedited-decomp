// SmFpPreAllocate 
 
int __fastcall SmFpPreAllocate(int a1, unsigned int *a2, int a3)
{
  unsigned int v6; // r1
  unsigned int v7; // r9
  int v8; // r8
  int v9; // r4
  _DWORD *v10; // r0
  _DWORD *v11; // r5
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // r0
  unsigned int v16; // r3
  int v17; // r8
  unsigned __int8 *v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r0
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r1
  unsigned int *v26; // [sp+0h] [bp-68h]
  int var60[25]; // [sp+8h] [bp-60h] BYREF

  memset(var60, 0, 64);
  LOWORD(var60[1]) = 1;
  BYTE2(var60[1]) = 4;
  var60[2] = 0;
  var60[4] = (int)&var60[3];
  var60[3] = (int)&var60[3];
  v26 = &a2[a3];
  if ( a2 < v26 )
  {
    while ( 1 )
    {
      v6 = *a2;
      v7 = 0;
      v8 = *a2 & 0xF;
      *((_WORD *)&var60[12] + v8) = *a2 >> 4;
      if ( (v6 & 0xFF00000) != 0 )
        break;
LABEL_12:
      if ( ++a2 >= v26 )
        goto LABEL_13;
    }
    v9 = 8;
    while ( 1 )
    {
      v10 = (_DWORD *)ExAllocatePoolWithTag(512, 8);
      v11 = v10;
      if ( !v10 )
        return sub_551E30();
      *v10 = 0;
      v10[1] = 0;
      v13 = *a2;
      v14 = *a2 & 0xF;
      if ( v14 == 2 )
        break;
      if ( v14 != 3 )
      {
        if ( v14 >= 4 )
          v15 = MmAllocateMappingAddress((unsigned __int16)(v13 >> 4) << 12, 1834118515);
        else
          v15 = ExAllocatePoolWithTag(512, (unsigned __int16)(v13 >> 4));
LABEL_10:
        if ( !v15 )
          return sub_551E30();
        goto LABEL_11;
      }
      if ( !SmAcquireReleaseCharges((unsigned __int16)(v13 >> 4) << 12, 1, 0) )
        return sub_551E30();
      v15 = v9;
LABEL_11:
      v11[1] = v15;
      ++v7;
      v9 += 8;
      *v11 = var60[v8 + 5];
      v16 = *a2;
      var60[v8 + 5] = (int)v11;
      if ( v7 >= (unsigned __int8)(v16 >> 20) )
        goto LABEL_12;
    }
    v15 = SmKmAllocateMdlForLock((unsigned __int16)(v13 >> 4) << 12);
    goto LABEL_10;
  }
LABEL_13:
  v17 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
  }
  else
  {
    v18 = (unsigned __int8 *)(a1 + 3);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
    __dmb(0xBu);
    if ( v19 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
    while ( 1 )
    {
      v20 = *(_DWORD *)a1;
      if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v20 & 0x40000000) == 0 )
      {
        do
          v25 = __ldrex((unsigned int *)a1);
        while ( v25 == v20 && __strex(v20 | 0x40000000, (unsigned int *)a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v21 = var60[13];
  *(_DWORD *)(a1 + 48) = var60[12];
  *(_DWORD *)(a1 + 52) = v21;
  *(_WORD *)(a1 + 56) = var60[14];
  v22 = var60[6];
  v23 = var60[7];
  v24 = var60[8];
  *(_DWORD *)(a1 + 20) = var60[5];
  *(_DWORD *)(a1 + 24) = v22;
  *(_DWORD *)(a1 + 28) = v23;
  *(_DWORD *)(a1 + 32) = v24;
  *(_DWORD *)(a1 + 36) = var60[9];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v17);
  return 0;
}
