// ViSuspectDriversLookupEntry 
 
int __fastcall ViSuspectDriversLookupEntry(unsigned __int16 *a1)
{
  int i; // r4

  for ( i = VfSuspectDriversList; (int *)i != &VfSuspectDriversList; i = *(_DWORD *)i )
  {
    if ( RtlEqualUnicodeString((unsigned __int16 *)(i + 16), a1, 1) )
      return i;
  }
  return 0;
}
