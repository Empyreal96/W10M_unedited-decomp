// -SmStReadThreadCtxCleanup@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU_SMKM_STORE_READ_THREAD_CTX@@@Z 
 
_DWORD *__fastcall SMKM_STORE<SM_TRAITS>::SmStReadThreadCtxCleanup(_DWORD *result)
{
  _DWORD *v1; // r4

  v1 = result;
  if ( *result )
  {
    KeSetEvent(result + 1, 0, 0);
    KeWaitForSingleObject(*v1, 0, 0);
    result = (_DWORD *)ObfDereferenceObjectWithTag(*v1, 1953261124);
  }
  return result;
}
