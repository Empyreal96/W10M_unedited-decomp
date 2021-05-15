// PopCalculateTotalHwDripsResidency 
 
void __fastcall PopCalculateTotalHwDripsResidency(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  if ( ((unsigned int)a1 & HIDWORD(a1)) != -1 && ((unsigned int)a2 & HIDWORD(a2)) != -1 )
  {
    if ( a2 < a1 )
      sub_50F834();
    else
      _rt_udiv64(10i64, a2 - a1);
  }
}
