// KsepStringTransform 
 
int __fastcall KsepStringTransform(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int result; // r0
  int v5; // r2
  unsigned __int16 v6; // r0
  int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r2
  _WORD *v10; // r3

  if ( !a1 )
    return sub_7CE728(0, 3);
  if ( !a2 )
  {
    __dmb(0xBu);
    do
    {
      v8 = __ldrex(&KsepHistoryErrorsIndex);
      v9 = v8 + 1;
    }
    while ( __strex(v9, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v10 = &KsepHistoryErrors[4 * (v9 & 0x3F)];
    *((_DWORD *)v10 + 1) = -1073740768;
    v10[1] = 3;
    LOBYTE(v10) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v9 & 0x3F)] = 801;
    if ( ((unsigned __int8)v10 & 4) != 0 )
      RtlAssert((int)"SourceString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 801, 0);
  }
  result = KsepStringDuplicate((int)a1, a2);
  if ( result >= 0 )
  {
    v5 = 0;
    if ( (*a1 & 0xFFFE) != 0 )
    {
      v6 = 0;
      do
      {
        v7 = *((_DWORD *)a1 + 1);
        if ( *(_WORD *)(v7 + 2 * v5) == 92 )
          *(_WORD *)(v7 + 2 * v5) = 33;
        v5 = ++v6;
      }
      while ( v6 < (unsigned int)(*a1 >> 1) );
    }
    result = 0;
  }
  return result;
}
