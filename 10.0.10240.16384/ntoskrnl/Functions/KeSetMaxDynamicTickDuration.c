// KeSetMaxDynamicTickDuration 
 
int __fastcall KeSetMaxDynamicTickDuration(unsigned __int64 a1)
{
  unsigned int v1; // r4
  unsigned __int64 v2; // kr00_8

  v1 = HIDWORD(a1);
  if ( (unsigned int)KeMaximumIncrement < a1 )
  {
    LODWORD(a1) = KeMaximumIncrement;
    v1 = 0;
  }
  __dmb(0xBu);
  do
    v2 = __ldrexd((unsigned __int64 *)&KiMaxDynamicTickDuration);
  while ( __strexd(__PAIR64__(v1, a1), (unsigned __int64 *)&KiMaxDynamicTickDuration) );
  __dmb(0xBu);
  return a1;
}
