// MiRemoveUnusedSubsection 
 
int __fastcall MiRemoveUnusedSubsection(int a1)
{
  int result; // r0
  unsigned int v3; // r1
  int v4; // r6
  _DWORD *v5; // r1
  __int64 v6; // kr00_8
  unsigned int v7; // r0

  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5207BC();
  do
    v3 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
  while ( __strex(v3 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
  while ( 1 )
  {
    v4 = dword_632D80;
    if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_632D80 & 0x40000000) == 0 )
    {
      do
        v7 = __ldrex((unsigned int *)&dword_632D80);
      while ( v7 == v4 && __strex(v4 | 0x40000000, (unsigned int *)&dword_632D80) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v5 = (_DWORD *)(a1 + 52);
  v6 = *(_QWORD *)(a1 + 52);
  if ( *(_DWORD *)(v6 + 4) != a1 + 52 || *(_DWORD **)HIDWORD(v6) != v5 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v6) = v6;
  *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  *(_WORD *)(a1 + 18) &= 0xFFF7u;
  *v5 = v5;
  *(_DWORD *)(a1 + 56) = a1 + 52;
  result = MI_UNUSED_SUBSECTIONS_COUNT_REMOVE(a1);
  if ( (dword_682604 & 0x10000) != 0 )
    return ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
  __dmb(0xBu);
  dword_632D80 = 0;
  return result;
}
