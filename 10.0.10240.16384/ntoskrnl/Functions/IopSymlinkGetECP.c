// IopSymlinkGetECP 
 
int __fastcall IopSymlinkGetECP(int a1, int a2)
{
  return FsRtlFindExtraCreateParameter(a1, IopSymlinkECPGuid, a2, 0);
}
