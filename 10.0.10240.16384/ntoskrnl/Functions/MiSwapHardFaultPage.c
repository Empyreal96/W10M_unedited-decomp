// MiSwapHardFaultPage 
 
int __fastcall MiSwapHardFaultPage(int *a1, int a2, int a3)
{
  int v5; // r2
  int result; // r0
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int *v10; // r2
  int v11; // r3

  v5 = *a1 & 0xFFF | (((a3 - MmPfnDatabase) / 24) << 12);
  if ( (unsigned int)(a1 + 0x10000000) <= 0x3FFFFF )
    return sub_511DA8();
  *a1 = v5;
  v7 = (unsigned __int8 *)(a3 + 15);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v11 = *(_DWORD *)(a3 + 12);
      __dmb(0xBu);
    }
    while ( v11 < 0 );
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
  }
  MiCopyPfnEntry(a3, a2);
  if ( (*(_BYTE *)(a2 + 23) & 7) == 3 )
    *(_DWORD *)(a3 + 20) = *(_DWORD *)(a3 + 20) & 0xF8FFFFFF | 0x3000000;
  *(_DWORD *)(a3 + 12) &= 0xC0000000;
  *(_DWORD *)(a2 + 12) |= 0x40000000u;
  v9 = *(_DWORD *)(a2 + 8) & 0xFFFFFFEF;
  *(_DWORD *)(a2 + 8) = v9;
  *(_DWORD *)(a2 + 8) = v9 & 0xFFFFFFF7;
  if ( MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(a2) )
    MiPfnReferenceCountIsZero(a2, (a2 - MmPfnDatabase) / 24);
  else
    *(_WORD *)(a3 + 16) = 1;
  __dmb(0xBu);
  v10 = (unsigned int *)(a2 + 12);
  do
    result = __ldrex(v10);
  while ( __strex(result & 0x7FFFFFFF, v10) );
  return result;
}
