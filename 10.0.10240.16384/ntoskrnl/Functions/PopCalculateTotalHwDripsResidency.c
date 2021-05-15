// PopCalculateTotalHwDripsResidency 
 
int __fastcall PopCalculateTotalHwDripsResidency(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // r0

  if ( ((unsigned int)a1 & HIDWORD(a1)) == -1 || ((unsigned int)a2 & HIDWORD(a2)) == -1 )
  {
    LODWORD(v3) = -1;
  }
  else if ( a2 < a1 )
  {
    LODWORD(v3) = sub_50F834();
  }
  else
  {
    LODWORD(v3) = _rt_udiv64(10i64, a2 - a1);
    if ( v3 > a3 )
      LODWORD(v3) = a3;
  }
  return v3;
}
