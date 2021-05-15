// KsepStringConcatenate 
 
int __fastcall KsepStringConcatenate(int a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  unsigned int v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r8
  int v12; // r4
  unsigned int v13; // r7
  int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r2
  _WORD *v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r2
  _WORD *v20; // r3

  if ( !a1 )
    return sub_7CE634(-1073740768, &KsepHistoryErrorsIndex);
  if ( !a2 )
  {
    __dmb(0xBu);
    do
    {
      v15 = __ldrex(&KsepHistoryErrorsIndex);
      v16 = v15 + 1;
    }
    while ( __strex(v16, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v17 = &KsepHistoryErrors[4 * (v16 & 0x3F)];
    *((_DWORD *)v17 + 1) = -1073740768;
    v17[1] = 3;
    LOBYTE(v17) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v16 & 0x3F)] = 720;
    if ( ((unsigned __int8)v17 & 4) != 0 )
      RtlAssert((int)"LeftString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 720, 0);
  }
  if ( !a3 )
  {
    __dmb(0xBu);
    do
    {
      v18 = __ldrex(&KsepHistoryErrorsIndex);
      v19 = v18 + 1;
    }
    while ( __strex(v19, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v20 = &KsepHistoryErrors[4 * (v19 & 0x3F)];
    v20[1] = 3;
    *((_DWORD *)v20 + 1) = -1073740768;
    LOBYTE(v20) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v19 & 0x3F)] = 721;
    if ( ((unsigned __int8)v20 & 4) != 0 )
      RtlAssert((int)"RightString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 721, 0);
  }
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v9 = 2 * wcslen(a2);
  v10 = wcslen(a3);
  v11 = v10;
  if ( a4 )
    v12 = 2;
  else
    v12 = 0;
  v13 = v12 + 2 * v10 + v9;
  if ( v13 + 2 > 0xFFFF || v13 == -2 )
    return -2147483643;
  v14 = KsepPoolAllocatePaged(v13 + 2);
  if ( !v14 )
    return -1073741801;
  *(_DWORD *)(a1 + 4) = v14;
  memmove(v14, (int)a2, v9);
  if ( v12 )
    *(_WORD *)(*(_DWORD *)(a1 + 4) + 2 * (v9 >> 1)) = 92;
  memmove(*(_DWORD *)(a1 + 4) + 2 * ((v12 + v9) >> 1), (int)a3, 2 * v11);
  *(_WORD *)(*(_DWORD *)(a1 + 4) + 2 * (v13 >> 1)) = 0;
  *(_WORD *)(a1 + 2) = v13 + 2;
  *(_WORD *)a1 = v13;
  return 0;
}
