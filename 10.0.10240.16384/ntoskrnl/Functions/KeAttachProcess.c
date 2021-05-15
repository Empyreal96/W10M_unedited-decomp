// KeAttachProcess 
 
int __fastcall KeAttachProcess(int result)
{
  int v1; // r5
  unsigned int v2; // r4
  int v3; // r2
  int v4; // r3
  int v5; // r0
  unsigned int *v6; // r1
  unsigned int v7; // r2
  int v8; // r2
  int v9; // r3

  v1 = result;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v2 + 0x74) != result )
  {
    if ( *(_BYTE *)(v2 + 362) )
      goto LABEL_15;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v3 = 0;
    }
    else
    {
      __disable_irq();
      v3 = 1;
    }
    v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v3 )
      __enable_irq();
    if ( (v4 & 0x10001) != 0 )
    {
LABEL_15:
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v8 = 0;
      }
      else
      {
        __disable_irq();
        v8 = 1;
      }
      v9 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      if ( v8 )
        __enable_irq();
      KeBugCheck2(5, result, *(_DWORD *)(v2 + 116), *(unsigned __int8 *)(v2 + 362), v9 & 0x10001, 0);
    }
    v5 = KfRaiseIrql(2);
    v6 = (unsigned int *)(v2 + 44);
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v7 )
      result = sub_526DC8(v5);
    else
      result = KiAttachProcess(v2, v1, v5, 0);
  }
  return result;
}
