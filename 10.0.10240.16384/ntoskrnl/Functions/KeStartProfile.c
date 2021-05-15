// KeStartProfile 
 
int __fastcall KeStartProfile(int a1)
{
  int v2; // r1
  int v3; // r5
  _BYTE *v4; // r0
  int v6; // r2
  int v7[12]; // [sp+0h] [bp-30h] BYREF

  memset(v7, 0, 32);
  v7[0] = a1;
  v7[1] = KeNumberProcessors_0;
  v7[2] = KeNumberProcessors_0;
  v7[3] = 65537;
  v7[4] = 0;
  v7[5] = 0;
  v3 = KeQueryMaximumProcessorCountEx(0xFFFFu, v2) + 6;
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, 4 * v3);
  v7[6] = (int)v4;
  if ( !v4 )
    return 1;
  memset(v4, 0, 4 * v3);
  if ( (unsigned int)KeNumberProcessors_0 <= 1 )
    KiStartProfileTarget(v7);
  else
    KeIpiGenericCall(KiStartProfileTarget, (int)v7, v6, KeNumberProcessors_0);
  if ( v7[6] )
    ExFreePoolWithTag(v7[6], 1718579792);
  return LOBYTE(v7[7]);
}
