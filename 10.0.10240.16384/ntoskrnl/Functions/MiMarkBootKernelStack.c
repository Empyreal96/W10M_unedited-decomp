// MiMarkBootKernelStack 
 
unsigned int __fastcall MiMarkBootKernelStack(unsigned int a1, unsigned int a2)
{
  unsigned int v4; // r0
  int v5; // r1
  int v7; // [sp+0h] [bp-B8h] BYREF
  char v8; // [sp+4h] [bp-B4h]
  char v9; // [sp+5h] [bp-B3h]
  int v10; // [sp+8h] [bp-B0h]
  int v11; // [sp+Ch] [bp-ACh]
  int v12; // [sp+10h] [bp-A8h]
  int v13; // [sp+14h] [bp-A4h]

  v4 = MiMarkKernelStack(a1, a2, -3);
  v9 = 0;
  v12 = 0;
  v10 = 33;
  v13 = 0;
  v11 = 0;
  v7 = 0;
  v8 = 0;
  if ( a1 < a2 )
    return sub_966514(v4);
  v8 = 1;
  return MiFlushTbList((unsigned int)&v7, v5);
}
