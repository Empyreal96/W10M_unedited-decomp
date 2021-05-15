// SUBTRACT_MAP_REGISTERS 
 
int __fastcall SUBTRACT_MAP_REGISTERS(int a1, int a2)
{
  unsigned int *v3; // r2
  unsigned int v4; // r6
  int v5; // r5
  unsigned int *v6; // r2
  int result; // r0
  unsigned int v8; // r1

  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 88);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 - a2, v3) );
  __dmb(0xBu);
  v5 = v4 - a2;
  if ( (int)(v4 - a2) < 0 )
  {
    ViHalPreprocessOptions(&dword_61874C, "Freed too many map registers: -%x.", 5);
    VfReportIssueWithOptions(230, 5, -v5, 0, 0, &dword_61874C);
  }
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 116);
  result = 0;
  do
    v8 = __ldrex(v6);
  while ( __strex(0, v6) );
  __dmb(0xBu);
  return result;
}
