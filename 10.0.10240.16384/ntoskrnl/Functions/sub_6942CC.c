// sub_6942CC 
 
void __fastcall sub_6942CC(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *v4; // r4
  unsigned int *v5; // r5
  int v6; // r6
  int v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r6
  int *v10; // r7
  int v11; // t1

  if ( a4 >= 9 )
    v4[6] = 0;
  if ( v4[5] >= 5u )
    v4[5] = 0;
  if ( v4[3] >= 5u )
    v4[3] = 0;
  if ( v4[2] >= 5u )
    v4[2] = 0;
  if ( v4[4] > 7u )
    v4[4] = 0;
  *v4 = _rt_udiv64(1000000i64, *(_QWORD *)(v5[13] + 968)) * v4[1];
  KeGenericCallDpc((int)KiConfigureHeteroProcessorsTarget, v6);
  v8 = v5[69];
  v5[517] = v8;
  if ( !v8 )
    v4[6] = 0;
  v9 = 0;
  if ( *v5 )
  {
    v10 = (int *)(v5 + 13);
    do
    {
      v11 = *v10++;
      KiConfigureCpuSetSchedulingInformation(v11);
      ++v9;
    }
    while ( v9 < *v5 );
  }
  if ( v7 == v4[6] )
    JUMPOUT(0x6931C2);
  JUMPOUT(0x6931C4);
}
