// KiDispatchInterrupt 
 
int __fastcall KiDispatchInterrupt(char a1)
{
  unsigned int v1; // r3
  int v3; // [sp+0h] [bp-8h] BYREF

  v1 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __disable_irq();
  *(_BYTE *)(*(_DWORD *)(v1 + 4) + 134) = a1;
  if ( (*(_BYTE *)(v1 + 1756) & 0x3F) == 0 )
    JUMPOUT(0x42018C);
  return KxRetireDpcList(v1, &v3);
}
