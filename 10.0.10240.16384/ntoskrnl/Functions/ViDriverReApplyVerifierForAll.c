// ViDriverReApplyVerifierForAll 
 
unsigned __int16 *__fastcall ViDriverReApplyVerifierForAll(unsigned __int16 *result)
{
  unsigned __int16 *v1; // r5
  unsigned __int16 *v2; // r4

  v1 = result;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    v2 = *(unsigned __int16 **)result;
    if ( *(unsigned __int16 **)result != result )
    {
      do
      {
        result = (unsigned __int16 *)RtlEqualUnicodeString((unsigned __int16 *)&VfKernelImageName, v2 + 22, 1);
        if ( !result && (*((_DWORD *)v2 + 13) & 0x2000000) != 0 )
        {
          VfDriverLock();
          if ( VfSuspectDriversIsLoaded(v2 + 22) )
            VfThunkApplyDriverAddedThunks(v2);
          __dmb(0xBu);
          ViDriversLoadLockOwner = 0;
          result = (unsigned __int16 *)KeReleaseMutex((int)&ViDriversLoadLock);
        }
        v2 = *(unsigned __int16 **)v2;
      }
      while ( v2 != v1 );
    }
  }
  return result;
}
