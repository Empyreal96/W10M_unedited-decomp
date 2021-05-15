// PopPowerRequestFindEntryById 
 
int __fastcall PopPowerRequestFindEntryById(int a1, int a2, int a3)
{
  _DWORD v4[2]; // [sp+0h] [bp-8h] BYREF

  v4[0] = a3;
  v4[1] = a1;
  return RtlLookupElementGenericTableAvl((int)&PopPowerRequestTable, (int)v4);
}
