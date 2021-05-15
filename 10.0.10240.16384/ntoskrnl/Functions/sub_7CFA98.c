// sub_7CFA98 
 
void sub_7CFA98()
{
  int v0; // r7
  unsigned __int8 *v1; // r4
  int v2; // r6
  unsigned int v3; // r2

  v1 = (unsigned __int8 *)(v0 + 160);
  v2 = KeAbPreAcquire(v0 + 160, 0, 0);
  KfRaiseIrql(1);
  do
    v3 = __ldrex(v1);
  while ( __strex(v3 & 0xFE, v1) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    ExpAcquireFastMutexContended(v0 + 160, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  JUMPOUT(0x789416);
}
