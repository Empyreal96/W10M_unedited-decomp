// BgConsoleDestroyInterface 
 
int __fastcall BgConsoleDestroyInterface(void **a1)
{
  BgpFwAcquireLock((unsigned int)a1);
  if ( a1 == &BgpConsoleInterface && dword_61036C )
  {
    BgpDisplayCharacterDestroyContext();
    dword_61036C = 0;
  }
  return BgpFwReleaseLock();
}
