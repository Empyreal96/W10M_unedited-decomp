// EtwpStartTrace 
 
int __fastcall EtwpStartTrace(int a1)
{
  unsigned int v2; // r2
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r1
  __int16 v6; // r3
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  KeWaitForSingleObject((unsigned int)&EtwpStartTraceMutex, 0, 0, 0, 0);
  v3 = EtwpStartLogger(a1);
  v4 = KeReleaseMutex((int)&EtwpStartTraceMutex);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( v6 || *(_DWORD *)(v5 + 100) == v5 + 100 )
    result = v3;
  else
    result = sub_7EB1E8(v4);
  return result;
}
