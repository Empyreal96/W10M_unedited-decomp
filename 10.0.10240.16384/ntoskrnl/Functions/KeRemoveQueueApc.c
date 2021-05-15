// KeRemoveQueueApc 
 
int __fastcall KeRemoveQueueApc(int a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r7
  unsigned int *v5; // r5
  unsigned int v6; // r2
  int v8; // r4

  v2 = *(_DWORD *)(a1 + 8);
  v3 = KfRaiseIrql(2);
  v4 = v3;
  v5 = (unsigned int *)(v2 + 44);
  do
    v6 = __ldrex(v5);
  while ( __strex(1u, v5) );
  __dmb(0xBu);
  if ( v6 )
    return sub_523708(v3, 1);
  v8 = KiRemoveQueueApc(a1, 1);
  __dmb(0xBu);
  *v5 = 0;
  KfLowerIrql(v4);
  return v8;
}
