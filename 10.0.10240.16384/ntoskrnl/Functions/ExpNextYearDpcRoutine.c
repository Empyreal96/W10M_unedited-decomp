// ExpNextYearDpcRoutine 
 
void __fastcall ExpNextYearDpcRoutine(int a1, unsigned int *a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r2

  __dmb(0xBu);
  do
  {
    v2 = __ldrex(a2);
    v3 = v2 + 1;
  }
  while ( __strex(v3, a2) );
  __dmb(0xBu);
  if ( v3 == 1 )
    ExQueueWorkItem(&ExpNextYearWorkItem, 1);
}
