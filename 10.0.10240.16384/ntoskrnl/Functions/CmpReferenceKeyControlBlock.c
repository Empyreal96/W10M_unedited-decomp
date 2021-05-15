// CmpReferenceKeyControlBlock 
 
int __fastcall CmpReferenceKeyControlBlock(unsigned int *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r0
  unsigned int v4; // r1
  int result; // r0

  v2 = *a1;
  __dmb(0xBu);
  v3 = v2 + 1;
  if ( v2 == -1 )
    return 0;
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex(a1);
    while ( v4 == v2 && __strex(v3, a1) );
    __dmb(0xBu);
    if ( v4 == v2 )
      break;
    v2 = v4;
    v3 = v4 + 1;
    if ( v4 == -1 )
      return 0;
  }
  if ( (a1[2] & 1) != 0 && CmpRemoveFromDelayedDeref(a1) )
  {
    CmpDereferenceKeyControlBlock(a1);
    result = 1;
  }
  else
  {
    if ( (a1[2] & 2) != 0 )
      CmpRemoveFromDelayedClose(a1);
    result = 1;
  }
  return result;
}
