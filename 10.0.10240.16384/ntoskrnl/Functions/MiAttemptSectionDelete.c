// MiAttemptSectionDelete 
 
int __fastcall MiAttemptSectionDelete(_DWORD *a1, int a2, int a3)
{
  if ( !a1[3] )
    return sub_524FEC();
  if ( a3 )
    a1[7] |= 0x40000u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
  }
  else
  {
    __dmb(0xBu);
    a1[9] = 0;
  }
  KfLowerIrql(a2);
  return 0;
}
