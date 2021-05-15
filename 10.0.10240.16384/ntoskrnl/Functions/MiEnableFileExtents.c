// MiEnableFileExtents 
 
int __fastcall MiEnableFileExtents(int *a1, int a2, int a3)
{
  int v4; // r9
  int *v5; // r2
  unsigned int *v6; // r4
  unsigned int *v7; // r4
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r5
  __int64 v13; // r0
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v21; // [sp+10h] [bp-30h] BYREF
  char v22[4]; // [sp+14h] [bp-2Ch] BYREF
  int v23; // [sp+18h] [bp-28h]
  int var24[10]; // [sp+1Ch] [bp-24h] BYREF
  int vars4; // [sp+44h] [bp+4h]

  v4 = *a1;
  if ( a1[3] )
  {
    while ( !a1[1] )
    {
      v22[0] = 7;
      v22[1] = 1;
      v22[2] = 4;
      v23 = 0;
      v5 = (int *)a1[3];
      var24[1] = (int)var24;
      var24[0] = (int)var24;
      v6 = (unsigned int *)(v4 + 36);
      v21 = *v5;
      *v5 = (int)&v21;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v4 + 36), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v6 = 0;
      }
      KfLowerIrql(a2);
      KeWaitForGate((int)v22, 18);
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 36));
      }
      else
      {
        v8 = (unsigned __int8 *)(v4 + 39);
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 | 0x80, v8) );
        __dmb(0xBu);
        if ( v9 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 36));
        while ( 1 )
        {
          v10 = *v6;
          if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v10 & 0x40000000) == 0 )
          {
            do
              v11 = __ldrex(v6);
            while ( v11 == v10 && __strex(v10 | 0x40000000, v6) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( !a1[3] )
        goto LABEL_9;
    }
    v12 = -1073741791;
  }
  else
  {
LABEL_9:
    v7 = (unsigned int *)(v4 + 36);
    a1[3] = a3;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v4 + 36), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    v13 = KfLowerIrql(a2);
    v12 = MiCreateFileOnlyPfns(v13, HIDWORD(v13), a1[7], a3);
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 36));
    }
    else
    {
      v15 = (unsigned __int8 *)(v4 + 39);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 36));
      while ( 1 )
      {
        v17 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v7);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v12 < 0 )
      a1[3] = 0;
  }
  return v12;
}
