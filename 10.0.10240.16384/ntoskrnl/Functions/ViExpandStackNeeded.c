// ViExpandStackNeeded 
 
BOOL __fastcall ViExpandStackNeeded(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int *v8; // r0
  int v11; // [sp+0h] [bp-8h] BYREF
  int v12; // [sp+4h] [bp-4h] BYREF

  v11 = a3;
  v12 = a4;
  v4 = RtlpGetStackLimits((int)&v11, (int)&v12, a3, a4);
  if ( !v4 )
    return 0;
  v8 = KeGetCurrentStackPointer(v4, v5, v6, v7, v11);
  return (unsigned int)v8 - v11 < 0xC00;
}
