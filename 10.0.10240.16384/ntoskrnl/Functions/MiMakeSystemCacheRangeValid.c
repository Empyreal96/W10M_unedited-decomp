// MiMakeSystemCacheRangeValid 
 
int __fastcall MiMakeSystemCacheRangeValid(int a1, unsigned int *a2, unsigned int a3, int a4)
{
  int result; // r0
  unsigned int v8; // r0
  int v9; // r6
  unsigned int v10; // r4
  int v11; // r6
  unsigned int v12; // r0
  int v13; // r2
  unsigned int v14; // r7
  unsigned int *i; // r9
  unsigned int v16; // r8
  int *v17; // r4
  int v18; // r6
  int v19; // r5
  int v20; // r0
  int v21; // r1
  int v22; // r4
  int v23; // r5
  unsigned __int8 *v24; // r3
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r0
  unsigned __int8 *v28; // r1
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r0
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  int v36; // r3
  unsigned int v37; // r2
  int v39; // [sp+Ch] [bp-ACh]
  int v40; // [sp+10h] [bp-A8h]
  _DWORD v41[40]; // [sp+18h] [bp-A0h]

  v40 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_546BB4();
  do
    v8 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
  while ( __strex(v8 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
  while ( 1 )
  {
    v9 = dword_634E00;
    if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634E00 & 0x40000000) == 0 )
    {
      do
        v32 = __ldrex((unsigned int *)&dword_634E00);
      while ( v32 == v9 && __strex(v9 | 0x40000000, (unsigned int *)&dword_634E00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = 0;
  if ( a3 )
  {
    v11 = a1 - (_DWORD)a2;
    do
    {
      v12 = *a2;
      v41[v10] = 0;
      if ( v12 )
      {
        if ( (v12 & 2) != 0 )
        {
          if ( (*(unsigned int *)((char *)a2 + v11) & 2) != 0 )
          {
            v41[v10] = 1;
          }
          else
          {
            v13 = MmPfnDatabase + 24 * (v12 >> 12);
            v41[v10 + 16] = *(_DWORD *)(v13 + 8);
            v39 = v13;
            if ( MiAllocateWsle((int)&dword_634E00, (unsigned int)a2 + v11, v13, 0, v12, 0) )
            {
              if ( (v41[v10 + 16] & 0x400) != 0 && PfSnNumActiveTraces )
                v41[v10] = *(_DWORD *)(v39 + 4) | 0x80000000;
            }
            else
            {
              v41[v10] = 1;
            }
          }
        }
        else
        {
          *a2 = v12 | 2;
          v41[v10] = 1;
        }
      }
      ++v10;
      ++a2;
    }
    while ( v10 < a3 );
  }
  result = MiUnlockWorkingSetExclusive((int)&dword_634E00, v40);
  v14 = 0;
  for ( i = &a2[-a3]; v14 < a3; ++i )
  {
    v16 = v41[v14];
    if ( v16 == 1 )
    {
      v22 = MmPfnDatabase + 24 * (*i >> 12);
      v23 = KfRaiseIrql(2);
      v24 = (unsigned __int8 *)(v22 + 15);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 | 0x80, v24) );
      __dmb(0xBu);
      if ( v25 >> 7 )
      {
        v33 = (unsigned __int8 *)(v22 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v34 = *(_DWORD *)(v22 + 12);
            __dmb(0xBu);
          }
          while ( (v34 & 0x80000000) != 0 );
          do
            v35 = __ldrex(v33);
          while ( __strex(v35 | 0x80, v33) );
          __dmb(0xBu);
        }
        while ( v35 >> 7 );
      }
      if ( (*(_BYTE *)(v22 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v22 - MmPfnDatabase) / 24);
      if ( !MiUpdateShareCount(v22, -1) )
        MiPfnShareCountIsZero(v22, 0);
      __dmb(0xBu);
      v26 = (unsigned int *)(v22 + 12);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 & 0x7FFFFFFF, v26) );
      v28 = (unsigned __int8 *)(a4 + 15);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 | 0x80, v28) );
      __dmb(0xBu);
      if ( v29 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v36 = *(_DWORD *)(a4 + 12);
            __dmb(0xBu);
          }
          while ( (v36 & 0x80000000) != 0 );
          do
            v37 = __ldrex(v28);
          while ( __strex(v37 | 0x80, v28) );
          __dmb(0xBu);
        }
        while ( v37 >> 7 );
      }
      if ( (*(_BYTE *)(a4 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (a4 - MmPfnDatabase) / 24);
      if ( !MiUpdateShareCount(a4, -1) )
        MiPfnShareCountIsZero(a4, 0);
      __dmb(0xBu);
      v30 = (unsigned int *)(a4 + 12);
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 & 0x7FFFFFFF, v30) );
      result = KfLowerIrql(v23);
    }
    else if ( v16 )
    {
      v17 = (int *)(v41[v14 + 16] & 0xFFFFF800 | (2 * (v41[v14 + 16] & 0x3FC)));
      v18 = *v17;
      v19 = MI_REFERENCE_CONTROL_AREA_FILE(*v17);
      v20 = MiStartingOffset(v17, v16);
      PfSnLogPageFault(v19, 4, v20, v21, 4);
      result = MI_DEREFERENCE_CONTROL_AREA_FILE(v18, v19);
    }
    ++v14;
  }
  return result;
}
