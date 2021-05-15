// PiDqObjectManagerLockData 
 
int __fastcall PiDqObjectManagerLockData(int a1)
{
  int v1; // r5
  int v2; // r4
  int result; // r0
  int v4; // r6
  unsigned int v5; // r2

  v1 = a1 + 56;
  v2 = KeAbPreAcquire(a1 + 56, 0, 0);
  result = KfRaiseIrql(1);
  v4 = result;
  do
    v5 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    result = ExpAcquireFastMutexContended(v1, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v1 + 28) = v4;
  return result;
}
