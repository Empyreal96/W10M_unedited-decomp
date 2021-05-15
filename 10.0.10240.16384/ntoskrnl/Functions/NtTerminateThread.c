// NtTerminateThread 
 
int __fastcall NtTerminateThread(int a1, int a2)
{
  int v2; // r3
  unsigned int v3; // r6
  int v4; // r3

  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = v2 & 0xFFFFFFC0;
  if ( a1 )
  {
    if ( a1 != -2 )
      JUMPOUT(0x7F7984);
LABEL_6:
    PspTerminateThreadByPointer(v3, a2, 1);
    JUMPOUT(0x7F79C0);
  }
  v4 = *(_DWORD *)(*(_DWORD *)((v2 & 0xFFFFFFC0) + 0x74) + 404);
  __dmb(0xBu);
  if ( v4 != 1 )
    goto LABEL_6;
  return sub_7F7980();
}
