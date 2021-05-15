// EtwpSynchronizeWithLogger 
 
int __fastcall EtwpSynchronizeWithLogger(int a1, int a2)
{
  unsigned int *v4; // r2
  unsigned int v5; // r5
  BOOL v6; // r0
  unsigned int v7; // r0
  int v9; // r4

  KeResetEvent(a1 + 356);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 612);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | a2, v4) );
  __dmb(0xBu);
  v6 = KeAreInterruptsEnabled();
  if ( v6 )
    v7 = KeGetCurrentIrql(v6);
  else
    v7 = 15;
  if ( v7 > 2 )
    return sub_7EFFB0();
  KeSetEvent(a1 + 372, 0, 0);
  KeWaitForSingleObject(a1 + 356, 0, 0, 0, 0);
  v9 = *(_DWORD *)(a1 + 40);
  KeResetEvent(a1 + 356);
  *(_DWORD *)(a1 + 40) = 0;
  return v9;
}
