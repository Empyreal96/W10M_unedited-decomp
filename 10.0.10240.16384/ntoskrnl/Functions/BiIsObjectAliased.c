// BiIsObjectAliased 
 
int __fastcall BiIsObjectAliased(unsigned int a1, _DWORD *a2)
{
  *a2 = 0;
  if ( !memcmp(a1, (unsigned int)&GUID_CURRENT_BOOT_ENTRY, 16) )
    return sub_813C64();
  if ( !memcmp(a1, (unsigned int)&GUID_DEFAULT_BOOT_ENTRY, 16) )
    JUMPOUT(0x813C68);
  return 0;
}
