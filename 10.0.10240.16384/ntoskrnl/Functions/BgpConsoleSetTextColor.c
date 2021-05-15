// BgpConsoleSetTextColor 
 
int __fastcall BgpConsoleSetTextColor(int *a1, int *a2)
{
  BgpFwAcquireLock((unsigned int)a1);
  if ( a1 )
    dword_610354 = *a1;
  if ( a2 )
    dword_610358 = *a2;
  BgpFwReleaseLock();
  return 0;
}
