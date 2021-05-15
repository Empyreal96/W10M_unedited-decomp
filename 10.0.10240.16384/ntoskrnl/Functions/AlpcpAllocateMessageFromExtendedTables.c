// AlpcpAllocateMessageFromExtendedTables 
 
int __fastcall AlpcpAllocateMessageFromExtendedTables(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4
  unsigned int v5; // r2
  int v6; // r4
  unsigned int v7; // r5
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r0

  if ( !AlpcpSecondaryMessageTables )
  {
    v2 = (_BYTE *)ExAllocatePoolWithTag(1, 128, 1632136257);
    v3 = v2;
    if ( !v2 )
      return 0;
    memset(v2, 0, 128);
    *v3 = AlpcMessageTable;
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&AlpcpSecondaryMessageTables);
    while ( !v5 && __strex((unsigned int)v3, (unsigned int *)&AlpcpSecondaryMessageTables) );
    __dmb(0xBu);
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v3);
  }
  v6 = 1;
  while ( 1 )
  {
    v7 = *(_DWORD *)(AlpcpSecondaryMessageTables + 4 * v6);
    if ( !v7 )
    {
      v8 = ExCreateHandleTable(0, 0);
      v7 = v8;
      if ( !v8 )
        return 0;
      __dmb(0xBu);
      v9 = (unsigned int *)(AlpcpSecondaryMessageTables + 4 * v6);
      do
        v10 = __ldrex(v9);
      while ( !v10 && __strex(v8, v9) );
      __dmb(0xBu);
      if ( v10 )
      {
        ExpRemoveHandleTable(v8);
        ExpFreeHandleTable(v7);
        v7 = *(_DWORD *)(AlpcpSecondaryMessageTables + 4 * v6);
      }
    }
    v11 = ExCreateHandleEx(v7, a1, 0, 0);
    if ( v11 )
      break;
    if ( (unsigned int)++v6 >= 0x20 )
      return 0;
  }
  return v11 | (v6 << 26);
}
