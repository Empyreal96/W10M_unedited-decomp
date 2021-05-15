// PiDqObjectManagerHandleObjectEvent 
 
int __fastcall PiDqObjectManagerHandleObjectEvent(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int v5; // r8
  int v7; // r9
  int result; // r0
  unsigned __int8 *v9; // r5
  int v10; // r6
  int v11; // r10
  unsigned int v12; // r2
  unsigned int **v13; // r6
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r6
  unsigned int v17; // r1
  unsigned int *v18; // [sp+0h] [bp-20h] BYREF

  v18 = a4;
  v5 = 0;
  v7 = 0;
  if ( (*(_DWORD *)(a2 + 4) & 2) != 0 )
    return sub_7E7934();
  v9 = (unsigned __int8 *)(a1 + 14);
  v10 = KeAbPreAcquire((unsigned int)(a1 + 14), 0, 0);
  v11 = KfRaiseIrql(1);
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 & 0xFE, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
    ExpAcquireFastMutexContended((int)(a1 + 14), v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  a1[15] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  a1[21] = v11;
  if ( (a1[31] & 2) == 0 && (unsigned int *)a1[26] != a1 + 26 )
  {
    v5 = PiDqObjectActionQueueEntryCreate(a2, &v18);
    if ( v5 < 0 )
    {
      a1[31] |= 2u;
    }
    else
    {
      v13 = (unsigned int **)a1[29];
      v14 = v18;
      *v18 = (unsigned int)(a1 + 28);
      v14[1] = (unsigned int)v13;
      if ( *v13 != a1 + 28 )
        __fastfail(3u);
      *v13 = v14;
      a1[29] = (unsigned int)v14;
    }
  }
  v15 = a1[31];
  if ( (v15 & 1) == 0 && ((unsigned int *)a1[28] != a1 + 28 || v5 < 0) )
  {
    a1[31] = v15 | 1;
    v7 = 1;
  }
  v16 = a1[21];
  a1[15] = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v9);
  while ( !v17 && __strex(1u, (unsigned int *)v9) );
  if ( v17 )
    ExpReleaseFastMutexContended(a1 + 14, v17);
  KfLowerIrql((unsigned __int8)v16);
  result = KeAbPostRelease((unsigned int)(a1 + 14));
  if ( v7 )
    result = ExQueueWorkItem(a1 + 22, 3);
  return result;
}
