// SmKmStoreHelperCleanup 
 
_DWORD *__fastcall SmKmStoreHelperCleanup(_DWORD *result)
{
  _DWORD *v1; // r4

  v1 = result;
  if ( *result )
  {
    SmKmStoreHelperSendCommand();
    KeWaitForSingleObject(*v1, 0, 0);
    result = (_DWORD *)ObfDereferenceObjectWithTag(*v1, 1953261124);
  }
  return result;
}
