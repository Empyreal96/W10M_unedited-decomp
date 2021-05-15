// RawCreate 
 
int __fastcall RawCreate(int a1)
{
  unsigned __int8 *v1; // r8
  int v2; // r0
  unsigned int v3; // r4

  v1 = (unsigned __int8 *)(a1 + 160);
  KeAbPreAcquire(a1 + 160, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex(v1);
  while ( __strex(v3 & 0xFE, v1) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    JUMPOUT(0x7CFB30);
  return sub_7CFB24(v2);
}
