// IoRegisterFsRegistrationChangeMountAware 
 
int __fastcall IoRegisterFsRegistrationChangeMountAware(int a1, int a2, int a3)
{
  int result; // r0
  unsigned int v5; // r2

  result = FsRtlSetDriverBacking();
  if ( result >= 0 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    if ( !a3 )
      JUMPOUT(0x80C240);
    result = sub_80C200(&IopDatabaseResource);
  }
  return result;
}
