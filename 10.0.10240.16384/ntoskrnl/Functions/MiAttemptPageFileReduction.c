// MiAttemptPageFileReduction 
 
int __fastcall MiAttemptPageFileReduction(int a1)
{
  char *v2; // r6
  int v3; // r3
  int v4; // r10
  unsigned int v5; // r1
  int v6; // r7
  int v7; // r1
  unsigned int v8; // r0
  int result; // r0
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r2
  unsigned __int64 v14; // [sp+8h] [bp-80h] BYREF
  char v15[48]; // [sp+10h] [bp-78h] BYREF
  int var48[20]; // [sp+40h] [bp-48h] BYREF

  memset(var48, 0, 36);
  LOWORD(var48[0]) = 0;
  BYTE2(var48[0]) = 4;
  var48[1] = 0;
  var48[3] = (int)&var48[2];
  v2 = *(char **)(a1 + 12);
  var48[2] = (int)&var48[2];
  v3 = *(unsigned __int8 *)(a1 + 53);
  var48[4] = (int)v2;
  if ( !v3 )
  {
    var48[5] = *(unsigned __int8 *)(a1 + 44);
    var48[6] = *(_DWORD *)(a1 + 20);
LABEL_20:
    result = MiQueueSyncModifiedWriterApc(v2, v15, MiAttemptPageFileReductionApc, var48, var48);
    v10 = (char *)var48 - v2;
    v11 = 2;
    do
    {
      v12 = *(_DWORD *)&v2[v10 + 28];
      if ( v12 )
      {
        v13 = *((_DWORD *)v2 + 900);
        v14 = (unsigned __int64)v12 << 12;
        result = IoSetInformation(*(_DWORD *)(v13 + 32), 19, 8, &v14);
      }
      v2 += 4;
      --v11;
    }
    while ( v11 );
    return result;
  }
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v5 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v6 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v7 = dword_632D80 | 0x40000000;
        do
          v8 = __ldrex((unsigned int *)&dword_632D80);
        while ( v8 == v6 && __strex(v7, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *(_DWORD *)(a1 + 16) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, var48[19]);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  KfLowerIrql(v4);
  result = MiOkToShrinkPageFiles(*((_DWORD *)v2 + 961), *((_DWORD *)v2 + 1029));
  if ( result )
  {
    var48[5] = 2;
    goto LABEL_20;
  }
  return result;
}
