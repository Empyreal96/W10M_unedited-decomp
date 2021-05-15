// PpmCapturePerformanceDistribution 
 
int __fastcall PpmCapturePerformanceDistribution(int a1, unsigned int a2, int a3, unsigned int *a4, unsigned int *a5)
{
  unsigned int v6; // r6
  unsigned int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r4
  int result; // r0
  bool v13; // cc
  int v14[2]; // [sp+0h] [bp-48h] BYREF
  unsigned int v15; // [sp+8h] [bp-40h]
  int v16; // [sp+Ch] [bp-3Ch]
  unsigned int *v17; // [sp+10h] [bp-38h]
  unsigned int v18; // [sp+14h] [bp-34h]
  __int16 v19[2]; // [sp+18h] [bp-30h] BYREF
  int v20; // [sp+1Ch] [bp-2Ch]
  int v21; // [sp+20h] [bp-28h]

  v17 = a5;
  v6 = *a4;
  v14[1] = a2;
  v14[0] = a1;
  v15 = 4 * (a3 + 1);
  v16 = 0;
  while ( v6 )
  {
    v8 = __clz(__rbit(v6));
    v6 &= ~(1 << v8);
    v18 = v8;
    if ( v8 >= KeNumberProcessors_0 )
      v9 = 0;
    else
      v9 = (int)*(&KiProcessorBlock + v8);
    v10 = KfRaiseIrql(2);
    v11 = PpmCapturePerformanceDistributionCallback(v9, v14, 0);
    KfLowerIrql(v10);
    if ( v11 < 0 )
    {
      v19[0] = 1;
      v19[1] = 1;
      v20 = 0;
      v21 = 0;
      v21 = 1 << *(_DWORD *)(v9 + 20);
      result = PopExecuteOnTargetProcessors((int)v19, (int)PpmCapturePerformanceDistributionCallback, (int)v14, 0);
      if ( result < 0 )
        return result;
    }
  }
  v13 = v15 > a2;
  *v17 = v15;
  if ( v13 )
    return -1073741820;
  result = 0;
  *(_DWORD *)v14[0] = a3;
  return result;
}
