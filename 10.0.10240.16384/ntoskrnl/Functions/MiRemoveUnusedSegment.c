// MiRemoveUnusedSegment 
 
int __fastcall MiRemoveUnusedSegment(__int64 a1)
{
  _DWORD *v1; // r8
  unsigned int v2; // r1
  int v3; // r6
  _DWORD *v4; // r2
  unsigned int v5; // r0

  v1 = (_DWORD *)a1;
  if ( (*(_DWORD *)(a1 + 28) & 0x8000000) != 0 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      LODWORD(a1) = sub_546B30();
    }
    else
    {
      do
        v2 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
      while ( __strex(v2 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
      __dmb(0xBu);
      if ( v2 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
      while ( 1 )
      {
        v3 = dword_632D80;
        if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632D80 & 0x40000000) == 0 )
        {
          do
            v5 = __ldrex((unsigned int *)&dword_632D80);
          while ( v5 == v3 && __strex(v3 | 0x40000000, (unsigned int *)&dword_632D80) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      if ( (v1[7] & 0x40000) != 0 )
        --dword_63FA64;
      v4 = v1 + 1;
      a1 = *(_QWORD *)(v1 + 1);
      if ( *(_DWORD **)(a1 + 4) != v1 + 1 || *(_DWORD **)HIDWORD(a1) != v4 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(a1) = a1;
      *(_DWORD *)(a1 + 4) = HIDWORD(a1);
      v1[7] &= 0xF7FFFFFF;
      *v4 = v4;
      v1[2] = v1 + 1;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        LODWORD(a1) = ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
      }
      else
      {
        __dmb(0xBu);
        dword_632D80 = 0;
      }
    }
  }
  return a1;
}
