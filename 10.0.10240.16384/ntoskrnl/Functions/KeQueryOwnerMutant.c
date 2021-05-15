// KeQueryOwnerMutant 
 
int __fastcall KeQueryOwnerMutant(int a1, _DWORD *a2)
{
  int v4; // r0
  unsigned int v5; // r2
  int v7; // r2
  unsigned int v8; // r1

  *a2 = 0;
  a2[1] = 0;
  v4 = KfRaiseIrql(2);
  do
    v5 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v5 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_526E7C(v4);
  v7 = *(_DWORD *)(a1 + 24);
  if ( v7 )
  {
    *a2 = *(_DWORD *)(v7 + 876);
    a2[1] = *(_DWORD *)(v7 + 880);
  }
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)a1);
  while ( __strex(v8 & 0xFFFFFF7F, (unsigned int *)a1) );
  return KfLowerIrql(v4);
}
