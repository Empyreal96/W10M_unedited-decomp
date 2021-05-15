// sub_7D4CE0 
 
void sub_7D4CE0()
{
  _DWORD *v0; // r6
  _DWORD *v1; // r7

  if ( (*v0 & 2) != 0 )
  {
    IoSetTopLevelIrp(0);
    FsRtlReleaseFile(v1);
    *v0 &= 0xFFFFFFFD;
  }
  JUMPOUT(0x6D63E6);
}
