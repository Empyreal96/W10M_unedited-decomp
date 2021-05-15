// CmpUnlockHiveWriter 
 
unsigned int __fastcall CmpUnlockHiveWriter(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1
  unsigned int result; // r0

  v1 = *(unsigned int **)(a1 + 1868);
  v1[1] = 0;
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( !v2 && __strex(1u, v1) );
  if ( v2 )
    result = sub_7D37E4();
  else
    result = KeAbPostRelease((unsigned int)v1);
  return result;
}
