// MiReleasePageFileSpace 
 
int __fastcall MiReleasePageFileSpace(int a1, unsigned int a2, int a3, int a4)
{
  if ( (a2 & 0x400) != 0 )
    return 0;
  if ( (a2 & 0x10) != 0 )
  {
    if ( !a3 )
      a2 &= 0xFFFFFFF7;
  }
  else if ( !a3 || (a2 & 8) == 0 )
  {
    a2 = 0;
  }
  if ( !a2 )
    return 0;
  MiReleasePageFileInfo(a1, a2, 0, a4);
  return 1;
}
