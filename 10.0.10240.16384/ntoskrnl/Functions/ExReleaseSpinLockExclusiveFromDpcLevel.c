// ExReleaseSpinLockExclusiveFromDpcLevel 
 
_DWORD *__fastcall ExReleaseSpinLockExclusiveFromDpcLevel(_DWORD *result)
{
  if ( (dword_682604 & 0x10000) != 0 )
    return (_DWORD *)sub_50AE98();
  __dmb(0xBu);
  *result = 0;
  return result;
}
