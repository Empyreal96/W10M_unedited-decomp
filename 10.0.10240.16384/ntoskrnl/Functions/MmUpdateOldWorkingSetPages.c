// MmUpdateOldWorkingSetPages 
 
int __fastcall MmUpdateOldWorkingSetPages(_DWORD *a1, unsigned int a2, char a3)
{
  unsigned int *v4; // r5
  _DWORD *v5; // r7
  unsigned int v6; // r4
  int v7; // r6
  int v8; // r10
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r9
  unsigned int v14; // r2
  int v15; // r4
  unsigned int v16; // r2
  _DWORD *v17; // r1
  int v18; // r0
  char v19; // r3
  bool v20; // zf
  unsigned int v21; // r3
  unsigned int v23; // [sp+0h] [bp-E0h]
  unsigned int v24; // [sp+4h] [bp-DCh]
  int v25; // [sp+8h] [bp-D8h]
  int v26; // [sp+Ch] [bp-D4h]
  int v27; // [sp+10h] [bp-D0h]
  int v28; // [sp+14h] [bp-CCh]
  char v31[24]; // [sp+20h] [bp-C0h] BYREF
  unsigned int v32[42]; // [sp+38h] [bp-A8h] BYREF

  if ( *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) == a1 )
  {
    v27 = 0;
  }
  else
  {
    v27 = 1;
    KiStackAttachProcess((int)a1, 0, (int)v31);
  }
  v4 = a1 + 123;
  v5 = (_DWORD *)a1[146];
  v6 = -1;
  v7 = 2;
  v23 = 0;
  v32[0] = 0;
  v26 = 0;
  v8 = 0;
  while ( 1 )
  {
    v25 = 0;
    v28 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 123);
    }
    else
    {
      v9 = (unsigned __int8 *)a1 + 495;
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
      __dmb(0xBu);
      if ( v10 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a1 + 123);
      while ( 1 )
      {
        v11 = *v4;
        if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v11 & 0x40000000) == 0 )
        {
          do
            v12 = __ldrex(v4);
          while ( v12 == v11 && __strex(v11 | 0x40000000, v4) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( (a1[48] & 0x20) != 0 )
      break;
    if ( v7 == 2 )
    {
      if ( v5[9] == 16 )
      {
        v7 = 1;
        v8 = 13;
LABEL_23:
        v24 = v5[v8 + 15];
        v6 = MiRotateHeadWsle(v5, v8);
        v13 = 0;
        goto LABEL_53;
      }
      v7 = 0;
      v8 = 5;
    }
    if ( v7 )
      goto LABEL_23;
    v14 = v4[v8 + 5];
    v13 = v5[2];
    ++v6;
    v24 = v14;
    if ( v6 < v5[1] )
      v6 = v5[1];
    while ( 1 )
    {
      if ( v7 )
      {
        if ( v6 == 0xFFFFF )
          goto LABEL_28;
      }
      else if ( v6 > v13 )
      {
        goto LABEL_28;
      }
      if ( v23 >= v14 )
      {
LABEL_28:
        if ( v32[0] )
          MiFreeWsleList((int)(a1 + 123), v32, 0);
        v15 = 0;
        goto LABEL_58;
      }
      v16 = *(_DWORD *)(v6 * v5[9] + v5[63]);
      if ( (v16 & 1) != 0 && (*(_DWORD *)(v6 * v5[9] + v5[63]) & 0xE00) == 3072 )
      {
        ++v23;
        v17 = (_DWORD *)(((v16 >> 10) & 0x3FFFFC) - 0x40000000);
        if ( (*v17 & 0x10) == 0 )
        {
          v18 = MmPfnDatabase + 24 * (*v17 >> 12);
          if ( (*(_DWORD *)(v18 + 12) & 0x3FFFFFFF) == 1 && ((a3 & 2) == 0 || (*(_DWORD *)(v18 + 20) & 0x8000000) == 0) )
          {
            v19 = *(_BYTE *)(v18 + 19);
            v20 = (v19 & 8) == 0;
            v21 = v19 & 7;
            if ( !v20 )
              v21 = 5;
            if ( (a3 & 1) != 0 )
            {
              if ( a2 == 8 || v21 == a2 )
              {
                MiEmptyWorkingSetHelper((int)(a1 + 123), v17, v6, v32);
                ++v25;
              }
            }
            else if ( v21 > a2 )
            {
              MiLockSetPfnPriority(v18, a2);
            }
          }
        }
      }
      if ( (++v26 & 0xF) == 0 )
      {
        if ( ExSpinLockIsContended(a1 + 123) )
          break;
      }
      if ( KeShouldYieldProcessor() )
        break;
      if ( v7 )
        v6 = MiRotateHeadWsle(v5, v8);
      else
        ++v6;
LABEL_53:
      v14 = v24;
    }
    if ( v32[0] )
    {
      MiFreeWsleList((int)(a1 + 123), v32, 0);
      v32[0] = 0;
    }
    MiUnlockWorkingSetExclusive((int)(a1 + 123), v28);
    v23 -= v25;
  }
  v15 = -1073741558;
LABEL_58:
  MiUnlockWorkingSetExclusive((int)(a1 + 123), v28);
  if ( v27 == 1 )
    KiUnstackDetachProcess((unsigned int)v31, 0);
  return v15;
}
