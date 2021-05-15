// RtlpIsFrameInBoundsEx 
 
int __fastcall RtlpIsFrameInBoundsEx(unsigned int *a1, unsigned int a2, unsigned int *a3, _DWORD *a4)
{
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r9
  int v12; // r2
  __int16 v13; // r3
  int v14; // r2
  __int64 v15; // kr00_8
  unsigned int *v16; // [sp+0h] [bp-28h] BYREF
  unsigned int v17; // [sp+4h] [bp-24h] BYREF
  _DWORD v18[8]; // [sp+8h] [bp-20h] BYREF

  v16 = a1;
  v17 = a2;
  v18[0] = a3;
  v18[1] = a4;
  if ( (a2 & 3) == 0 )
  {
    if ( a2 >= *a1 && a2 < *a3 )
      return 1;
    if ( *a1 >= MmSystemRangeStart )
    {
      v9 = KeQueryCurrentStackInformation(&v16, v18, &v17);
      v10 = (int)v16;
      if ( v16 != (unsigned int *)5 )
      {
        if ( v16 )
        {
          v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          if ( v10 != 1 )
          {
            if ( (__get_CPSR() & 0x80) != 0 )
            {
              v12 = 0;
            }
            else
            {
              __disable_irq();
              v12 = 1;
            }
            v13 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
            if ( v12 )
              __enable_irq();
            if ( (v13 & 1) != 0 )
              return sub_547C18(v9);
          }
          v14 = 0;
          if ( !*a4 )
          {
            KeGetNextKernelStackSegment(v11, a4, 1);
            v14 = 1;
          }
          if ( (v10 == 1 || v10 == 6) && v14 || KeGetNextKernelStackSegment(v11, a4, 0) )
          {
            v15 = *(_QWORD *)a4;
            if ( a2 >= a4[1] && a2 < (unsigned int)v15 )
            {
              *a1 = HIDWORD(v15);
              *a3 = v15;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
