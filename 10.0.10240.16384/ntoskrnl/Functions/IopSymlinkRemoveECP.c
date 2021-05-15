// IopSymlinkRemoveECP 
 
int __fastcall IopSymlinkRemoveECP(int a1, int a2)
{
  return FsRtlRemoveExtraCreateParameter(a1, IopSymlinkECPGuid, a2, 0);
}
