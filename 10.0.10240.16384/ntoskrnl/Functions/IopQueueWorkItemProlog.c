// IopQueueWorkItemProlog 
 
int __fastcall IopQueueWorkItemProlog(_DWORD *a1, int a2, int a3)
{
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r4
  int v10; // r3
  int v11; // r2
  unsigned int *v12; // r4
  unsigned int v13; // r2
  signed int v14; // r2

  if ( (IopFunctionPointerMask & 4) != 0 )
    return sub_51F7D0();
  a1[9] = 0;
  a1[10] = 0;
  a1[11] = 0;
  a1[12] = 0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v7 = 0;
  }
  else
  {
    __disable_irq();
    v7 = 1;
  }
  v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v7 )
    __enable_irq();
  if ( (v8 & 0x10001) == 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_DWORD *)(v9 + 0x420);
    if ( v10 )
    {
      ObfReferenceObjectWithTag(v10 & 0xFFFFFFFE, 1953261124);
      a1[7] = *(_DWORD *)(v9 + 1056);
    }
    else
    {
      v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 288);
      __dmb(0xBu);
      if ( v11 )
      {
        ObfReferenceObjectWithTag(v9, 1953261124);
        a1[7] = v9 | 1;
      }
    }
  }
  v12 = (unsigned int *)(a1[5] - 24);
  if ( ObpTraceFlags )
    ObpPushStackInfo(a1[5] - 24, 1, 1, 1953261124);
  do
  {
    v13 = __ldrex(v12);
    v14 = v13 + 1;
  }
  while ( __strex(v14, v12) );
  __dmb(0xBu);
  if ( v14 <= 1 )
    KeBugCheckEx(24, 0, v12 + 6);
  a1[4] = a2;
  a1[6] = a3;
  return (int)a1;
}
