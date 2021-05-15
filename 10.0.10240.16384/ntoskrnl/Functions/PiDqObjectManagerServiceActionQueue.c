// PiDqObjectManagerServiceActionQueue 
 
int __fastcall PiDqObjectManagerServiceActionQueue(int a1)
{
  unsigned __int8 *v1; // r8
  int v2; // r2
  int v3; // r3
  int v4; // r0
  unsigned int v5; // r2

  v1 = (unsigned __int8 *)(a1 + 56);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite(a1, 1, v2, v3);
  KeAbPreAcquire((unsigned int)v1, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex(v1);
  while ( __strex(v5 & 0xFE, v1) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    JUMPOUT(0x7C76DA);
  return sub_7C76D0(v4);
}
