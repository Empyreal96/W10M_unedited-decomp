// CmUnlockHive 
 
unsigned int __fastcall CmUnlockHive(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1
  unsigned int result; // r0

  v1 = *(unsigned int **)(a1 + 1864);
  v1[1] = 0;
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( !v2 && __strex(1u, v1) );
  if ( v2 )
    result = sub_7DD5CC();
  else
    result = KeAbPostRelease((unsigned int)v1);
  return result;
}
