// HvResetUnreconciledData 
 
_BYTE *__fastcall HvResetUnreconciledData(_BYTE *result)
{
  _BYTE *v1; // r4

  v1 = result;
  if ( *((_DWORD *)result + 14) )
  {
    result = RtlClearAllBits((int)(result + 52));
    v1[123] = 0;
    *((_DWORD *)v1 + 15) = 0;
  }
  return result;
}
