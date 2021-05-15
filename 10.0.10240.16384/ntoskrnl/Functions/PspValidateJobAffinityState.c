// PspValidateJobAffinityState 
 
int __fastcall PspValidateJobAffinityState(int a1, int a2)
{
  unsigned int *v5; // r2
  unsigned int v6; // r4

  ExAcquireResourceSharedLite(a1 + 32, 1);
  if ( *(_DWORD *)(a1 + 196) )
    return sub_7EBD78();
  __dmb(0xBu);
  v5 = (unsigned int *)(a2 + 192);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x4000000, v5) );
  __dmb(0xBu);
  ExReleaseResourceLite(a1 + 32);
  return 0;
}
