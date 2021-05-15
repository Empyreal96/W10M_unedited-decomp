// KeQueryCurrentStackInformation 
 
int __fastcall KeQueryCurrentStackInformation(_DWORD *a1, unsigned int *a2, unsigned int *a3, int a4)
{
  int result; // r0
  int *v8; // r5
  unsigned int v9; // r0
  unsigned int v10; // r4
  int v11; // r2
  int v12; // r1
  __int64 v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r3

  if ( (KiBugCheckActive & 3) != 0 )
    return sub_548290();
  v8 = KeGetCurrentStackPointer((int)a1, (int)a2, (int)a3, KiBugCheckActive, a4);
  v9 = KeGetCurrentIrql(v8);
  if ( v9 < 2
    || (v14 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574), v14 - 12288 > (unsigned int)v8)
    || (unsigned int)v8 >= v14 )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v11 = 0;
    }
    else
    {
      __disable_irq();
      v11 = 1;
    }
    v12 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44);
    if ( v11 )
      __enable_irq();
    if ( *(_DWORD *)(v10 + 32) == v12 )
    {
      if ( (unsigned int)KeGetCurrentIrql(v9) < 2
        || (v15 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC40) + 16,
            v16 = v15 - KeKernelStackSize,
            v15 - KeKernelStackSize > (unsigned int)v8)
        || (unsigned int)v8 >= v15 )
      {
        if ( (*(_DWORD *)(v10 + 76) & 0x1000) != 0 )
        {
          *a1 = 2;
        }
        else if ( *(_BYTE *)(v10 + 447) )
        {
          *a1 = 4;
        }
        else
        {
          *a1 = 3;
        }
        v13 = *(_QWORD *)(v10 + 36);
        *a3 = HIDWORD(v13);
        *a2 = v13;
        result = *a2 <= (unsigned int)v8 && (unsigned int)v8 < *a3;
      }
      else
      {
        *a1 = 1;
        *a3 = v15;
        *a2 = v16;
        result = 1;
      }
    }
    else
    {
      *a1 = 5;
      *a3 = -1;
      result = 1;
      *a2 = MmSystemRangeStart;
    }
  }
  else
  {
    *a1 = 6;
    *a3 = v14;
    *a2 = v14 - 12288;
    result = 1;
  }
  return result;
}
