// PopThermalWorker 
 
int __fastcall PopThermalWorker(int a1)
{
  unsigned __int8 *v2; // r8
  unsigned int v3; // r2
  unsigned int v4; // r2

  KeQueryInterruptTime();
  v2 = (unsigned __int8 *)(a1 + 320);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  KeAbPreAcquire(a1 + 320, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    JUMPOUT(0x814894);
  return sub_814888();
}
