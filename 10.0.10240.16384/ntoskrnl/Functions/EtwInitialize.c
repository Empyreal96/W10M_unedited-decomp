// EtwInitialize 
 
unsigned int __fastcall EtwInitialize(unsigned int result)
{
  if ( result < 2 )
    return EtwpInitialize();
  if ( result == 2 )
    EtwpFileSystemReady = 1;
  return result;
}
