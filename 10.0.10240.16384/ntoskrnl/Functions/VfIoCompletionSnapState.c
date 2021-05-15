// VfIoCompletionSnapState 
 
int __fastcall VfIoCompletionSnapState(int a1)
{
  int result; // r0

  if ( ViIoCallbacksInitialized && (MmVerifierData & 0x10) != 0 )
    result = ViIoCallbackSnapState(a1);
  else
    result = 0;
  return result;
}
