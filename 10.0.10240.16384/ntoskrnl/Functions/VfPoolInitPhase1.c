// VfPoolInitPhase1 
 
int VfPoolInitPhase1()
{
  _DWORD *v0; // r4
  int v1; // r5
  int result; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1
  int v5; // [sp+10h] [bp-30h] BYREF
  int v6; // [sp+14h] [bp-2Ch] BYREF
  int v7[10]; // [sp+18h] [bp-28h] BYREF

  v0 = &VfPoolDelayFreeData;
  v1 = 2;
  do
  {
    KeInitializeEvent((int)(v0 + 2), 1, 0);
    v7[0] = 24;
    v7[1] = 0;
    v7[3] = 512;
    v7[2] = 0;
    v7[4] = 0;
    v7[5] = 0;
    result = PsCreateSystemThread((int)&v5, 0, (int)v7);
    if ( result >= 0 )
    {
      ObReferenceObjectByHandle(v5, 0, PsThreadType, 0, (int)&v6, 0);
      v0[6] = v6;
      ZwClose();
      *v0 = 0;
      v0[1] = 0;
      __dmb(0xBu);
      v3 = v0 + 7;
      result = 1;
      do
        v4 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
    }
    v0 += 12;
    --v1;
  }
  while ( v1 );
  return result;
}
