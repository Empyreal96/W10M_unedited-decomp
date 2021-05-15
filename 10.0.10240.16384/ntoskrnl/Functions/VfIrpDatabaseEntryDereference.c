// VfIrpDatabaseEntryDereference 
 
unsigned int *__fastcall VfIrpDatabaseEntryDereference(unsigned int *result, int a2, int a3, int a4)
{
  unsigned int *v4; // r5
  int v5; // r3
  unsigned int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r1
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = result;
  if ( a2 == 1 )
  {
    v5 = result[4] - 1;
    result[4] = v5;
    if ( !v5 )
    {
      ViIrpDatabaseAcquireLockExclusive(v9);
      v6 = *v4;
      ((void (__fastcall *)(unsigned int *, unsigned int, int))v4[8])(v4, *v4, 1);
      *v4 = 0;
      VfUtilAddressRangeRemoveCheckEmpty(
        (_DWORD *)(ViIrpDatabaseAddressRanges + 8 * (unsigned __int8)(-125 * (v6 >> 12))),
        v6);
      result = (unsigned int *)ViIrpDatabaseReleaseLockExclusive(LOBYTE(v9[0]));
    }
  }
  __dmb(0xBu);
  v7 = v4 + 3;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 - 1, v7) );
  __dmb(0xBu);
  return result;
}
