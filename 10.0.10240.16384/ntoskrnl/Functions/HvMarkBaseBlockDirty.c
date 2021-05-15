// HvMarkBaseBlockDirty 
 
int __fastcall HvMarkBaseBlockDirty(int result, unsigned __int64 a2)
{
  unsigned __int64 v3; // [sp+0h] [bp-18h] BYREF

  v3 = a2;
  if ( !*(_BYTE *)(result + 123) && !*(_DWORD *)(result + 44) )
    return sub_7D1478(MEMORY[0xFFFF93B0], MEMORY[0xFFFF93B4]);
  *(_BYTE *)(result + 123) = 1;
  if ( (*(_DWORD *)(result + 92) & 2) == 0 )
  {
    v3 = *(_QWORD *)(result + 3240)
       + (unsigned int)CmpLazyFlushIntervalInSeconds * (unsigned __int64)(unsigned int)dword_989680;
    result = CmpArmLazyWriter(0, (__int64 *)&v3, 0);
  }
  return result;
}
