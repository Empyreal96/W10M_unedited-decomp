// MiDeleteNoBlockStacks 
 
int __fastcall MiDeleteNoBlockStacks(int a1)
{
  int result; // r0
  _DWORD *v2; // r5
  unsigned int v3; // r0
  int v4; // r1

  if ( !a1 )
    return sub_516B78();
  result = RtlpInterlockedFlushSList((unsigned __int64 *)&algn_634841[7]);
  v2 = (_DWORD *)result;
  while ( v2 )
  {
    v3 = (unsigned int)(v2 - 1022);
    if ( *(v2 - 2) != (dword_634C80 ^ (unsigned int)(v2 - 1022)) )
      KeBugCheckEx(26, 13425, v2 - 1022);
    v4 = v2[1];
    v2 = (_DWORD *)*v2;
    result = MiDeleteKernelStack(((v3 >> 10) & 0x3FFFFC) - 0x40000000, v4);
  }
  return result;
}
