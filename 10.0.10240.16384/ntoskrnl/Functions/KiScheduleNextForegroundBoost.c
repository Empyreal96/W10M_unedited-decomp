// KiScheduleNextForegroundBoost 
 
int __fastcall KiScheduleNextForegroundBoost(int result)
{
  int v1; // r6
  int v2; // r5
  unsigned int v3; // r1
  bool v4; // zf
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = result;
  if ( *(_DWORD *)(result + 816) == 1 )
  {
    v2 = 0;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = KiAcquireSpinLockInstrumented((int)&dword_624F00);
    }
    else
    {
      result = 1;
      do
        v3 = __ldrex((unsigned int *)&dword_624F00);
      while ( __strex(1u, (unsigned int *)&dword_624F00) );
      __dmb(0xBu);
      if ( v3 )
        result = KxWaitForSpinLockAndAcquire((unsigned int *)&dword_624F00);
    }
    if ( *(_DWORD *)(v1 + 816) == 1 )
    {
      result = dword_624EFC;
      v4 = dword_624EF8 == (_DWORD)&dword_624EF8;
      *(_DWORD *)(v1 + 816) = &dword_624EF8;
      *(_DWORD *)(v1 + 820) = result;
      if ( v4 )
        v2 = 1;
      if ( !v4 )
        v2 = 0;
      if ( *(int **)result != &dword_624EF8 )
        __fastfail(3u);
      *(_DWORD *)result = v1 + 816;
      dword_624EFC = v1 + 816;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseSpinLockInstrumented(&dword_624F00, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_624F00 = 0;
    }
    if ( v2 )
      result = KiInsertQueueDpc((int)&unk_624ED8, 0, 0, 0, 0);
  }
  return result;
}
