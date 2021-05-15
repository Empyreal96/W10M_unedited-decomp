// sub_7CE214 
 
void sub_7CE214()
{
  int v0; // r4
  unsigned int v1; // r1
  unsigned int v2; // r1
  _WORD *v3; // r3

  __dmb(0xBu);
  do
  {
    v1 = __ldrex(&KsepHistoryErrorsIndex);
    v2 = v1 + 1;
  }
  while ( __strex(v2, &KsepHistoryErrorsIndex) );
  __dmb(0xBu);
  v3 = &KsepHistoryErrors[4 * (v2 & 0x3F)];
  *((_DWORD *)v3 + 1) = v0;
  v3[1] = 9;
  *v3 = 494;
  if ( (KsepDebugFlag & 2) != 0 )
    KsepDebugPrint(0, (int)"KSE: ZwOpenFile failed opening DB file!\n");
  JUMPOUT(0x773AF4);
}
