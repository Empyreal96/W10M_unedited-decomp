// PnpIsNullGuid 
 
BOOL __fastcall PnpIsNullGuid(int a1)
{
  return RtlCompareMemory((unsigned __int8 *)&NullGuid, a1, 16) == 16;
}
