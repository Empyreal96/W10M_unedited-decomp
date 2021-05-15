// KeEnableProfiling 
 
int __fastcall KeEnableProfiling(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned __int64 v5; // r6
  _BYTE *v9; // r0
  _BYTE *v10; // r4
  unsigned __int8 *v11; // r9
  unsigned int v12; // r3
  __int64 v13; // r0
  unsigned int v14; // r3

  v5 = __PAIR64__(a3, a4);
  if ( (a2 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  if ( *(_DWORD *)(a1 + 236) )
    return -1073741053;
  v9 = (_BYTE *)ExAllocatePoolWithQuotaTag(0x208u, 0x1A8u, 1718579792);
  v10 = v9;
  if ( !v9 )
    return -1073741801;
  memset(v9, 0, 424);
  *((_DWORD *)v10 + 2) = a5;
  *((_DWORD *)v10 + 3) = a2;
  *((_DWORD *)v10 + 8) = HIDWORD(v5);
  *((_DWORD *)v10 + 9) = v5;
  *(_DWORD *)(a1 + 236) = v10;
  __dmb(0xBu);
  v11 = (unsigned __int8 *)(a1 + 2);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 1, v11) );
  __dmb(0xBu);
  LODWORD(v13) = KeUpdateTotalCyclesCurrentThread(a1, 0);
  *((_QWORD *)v10 + 3) = v13;
  if ( (a2 & 1) != 0 || v5 )
  {
    KiBeginCounterAccumulation(a1, 0);
    __dmb(0xBu);
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 | 2, v11) );
    __dmb(0xBu);
  }
  return 0;
}
