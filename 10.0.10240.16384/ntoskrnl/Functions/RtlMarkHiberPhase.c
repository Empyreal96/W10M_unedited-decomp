// RtlMarkHiberPhase 
 
char *RtlMarkHiberPhase()
{
  PoSetHiberRange(0, 0x10000, XpressHashFunction, (const void *)0x600, 1936879704);
  return PoSetHiberRange(0, 0x10000, XpressHighBitIndexTable, (const void *)0x100, 1936879704);
}
