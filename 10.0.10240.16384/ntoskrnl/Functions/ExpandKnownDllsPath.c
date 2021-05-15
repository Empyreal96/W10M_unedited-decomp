// ExpandKnownDllsPath 
 
int __fastcall ExpandKnownDllsPath(unsigned __int16 *a1, int a2)
{
  unsigned __int16 v4; // r7
  int v5; // r0

  v4 = NtSystemRoot + *a1;
  v5 = ExAllocatePoolWithTag(1, v4, 1953066569);
  *(_DWORD *)(a2 + 4) = v5;
  if ( !v5 )
    return -1073741670;
  *(_WORD *)a2 = 0;
  *(_WORD *)(a2 + 2) = v4;
  RtlCopyUnicodeString((unsigned __int16 *)a2, (unsigned __int16 *)&NtSystemRoot);
  RtlAppendUnicodeStringToString((unsigned __int16 *)a2, a1);
  return 0;
}
