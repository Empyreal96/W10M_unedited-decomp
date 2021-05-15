// sub_96580C 
 
void sub_96580C()
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
  v2[1] = 2;
  *v2 = 811;
  if ( (KsepDebugFlag & 4) != 0 )
    RtlAssert((int)"Engine != NULL", (int)"minkernel\\ntos\\kshim\\ksecore.c", 811, 0);
  JUMPOUT(0x948544);
}
