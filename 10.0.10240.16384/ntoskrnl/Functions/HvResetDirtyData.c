// HvResetDirtyData 
 
_BYTE *__fastcall HvResetDirtyData(_BYTE *result)
{
  _BYTE *v1; // r5
  int v2; // r1
  unsigned int v3; // r4

  v1 = result;
  if ( *((_DWORD *)result + 10) )
  {
    HvpResetPageProtection();
    result = RtlClearAllBits((int)(v1 + 36));
    __dmb(0xBu);
    v2 = -*((_DWORD *)v1 + 11);
    do
      v3 = __ldrex((unsigned int *)&CmpDirtySectorCount);
    while ( __strex(v3 + v2, (unsigned int *)&CmpDirtySectorCount) );
    __dmb(0xBu);
    *((_DWORD *)v1 + 11) = 0;
  }
  return result;
}
