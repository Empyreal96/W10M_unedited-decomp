// PopPowerRequestDeleteEntryById 
 
int __fastcall PopPowerRequestDeleteEntryById(int a1, int a2, int a3)
{
  int result; // r0
  int v4; // r2
  int v5; // r3
  _DWORD v6[2]; // [sp+0h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a1;
  result = RtlLookupElementGenericTableAvl((int)&PopPowerRequestTable, (int)v6);
  if ( result )
    result = RtlDeleteElementGenericTableAvl((int)&PopPowerRequestTable, result, v4, v5);
  return result;
}
