// RtlEnoughStackSpaceForStackCapture 
 
BOOL __fastcall RtlEnoughStackSpaceForStackCapture(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int *v8; // r0
  BOOL result; // r0
  int v10; // [sp+0h] [bp-8h] BYREF
  int v11; // [sp+4h] [bp-4h] BYREF

  v10 = a3;
  v11 = a4;
  v4 = RtlpGetStackLimits((int)&v10, (int)&v11, a3, a4);
  result = 0;
  if ( v4 )
  {
    v8 = KeGetCurrentStackPointer(v4, v5, v6, v7, v10);
    if ( (unsigned int)v8 - v10 >= 0x2D0 )
      result = 1;
  }
  return result;
}
