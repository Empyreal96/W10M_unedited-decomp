// KeStallWhileFrozen 
 
int KeStallWhileFrozen()
{
  return KiCheckStall(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0);
}
