// ExpUuidSaveSequenceNumberIf 
 
int ExpUuidSaveSequenceNumberIf()
{
  int result; // r0

  result = 0;
  if ( ExpUuidSequenceNumberNotSaved == 1 )
  {
    result = ExpUuidSaveSequenceNumber(ExpUuidSequenceNumber);
    if ( result >= 0 )
      ExpUuidSequenceNumberNotSaved = 0;
  }
  return result;
}
