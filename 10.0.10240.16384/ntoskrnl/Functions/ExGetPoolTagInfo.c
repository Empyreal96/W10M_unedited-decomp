// ExGetPoolTagInfo 
 
int __fastcall ExGetPoolTagInfo(_DWORD *a1, unsigned int a2, unsigned int *a3, int a4)
{
  int v6; // r4
  _DWORD *v7; // r6
  unsigned int v8; // r5
  unsigned int v9; // r1
  int v11; // r0
  unsigned int v12; // r10
  _DWORD *i; // r2
  unsigned int v14; // r1
  unsigned int v15; // r1
  int v16; // [sp+8h] [bp-50h]
  int v18; // [sp+18h] [bp-40h]
  _DWORD _28[18]; // [sp+28h] [bp-30h] BYREF

  _28[14] = a1;
  _28[17] = a4;
  _28[16] = a3;
  _28[15] = a2;
  v6 = 0;
  v7 = a1 + 1;
  v8 = 4;
  *a1 = 0;
  v18 = PoolTrackTableSize;
  v16 = PoolTrackTableExpansionSize;
  v9 = 28 * PoolTrackTableExpansionSize + 28 * PoolTrackTableSize;
  if ( v9 < 28 * PoolTrackTableSize )
    return -1073741670;
  v11 = ExAllocatePoolWithTag(512, v9, 1868983881);
  v12 = v11;
  if ( !v11 )
    return -1073741670;
  _28[0] = v11;
  _28[1] = PoolTrackTableSize;
  _28[2] = v11 + 28 * PoolTrackTableSize;
  _28[3] = v16;
  KeGenericCallDpc((int)ExpGetPoolTagInfoTarget, (int)_28);
  for ( i = (_DWORD *)v12; (unsigned int)i < v12 + 28 * (v16 + v18); i += 7 )
  {
    if ( *i )
    {
      ++*a1;
      v8 += 28;
      if ( v8 < 0x1C )
      {
        v6 = -1073741675;
        break;
      }
      if ( a2 >= v8 )
      {
        v14 = i[5];
        if ( i[4] < v14 )
          i[4] = v14;
        v15 = i[2];
        if ( i[1] < v15 )
          i[1] = v15;
        *v7 = *i;
        v7[1] = i[4];
        v7[2] = i[5];
        v7[3] = i[6];
        v7[4] = i[1];
        v7[5] = i[2];
        v7[6] = i[3];
        v7 += 7;
      }
      else
      {
        v6 = -1073741820;
      }
    }
  }
  ExFreePoolWithTag(v12);
  if ( a3 )
    *a3 = v8;
  return v6;
}
