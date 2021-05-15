// PsGetCurrentProcessSessionId 
 
int PsGetCurrentProcessSessionId()
{
  int v0; // r1
  int v1; // r2
  int result; // r0

  v0 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v1 = *(_DWORD *)(v0 + 324);
  if ( !v1 || v0 == PsInitialSystemProcess )
    result = -1;
  else
    result = *(_DWORD *)(v1 + 8);
  if ( result == -1 )
    result = 0;
  return result;
}
