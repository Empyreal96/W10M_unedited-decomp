// MiReturnPfnReferenceCount 
 
int __fastcall MiReturnPfnReferenceCount(int a1)
{
  int v2; // r6
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  int v6; // r5
  unsigned int *v7; // r2
  unsigned int v8; // r4

  v2 = KfRaiseIrql(2);
  v3 = (unsigned __int8 *)(a1 + 15);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    return sub_51A8A4();
  v6 = MiRemoveLockedPageChargeAndDecRef(a1);
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 12);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 & 0x7FFFFFFF, v7) );
  KfLowerIrql(v2);
  return v6;
}
