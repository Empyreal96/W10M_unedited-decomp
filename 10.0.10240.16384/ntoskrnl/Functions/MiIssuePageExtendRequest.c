// MiIssuePageExtendRequest 
 
int __fastcall MiIssuePageExtendRequest(int a1, int a2, unsigned int a3, char a4)
{
  int v7; // r6
  int *v8; // r4
  int result; // r0
  unsigned int v10; // r0
  unsigned int i; // r1
  int v12; // r3
  __int16 v13; // r2
  int v14; // r9
  int v15; // r0
  int **v16; // r1
  unsigned int v17; // r1
  int v18; // r6
  int v19; // r1
  unsigned int v20; // r0
  int v21; // [sp+8h] [bp-50h] BYREF
  int v22; // [sp+Ch] [bp-4Ch] BYREF
  int **v23; // [sp+10h] [bp-48h]
  int v24; // [sp+14h] [bp-44h]
  int v25; // [sp+18h] [bp-40h]
  int v26; // [sp+1Ch] [bp-3Ch]
  char v27[4]; // [sp+20h] [bp-38h] BYREF
  int v28; // [sp+24h] [bp-34h]
  int v29[3]; // [sp+28h] [bp-30h] BYREF
  char v30; // [sp+34h] [bp-24h]
  char v31; // [sp+37h] [bp-21h]
  int v32; // [sp+38h] [bp-20h]
  char v33; // [sp+3Ch] [bp-1Ch]
  char v34; // [sp+3Dh] [bp-1Bh]
  int vars4; // [sp+5Ch] [bp+4h]

  v7 = a1;
  v8 = (int *)MiDereferenceSegmentThread;
  if ( *(int (__fastcall **)(__int16 *))((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x39C) == MiDereferenceSegmentThread
    || (unsigned int)KeGetCurrentIrql(a1) >= 2 )
  {
    goto LABEL_2;
  }
  v10 = *(_DWORD *)(v7 + 3596);
  __dmb(0xBu);
  v29[2] = 1;
  v24 = v7;
  v25 = a2;
  v30 = a3;
  v26 = 0;
  v33 = 0;
  v34 = 0;
  v21 = 0;
  v31 = v31 & 0xFC | (2 * (a4 & 1));
  v32 = 0;
  v27[0] = 0;
  v27[1] = 0;
  v27[2] = 4;
  v28 = 0;
  v29[1] = (int)v29;
  if ( a3 < v10 )
    v8 = 0;
  v29[0] = (int)v29;
  if ( a3 >= v10 )
  {
    v8 = MiOneSecond;
    for ( i = 0; i < v10; v7 += 4 )
    {
      v12 = *(_DWORD *)(v7 + 3600);
      v13 = *(_WORD *)(v12 + 96);
      if ( (v13 & 0x10) == 0 && (v13 & 0x40) == 0 && *(_DWORD *)v12 < *(_DWORD *)(v12 + 4) )
        break;
      ++i;
    }
    if ( i == v10 )
      goto LABEL_2;
  }
  MiQueuePageFileExtension(&v21, 1);
  if ( KeWaitForSingleObject((unsigned int)v27, 0, 0, 0, v8) == 258 )
  {
    v14 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
    }
    else
    {
      do
        v17 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
      while ( __strex(v17 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
      __dmb(0xBu);
      if ( v17 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
      while ( 1 )
      {
        v18 = dword_632D80;
        if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632D80 & 0x40000000) == 0 )
        {
          v19 = dword_632D80 | 0x40000000;
          do
            v20 = __ldrex((unsigned int *)&dword_632D80);
          while ( v20 == v18 && __strex(v19, (unsigned int *)&dword_632D80) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( !v28 )
    {
      if ( v32 )
      {
        *(_DWORD *)(v32 + 48) = 0;
      }
      else
      {
        v15 = v22;
        v16 = v23;
        if ( *(int **)(v22 + 4) != &v22 || *v23 != &v22 )
          __fastfail(3u);
        *v23 = (int *)v22;
        *(_DWORD *)(v15 + 4) = v16;
      }
      v26 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_632D80 = 0;
    }
    KfLowerIrql(v14);
  }
  if ( !v26 )
LABEL_2:
    result = 0;
  else
    result = 1;
  return result;
}
