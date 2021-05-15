// sub_7C95FC 
 
void sub_7C95FC()
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
  *((_DWORD *)v2 + 1) = -1073741823;
  v2[1] = 10;
  *v2 = 715;
  if ( (KsepDebugFlag & 2) != 0 )
    KsepDebugPrint(0, (int)"KSE: Cannot add hardware id until the kshim engine is initialized\n");
  KsepLogError(0, (int)"KSE: Cannot add hardware id until the kshim engine is initialized\n");
  JUMPOUT(0x7689A6);
}
