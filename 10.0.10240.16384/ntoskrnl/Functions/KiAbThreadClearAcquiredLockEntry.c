// KiAbThreadClearAcquiredLockEntry 
 
int __fastcall KiAbThreadClearAcquiredLockEntry(int a1, int a2, int a3)
{
  int v3; // lr
  int v4; // r1
  int v6; // r5
  unsigned int v7; // r3
  unsigned int v8; // r4
  int v9; // r2
  unsigned int v11; // r3

  v3 = a2 & 0x7FFFFFFC;
  v4 = *(char *)(a1 + 484);
  __dmb(0xBu);
  v6 = (v4 | *(char *)(a1 + 810)) ^ 0x3F;
  v7 = __clz(v6);
  v8 = 31 - v7;
  if ( 1 == (unsigned __int8)(v7 >> 5) )
    return 0;
  do
  {
    v6 &= ~(1 << v8);
    v9 = a1 + 48 * v8;
    if ( (*(_BYTE *)(v9 + 502) & 1) != 0
      && (*(_DWORD *)(v9 + 504) & 1) == 0
      && (*(_DWORD *)(v9 + 504) & 0x7FFFFFFC) == v3
      && *(_DWORD *)(v9 + 508) == a3 )
    {
      *(_BYTE *)(v9 + 502) &= 0xFEu;
      if ( *(_DWORD *)(v9 + 504) )
        return v9 + 488;
    }
    v11 = __clz(v6);
    v8 = 31 - v11;
  }
  while ( 1 != (unsigned __int8)(v11 >> 5) );
  return 0;
}
