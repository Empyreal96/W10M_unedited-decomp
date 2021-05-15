// sub_7CD27C 
 
void sub_7CD27C()
{
  unsigned int v0; // r1
  unsigned int v1; // r1
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
  *v2 = 846;
  if ( (KsepDebugFlag & 4) != 0 )
    RtlAssert((int)"String != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 846, 0);
  JUMPOUT(0x77106A);
}
