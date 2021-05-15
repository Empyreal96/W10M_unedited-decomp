// InitMultiSessionSku 
 
int InitMultiSessionSku()
{
  int result; // r0

  if ( RtlpNumberOfInitialSessions == 1 )
    return sub_970224();
  MEMORY[0xFFFF92F0] |= 0x100u;
  return result;
}
