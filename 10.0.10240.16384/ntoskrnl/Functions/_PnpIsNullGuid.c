// _PnpIsNullGuid 
 
BOOL __fastcall PnpIsNullGuid(int a1)
{
  return RtlCompareMemory((unsigned __int8 *)dword_401DFC, a1, 16) == 16;
}
