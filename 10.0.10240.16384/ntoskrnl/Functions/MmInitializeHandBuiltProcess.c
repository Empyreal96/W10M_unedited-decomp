// MmInitializeHandBuiltProcess 
 
int __fastcall MmInitializeHandBuiltProcess(int a1)
{
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 24);
  if ( (BYTE2(MiFlags) & 3) != 3 )
    JUMPOUT(0x81B1CC);
  return sub_81B1A8();
}
