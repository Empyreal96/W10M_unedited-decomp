// IopRemoveLegacyDeviceNode 
 
int __fastcall IopRemoveLegacyDeviceNode(int result)
{
  if ( !result )
    return sub_80D278(0, 0);
  if ( (*(_DWORD *)(result + 28) & 0x1000) == 0 )
    JUMPOUT(0x80D2A2);
  return result;
}
