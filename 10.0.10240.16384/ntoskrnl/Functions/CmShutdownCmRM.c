// CmShutdownCmRM 
 
int __fastcall CmShutdownCmRM(int a1, int a2, unsigned int *a3, int a4)
{
  unsigned int v6; // r4

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 32) )
    {
      __dmb(0xBu);
      a3 = (unsigned int *)(a1 + 32);
      do
        v6 = __ldrex(a3);
      while ( __strex(v6 - 1, a3) );
      __dmb(0xBu);
      if ( !*(_DWORD *)(a1 + 32) )
        CmpStopRMLog();
    }
  }
  return CmpRunDownCmRM(a1, a2, a3, a4);
}
