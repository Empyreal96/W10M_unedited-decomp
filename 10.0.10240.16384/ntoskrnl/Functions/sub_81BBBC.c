// sub_81BBBC 
 
void sub_81BBBC()
{
  int v0; // r0
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r1
  __int16 v4; // r3

  v0 = IopGetFsRegistrationInProgress();
  if ( v0 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = *(_WORD *)(v3 + 0x134) + 1;
    *(_WORD *)(v3 + 308) = v4;
    if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
      KiCheckForKernelApcDelivery(v0);
    JUMPOUT(0x7BBD38);
  }
  ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v1, v2);
  JUMPOUT(0x7BBCE6);
}
