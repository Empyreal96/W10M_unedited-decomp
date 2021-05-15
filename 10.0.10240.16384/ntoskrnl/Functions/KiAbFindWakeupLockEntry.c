// KiAbFindWakeupLockEntry 
 
int __fastcall KiAbFindWakeupLockEntry(unsigned int a1, int a2, int a3, int a4)
{
  int v6; // r9
  int result; // r0
  int v8; // r2
  int v9; // r10
  unsigned int v10; // r3
  unsigned int v11; // r2
  int v12; // r5
  unsigned __int64 *v13; // lr
  unsigned __int64 v14; // r2
  unsigned __int64 *v15; // r6
  int v16; // [sp-18h] [bp-40h] BYREF
  unsigned __int64 *v17; // [sp+0h] [bp-28h]
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]

  v18 = a3;
  v19 = a4;
  v17 = (unsigned __int64 *)&v16;
  if ( KeAbThreadAreAllEntriesFree(a2) )
    return 0;
  v6 = a1 & 0x7FFFFFFC;
  if ( MmIsSessionAddress(a1) )
    return sub_50ECC4();
  v8 = *(char *)(a2 + 484);
  result = 0;
  __dmb(0xBu);
  v9 = (*(char *)(a2 + 810) | v8) ^ 0x3F;
  while ( 1 )
  {
    v10 = __clz(v9);
    v11 = 31 - v10;
    v18 = 31 - v10;
    if ( 1 == (unsigned __int8)(v10 >> 5) )
      break;
    v9 &= ~(1 << v11);
    v12 = a2 + 48 * v11;
    v13 = (unsigned __int64 *)(v12 + 504);
    if ( (*(_DWORD *)(v12 + 504) & 0x7FFFFFFC) == v6 )
    {
      __dmb(0xBu);
      result = 0;
      do
        v14 = __ldrexd(v13);
      while ( !v14 && __strexd(0i64, v13) );
      v15 = v17;
      *v17 = v14;
      __dmb(0xBu);
      if ( (*(_BYTE *)(v12 + 501) & 1) != 0 && (*(_DWORD *)v15 & 0x7FFFFFFC) == v6 && *((_DWORD *)v15 + 1) == -1 )
        return v12 + 488;
    }
  }
  return result;
}
