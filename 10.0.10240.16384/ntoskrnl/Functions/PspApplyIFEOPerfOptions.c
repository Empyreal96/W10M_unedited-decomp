// PspApplyIFEOPerfOptions 
 
unsigned int __fastcall PspApplyIFEOPerfOptions(unsigned int result, _DWORD *a2, char a3)
{
  int v4; // r7
  unsigned int v5; // r5
  unsigned int *v6; // r6
  unsigned int v7; // lr
  unsigned int v8; // r1
  unsigned int v9; // r6
  unsigned int *v10; // r5
  unsigned int v11; // lr
  unsigned int v12; // r1
  unsigned int v13; // r3

  v4 = result;
  if ( (*a2 & 1) != 0 )
  {
    v5 = a2[2];
    if ( v5 < 4 )
    {
      if ( v5 <= 2
        || (result = SeSinglePrivilegeCheck(
                       SeIncreaseBasePriorityPrivilege,
                       dword_9227C4,
                       a3,
                       (int)&SeIncreaseBasePriorityPrivilege),
            (result & 1) != 0) )
      {
        v6 = (unsigned int *)(v4 + 192);
        v7 = *(_DWORD *)(v4 + 192);
        __dmb(0xBu);
        do
        {
          result = v7;
          __dmb(0xBu);
          do
            v8 = __ldrex(v6);
          while ( v8 == v7 && __strex(v7 & 0xC7FFFFFF | (v5 << 27), v6) );
          v7 = v8;
          __dmb(0xBu);
        }
        while ( v8 != result );
      }
    }
  }
  if ( (*a2 & 2) != 0 )
  {
    v9 = a2[3];
    result = MmGetDefaultPagePriority();
    if ( v9 < result )
    {
      v10 = (unsigned int *)(v4 + 188);
      v11 = *(_DWORD *)(v4 + 188);
      __dmb(0xBu);
      do
      {
        result = v11;
        __dmb(0xBu);
        do
          v12 = __ldrex(v10);
        while ( v12 == v11 && __strex(v11 & 0xFFFF8FFF | (v9 << 12), v10) );
        v11 = v12;
        __dmb(0xBu);
      }
      while ( v12 != result );
    }
  }
  if ( (*a2 & 4) != 0 )
  {
    v13 = a2[4];
    if ( v13 <= 0xFF )
      result = PspSetProcessPriorityClass(v4, (unsigned __int8)v13);
  }
  return result;
}
