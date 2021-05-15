// RtlInitializeHistoryTable 
 
int __fastcall RtlInitializeHistoryTable(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  int *v5; // r6
  int result; // r0
  unsigned int v7; // r7
  unsigned int v8; // r2
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a4;
  v4 = 0;
  v5 = RtlpUnwindHistoryTable;
  do
  {
    result = RtlpFunctionAddressTableEntry(v4);
    if ( !result )
      break;
    if ( (void (__fastcall __noreturn *)(int))result == RtlRaiseStatus )
      byte_681BDD = v4;
    result = RtlLookupFunctionEntry(result, v9, 0);
    v7 = *(_DWORD *)result + v9[0];
    if ( (*(_DWORD *)(result + 4) & 3) == 0 )
      return sub_96E9BC();
    v8 = *(_DWORD *)result + 2 * ((*(_DWORD *)(result + 4) >> 2) & 0x7FF) + v9[0];
    v5[4] = v9[0];
    v5[5] = result;
    if ( v7 < dword_681BE0 )
      dword_681BE0 = v7;
    if ( v8 > dword_681BE4 )
      dword_681BE4 = v8;
    ++v4;
    v5 += 2;
  }
  while ( v4 < 0xC );
  RtlpUnwindHistoryTable[0] = v4;
  return result;
}
