// IopGetEnvironmentVariableSysEnv 
 
int __fastcall IopGetEnvironmentVariableSysEnv(int a1, int a2, unsigned __int16 *a3)
{
  unsigned int v3; // r5
  int v5; // r3

  v3 = 2 * (wcslen(a3) + 1);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v5 = 40;
    else
      v5 = 32;
    if ( !ExAllocatePoolWithTagPriority(1, v3 + 20, 538996553, v5) )
      JUMPOUT(0x6D95E4);
    JUMPOUT(0x7D5904);
  }
  return sub_7D58D8();
}
