// MiCommitRequestFailed 
 
int __fastcall MiCommitRequestFailed(int result)
{
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1 && (*(_DWORD *)(result + 192) & 0x100) != 0 )
    result = KeRequestTerminationProcess(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return result;
}
