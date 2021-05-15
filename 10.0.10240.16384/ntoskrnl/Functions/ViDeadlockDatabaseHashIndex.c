// ViDeadlockDatabaseHashIndex 
 
unsigned int __fastcall ViDeadlockDatabaseHashIndex(unsigned int a1)
{
  return (a1 >> 12)
       - 1023
       * ((unsigned int)((((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                       + ((unsigned int)((a1 >> 12) - (((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
}
