// sub_7CD2E0 
 
void sub_7CD2E0()
{
  unsigned int v0; // r4
  unsigned int v1; // r4
  _WORD *v2; // r2

  __dmb(0xBu);
  do
  {
    v0 = __ldrex(&KsepHistoryErrorsIndex);
    v1 = v0 + 1;
  }
  while ( __strex(v1, &KsepHistoryErrorsIndex) );
  __dmb(0xBu);
  v2 = &KsepHistoryErrors[4 * (v1 & 0x3F)];
  *((_DWORD *)v2 + 1) = -1073740768;
  v2[1] = 3;
  *v2 = 656;
  if ( (KsepDebugFlag & 4) != 0 )
    RtlAssert((int)"SourceString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 656, 0);
  JUMPOUT(0x771082);
}
