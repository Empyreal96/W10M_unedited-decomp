// KiSendFreeze 
 
int __fastcall KiSendFreeze(int result, int a2)
{
  unsigned int v2; // r5
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  unsigned int *v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r1
  char v12; // [sp+0h] [bp-20h]

  v2 = *(_DWORD *)(result + 8);
  v4 = 0;
  while ( v2 )
  {
    v5 = __clz(__rbit(v2));
    v2 &= ~(1 << v5);
    v6 = (int)*(&KiProcessorBlock + v5);
    v12 = v5;
    __dmb(0xBu);
    if ( a2 )
    {
      v7 = (unsigned int *)(v6 + 1672);
      do
        v8 = __ldrex(v7);
      while ( !v8 && __strex(5u, v7) );
      __dmb(0xBu);
      if ( v8 )
        return sub_51C208();
LABEL_9:
      ++v4;
    }
    else
    {
      v10 = (unsigned int *)(v6 + 1672);
      do
        v11 = __ldrex(v10);
      while ( !v11 && __strex(5u, v10) );
      __dmb(0xBu);
      if ( !v11 )
        goto LABEL_9;
      *(_DWORD *)(result + 8) &= ~(1 << v12);
    }
  }
  if ( v4 )
  {
    v9 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v9 & 0xFFFFF000) + 0x1414);
    result = HalRequestIpi(0, result);
  }
  return result;
}
