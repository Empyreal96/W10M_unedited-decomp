// ADD_MAP_REGISTERS 
 
int __fastcall ADD_MAP_REGISTERS(int result, unsigned int a2, int a3)
{
  int v5; // r7
  unsigned int *v6; // r4
  unsigned int v7; // r6
  unsigned int v8; // r8
  unsigned int *v9; // r4
  unsigned int v10; // r6

  v5 = result;
  __dmb(0xBu);
  v6 = (unsigned int *)(result + 88);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + a2, v6) );
  v8 = v7 + a2;
  __dmb(0xBu);
  v9 = (unsigned int *)(result + 84);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + a2, v9) );
  __dmb(0xBu);
  if ( a2 > *(_DWORD *)(result + 80) )
  {
    ViHalPreprocessOptions(&dword_618750, "Allocating too many map registers at a time: %x (max %x).", 12, a2);
    result = VfReportIssueWithOptions(230, 12, a2, *(_DWORD *)(v5 + 80), 0, &dword_618750);
  }
  if ( !a3 && v8 > *(_DWORD *)(v5 + 80) )
  {
    ViHalPreprocessOptions(&dword_618754, "Allocated too many map registers : %x (max %x).", 21, v8);
    result = VfReportIssueWithOptions(230, 21, v8, *(_DWORD *)(v5 + 80), 0, &dword_618754);
  }
  return result;
}
