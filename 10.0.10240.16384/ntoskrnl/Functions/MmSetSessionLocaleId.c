// MmSetSessionLocaleId 
 
int __fastcall MmSetSessionLocaleId(int a1)
{
  int result; // r0
  int v3; // r5

  result = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = *(_DWORD *)(result + 324);
  if ( !v3 || (result = PsIsSystemProcess(result)) != 0 )
    PsDefaultThreadLocaleId = a1;
  else
    *(_DWORD *)(v3 + 72) = a1;
  return result;
}
