// MiCreateMdl 
 
int __fastcall MiCreateMdl(int a1)
{
  int v2; // r0
  int v3; // r4

  v2 = ExAllocatePoolWithTag(512, a1, 2021158221);
  if ( !v2 )
    JUMPOUT(0x51AA00);
  v3 = IoAllocateMdl(v2, a1, 0);
  if ( !v3 )
    return sub_51A9F8();
  MmBuildMdlForNonPagedPool();
  *(_WORD *)(v3 + 6) |= 0x4000u;
  return v3;
}
