// MiTrimSegmentCache 
 
int MiTrimSegmentCache()
{
  int result; // r0
  int v1; // r4

  result = dword_632E18;
  if ( !dword_632E18 )
  {
    v1 = 0;
    if ( (int *)dword_63FA68 != &dword_63FA68 )
    {
      dword_632E18 = 31;
      return KeSetEvent((int)&unk_63F9F8, 0, 0);
    }
    if ( (int *)dword_63FA70 != &dword_63FA70 )
    {
      v1 = 1;
      result = 31;
      dword_632E18 = 31;
    }
    if ( (unsigned int)dword_632E14 < 0x4000 && !v1 )
    {
      if ( result )
        return result;
      v1 = 1;
      dword_632E18 = 31;
    }
    if ( v1 == 1 )
      return KeSetEvent((int)&unk_63F9F8, 0, 0);
  }
  return result;
}
