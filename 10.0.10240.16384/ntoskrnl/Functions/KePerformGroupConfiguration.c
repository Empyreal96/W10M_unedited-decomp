// KePerformGroupConfiguration 
 
int KePerformGroupConfiguration()
{
  byte_6836A1 &= 0xF9u;
  byte_6836A0 = 0;
  word_6376C4 = 0;
  KiPerformGroupConfiguration();
  return KiCommitNodeAssignment((int)&ExNode0);
}
