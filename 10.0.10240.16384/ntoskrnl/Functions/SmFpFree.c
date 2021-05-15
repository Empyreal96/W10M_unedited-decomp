// SmFpFree 
 
int __fastcall SmFpFree(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r4
  int v7; // r6
  unsigned int *v8; // r8
  int v9; // r3
  int result; // r0
  unsigned int v11; // r2

  v5 = a4;
  if ( a2 < 4 )
  {
    v7 = 0;
  }
  else
  {
    v5 = *(_DWORD *)(a4 + 12);
    v7 = a4;
  }
  v8 = (unsigned int *)(a1 + 60);
  v9 = *(_DWORD *)(a1 + 60);
  __dmb(0xBu);
  if ( v9 == a3 && (result = SmpFpReleaseResource(a1, a2, v5)) != 0 )
  {
    if ( a2 >= 4 )
      result = MmUnmapReservedMapping(v5, 1834118515, v7);
    if ( !*(_BYTE *)(a1 + 45) )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v8);
      while ( __strex(0, v8) );
      __dmb(0xBu);
      result = KeSetEvent(a1 + 4, 0, 0);
    }
  }
  else if ( a2 < 4 )
  {
    if ( a2 == 2 )
    {
      result = SmKmFreeMdlForLock(v5);
    }
    else if ( a2 == 3 )
    {
      result = SmAcquireReleaseCharges(*(unsigned __int16 *)(a1 + 54) << 12, 1, 1);
    }
    else
    {
      result = ExFreePoolWithTag(v5);
    }
  }
  else
  {
    result = (int)MmUnmapLockedPages(v5, v7, a3);
  }
  return result;
}
