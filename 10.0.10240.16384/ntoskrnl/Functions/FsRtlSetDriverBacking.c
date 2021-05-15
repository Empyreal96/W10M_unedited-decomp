// FsRtlSetDriverBacking 
 
int __fastcall FsRtlSetDriverBacking(int a1, char a2)
{
  int result; // r0

  result = 0;
  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 44) )
      result = MmBackSystemImageWithPagefile();
    else
      result = -1073741213;
  }
  return result;
}
