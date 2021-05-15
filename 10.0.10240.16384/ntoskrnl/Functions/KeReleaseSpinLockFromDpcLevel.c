// KeReleaseSpinLockFromDpcLevel 
 
_DWORD *__fastcall KeReleaseSpinLockFromDpcLevel(_DWORD *result)
{
  if ( (dword_682604 & 0x10000) != 0 )
    return (_DWORD *)sub_50ECEC();
  __dmb(0xBu);
  *result = 0;
  return result;
}
