// PfpPrefetchSharedConflictNotify 
 
int __fastcall PfpPrefetchSharedConflictNotify(_DWORD *a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  ++dword_637364;
  a1[11] = 1;
  __dmb(0xBu);
  v1 = a1 + 19;
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  __dmb(0xBu);
  a1[8] = 0;
  return 0;
}
