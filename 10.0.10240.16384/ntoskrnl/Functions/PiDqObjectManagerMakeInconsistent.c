// PiDqObjectManagerMakeInconsistent 
 
unsigned int __fastcall PiDqObjectManagerMakeInconsistent(_DWORD *a1)
{
  unsigned int v1; // r4
  int v3; // r7
  int v4; // r6
  int v5; // r8
  unsigned int v6; // r2
  int v7; // r1
  int v8; // r6
  unsigned int v9; // r1
  unsigned int result; // r0

  v1 = (unsigned int)(a1 + 14);
  v3 = 0;
  v4 = KeAbPreAcquire((unsigned int)(a1 + 14), 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended(v1, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v1 + 28) = v5;
  v7 = a1[31];
  if ( (v7 & 2) == 0 && (_DWORD *)a1[26] != a1 + 26 )
  {
    a1[31] = v7 | 2;
    if ( ((v7 | 2) & 1) == 0 )
    {
      a1[31] = v7 | 3;
      v3 = 1;
    }
  }
  v8 = *(_DWORD *)(v1 + 28);
  *(_DWORD *)(v1 + 4) = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)v1);
  while ( !v9 && __strex(1u, (unsigned int *)v1) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)v1, v9);
  KfLowerIrql((unsigned __int8)v8);
  result = KeAbPostRelease(v1);
  if ( v3 )
    result = ExQueueWorkItem(a1 + 22, 3);
  return result;
}
