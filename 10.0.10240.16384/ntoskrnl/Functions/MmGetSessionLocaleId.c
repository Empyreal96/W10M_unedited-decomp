// MmGetSessionLocaleId 
 
int MmGetSessionLocaleId()
{
  int v0; // r0
  int v1; // r4
  int result; // r0

  v0 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v1 = *(_DWORD *)(v0 + 324);
  if ( !v1 || PsIsSystemProcess(v0) )
    result = PsDefaultThreadLocaleId;
  else
    result = *(_DWORD *)(v1 + 72);
  return result;
}
