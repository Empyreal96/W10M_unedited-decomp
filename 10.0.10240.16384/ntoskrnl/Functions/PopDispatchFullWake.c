// PopDispatchFullWake 
 
void __fastcall PopDispatchFullWake(int a1, int a2)
{
  unsigned int v2; // r1
  int v3; // r0
  int v4; // r1

  if ( byte_61EC61 != 3 )
  {
    PopNotifyConsoleUserPresent(0, a2, 9);
    if ( (PopFullWake & 3) == 2 )
    {
      if ( (PoDebug & 8) != 0 )
        DbgPrint("PopEventDispatch: full wake\n");
      __dmb(0xBu);
      do
        v2 = __ldrex((unsigned int *)&PopFullWake);
      while ( __strex(v2 | 1, (unsigned int *)&PopFullWake) );
      __dmb(0xBu);
      PopEventCalloutDispatch(0, 0);
      v3 = PopAcquirePolicyLock();
      PopInitSIdle(v3, v4);
      PopReleasePolicyLock();
    }
  }
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
}
