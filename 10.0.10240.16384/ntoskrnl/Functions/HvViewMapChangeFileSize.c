// HvViewMapChangeFileSize 
 
int __fastcall HvViewMapChangeFileSize(int a1)
{
  int v1; // r4
  unsigned __int8 *v2; // r6
  int v3; // r0
  unsigned int v4; // r5

  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  v2 = (unsigned __int8 *)(a1 + 4);
  v3 = KeAbPreAcquire(a1 + 4, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    JUMPOUT(0x7EA9D6);
  return sub_7EA9CC(v3);
}
