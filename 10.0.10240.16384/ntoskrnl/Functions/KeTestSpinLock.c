// KeTestSpinLock 
 
int __fastcall KeTestSpinLock(_DWORD *a1)
{
  if ( !*a1 )
    return 1;
  __dmb(0xAu);
  __yield();
  return 0;
}
