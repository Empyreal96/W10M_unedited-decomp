// PpmIdleDurationExpiration 
 
int PpmIdleDurationExpiration()
{
  int result; // r0
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // lr
  int v4; // r5
  int v5; // r7
  void **v6; // r2
  int v7; // t1
  int v8; // r2
  unsigned int v9; // r1
  int v10; // r3
  int v11; // [sp+8h] [bp-28h] BYREF
  __int16 v12[2]; // [sp+10h] [bp-20h] BYREF
  int v13; // [sp+14h] [bp-1Ch]
  int v14; // [sp+18h] [bp-18h]

  v12[0] = 1;
  v12[1] = 1;
  v13 = 0;
  v14 = 0;
  result = RtlGetInterruptTimePrecise(&v11);
  v1 = 0;
  v3 = v2;
  v4 = (unsigned __int16)KeNumberNodes;
  v5 = result;
  if ( KeNumberNodes )
  {
    v6 = &KeNodeBlock;
    do
    {
      v7 = (int)*v6++;
      v1 |= *(_DWORD *)(v7 + 132);
      --v4;
    }
    while ( v4 );
  }
  v8 = v14;
  while ( v1 )
  {
    v9 = __clz(__rbit(v1));
    result = 1 << v9;
    v1 &= ~(1 << v9);
    if ( v9 >= KeNumberProcessors_0 )
      v10 = 0;
    else
      v10 = (int)*(&KiProcessorBlock + v9);
    if ( *(_QWORD *)(v10 + 2976) <= __PAIR64__(v3, v5) )
    {
      v8 |= result;
      v14 = v8;
    }
  }
  if ( v8 )
  {
    PpmEventIdleDurationExpiration(v12);
    result = HalRequestIpi(0, v12);
  }
  return result;
}
