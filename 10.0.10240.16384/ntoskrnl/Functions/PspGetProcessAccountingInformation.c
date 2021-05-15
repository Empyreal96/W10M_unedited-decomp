// PspGetProcessAccountingInformation 
 
int __fastcall PspGetProcessAccountingInformation(int a1)
{
  unsigned __int8 *v1; // r5
  unsigned int v2; // r2
  unsigned int v4; // r4

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(a1 + 188);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 2, v1) );
  __dmb(0xBu);
  if ( (unsigned __int8)(v2 & 2) >> 1 )
    return 0;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)v1);
  while ( __strex(v4 & 0xFFFFFFDF, (unsigned int *)v1) );
  __dmb(0xBu);
  PsQueryStatisticsProcess();
  return 1;
}
