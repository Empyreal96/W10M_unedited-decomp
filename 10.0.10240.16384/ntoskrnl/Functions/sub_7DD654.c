// sub_7DD654 
 
void sub_7DD654()
{
  int *v0; // r6
  int v1; // r7
  int v2; // r8
  int v3; // r9

  if ( *v0 )
  {
    *(_DWORD *)(*v0 + 8) = v3;
    FsRtlFreeExtraCreateParameter(*v0);
    *v0 = v3;
  }
  if ( v2 )
  {
    FsRtlFreeExtraCreateParameterList();
    IoClearIrpExtraCreateParameter(v1);
    JUMPOUT(0x6EAE4C);
  }
  JUMPOUT(0x6EAE4E);
}
