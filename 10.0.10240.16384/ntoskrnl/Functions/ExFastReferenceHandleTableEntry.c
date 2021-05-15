// ExFastReferenceHandleTableEntry 
 
int __fastcall ExFastReferenceHandleTableEntry(int a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  unsigned __int64 v6; // r0
  bool v7; // cf
  int result; // r0

  do
  {
    while ( 1 )
    {
      v6 = __ldrexd(a2);
      if ( !(_DWORD)v6 )
        return -1;
      v7 = HIDWORD(v6) >= 0x8000000;
      HIDWORD(v6) -= 0x8000000;
      if ( !v7 )
        return -1;
      if ( (v6 & 1) != 0 )
        break;
      ExpBlockOnLockedHandleEntry(a1, a2, a1);
    }
  }
  while ( __strexd(v6, a2) );
  *a3 = v6;
  LODWORD(v6) = 24;
  if ( HIDWORD(v6) >> 27 != 7 )
    result = 0;
  return result;
}
