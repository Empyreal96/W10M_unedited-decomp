// sub_5376D4 
 
void sub_5376D4()
{
  int v0; // r5
  int v1; // r6
  unsigned int *v2; // r8
  unsigned int v3; // r1
  unsigned int *v4; // r2
  unsigned int v5; // r1

  __dmb(0xBu);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 - v0, v2) );
  __dmb(0xBu);
  v4 = (unsigned int *)(v1 + 288);
  do
    v5 = __ldrex(v4);
  while ( !v5 && __strex(3u, v4) );
  __dmb(0xBu);
  if ( !v5 )
    ExQueueWorkItem((_DWORD *)(v1 + 272), 1);
  JUMPOUT(0x495098);
}
