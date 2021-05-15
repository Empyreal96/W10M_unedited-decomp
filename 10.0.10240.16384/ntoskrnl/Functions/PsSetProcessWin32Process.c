// PsSetProcessWin32Process 
 
int __fastcall PsSetProcessWin32Process(int a1)
{
  unsigned int v1; // r6
  unsigned __int8 *v2; // r7
  int v3; // r0
  unsigned int v4; // r4

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = (unsigned __int8 *)(a1 + 168);
  v3 = KeAbPreAcquire(a1 + 168, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    JUMPOUT(0x7EA636);
  return sub_7EA62C(v3);
}
