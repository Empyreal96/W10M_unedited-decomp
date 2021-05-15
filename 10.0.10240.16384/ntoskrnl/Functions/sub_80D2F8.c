// sub_80D2F8 
 
int sub_80D2F8()
{
  unsigned int v0; // r0
  int v1; // r2
  int *v3; // r4
  unsigned int *v4; // r5
  int v5; // r6
  unsigned int v6; // r7
  unsigned int v7; // r0
  unsigned int v8; // r6
  unsigned int v9; // r1
  int v10; // r2
  unsigned int v11; // r0
  int (__fastcall *v12)(unsigned int); // [sp-4h] [bp-4h]

  ExpAcquireFastMutexContended((int)v4, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v4[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4[7] = v6;
  v7 = v3[71];
  if ( v7 )
  {
    ExFreePoolWithTag(v7);
    v3[71] = 0;
  }
  v0 = v3[72];
  if ( v0 )
  {
    ExFreePoolWithTag(v0);
    v3[72] = 0;
  }
  v4[1] = 0;
  v8 = v4[7];
  __dmb(0xBu);
  do
    v9 = __ldrex(v4);
  while ( !v9 && __strex(1u, v4) );
  if ( v9 )
    ExpReleaseFastMutexContended(v4, v9);
  KfLowerIrql((unsigned __int8)v8);
  v11 = KeAbPostRelease((unsigned int)v4);
  v1 = v3[67];
  if ( (v1 & 0x10001) == 1 )
  {
    if ( (v1 & 0x40) != 0 )
    {
      v10 = v3[90];
      if ( v10 )
        v11 = IopAllocateBootResourcesInternal(4, v3[4], v10);
    }
  }
  else
  {
    PipClearDevNodeFlags((int)v3, 192);
    v11 = v3[90];
    if ( v11 )
    {
      v11 = ExFreePoolWithTag(v11);
      v3[90] = 0;
    }
  }
  return v12(v11);
}
