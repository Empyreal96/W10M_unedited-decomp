// IopAllocateMiniCompletionPacket 
 
int __fastcall IopAllocateMiniCompletionPacket(int a1, int a2)
{
  char v3; // r4
  unsigned int v4; // r8
  int v5; // r5
  int result; // r0
  int v7; // r5
  unsigned int v8; // r1
  char vars8a; // [sp+28h] [bp+8h]
  int _2C; // [sp+2Ch] [bp+Ch]

  _2C = a2;
  v3 = a1;
  if ( a1 == 4 )
  {
    v8 = 40;
    goto LABEL_8;
  }
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v5 = *(_DWORD *)(v4 + 2872);
  ++*(_DWORD *)(v5 + 12);
  result = RtlpInterlockedPopEntrySList((unsigned __int64 *)v5);
  if ( !result )
  {
    ++*(_DWORD *)(v5 + 16);
    v7 = *(_DWORD *)(v4 + 2876);
    ++*(_DWORD *)(v7 + 12);
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)v7);
    if ( !result )
    {
      ++*(_DWORD *)(v7 + 16);
      if ( a2 )
      {
        v3 = 3;
        vars8a = 3;
        result = ExAllocatePoolWithQuotaTag(0x200u, 0x1Cu, 544236361);
        goto LABEL_9;
      }
      v8 = 28;
LABEL_8:
      result = ExAllocatePoolWithTagPriority(512, v8, 544236361, 0);
LABEL_9:
      if ( !result )
        return result;
      goto LABEL_10;
    }
  }
LABEL_10:
  *(_BYTE *)(result + 8) = v3;
  return result;
}
