// PsTerminateSystemThread 
 
int __fastcall PsTerminateSystemThread(int a1)
{
  unsigned int v2; // r0
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v2 + 0x4C) & 0x400) != 0 )
    result = PspTerminateThreadByPointer(v2, a1, 1);
  else
    result = sub_7EAD24();
  return result;
}
