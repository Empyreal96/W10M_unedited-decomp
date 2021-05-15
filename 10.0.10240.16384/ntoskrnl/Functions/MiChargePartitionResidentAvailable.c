// MiChargePartitionResidentAvailable 
 
int __fastcall MiChargePartitionResidentAvailable(int a1, unsigned int a2, int a3)
{
  unsigned int *v4; // r6
  int v5; // r5
  int v7; // r7
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r3
  unsigned int *v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r2

  if ( a2 + a3 >= a2 || a3 == -1 )
  {
    v4 = (unsigned int *)(a1 + 3840);
    v5 = *(_DWORD *)(a1 + 3840);
    if ( v5 < 1024 )
      return sub_50AC8C(0);
    while ( a2 + a3 <= v5 || a3 == -1 )
    {
      do
        v7 = __ldrex(v4);
      while ( v7 == v5 && __strex(v5 - a2, v4) );
      if ( v7 == v5 )
      {
        v8 = v5 - a2;
        if ( (int)(v5 - a2) < 1024 )
          v9 = 3;
        else
          v9 = 2;
        if ( (__int16 *)a1 == MiSystemPartition )
        {
          v10 = (unsigned int)KeGetPcr();
          v11 = (unsigned int *)((v10 & 0xFFFFF000) + 4992);
          v12 = *(_DWORD *)((v10 & 0xFFFFF000) + 0x1380);
          if ( v12 == -1 )
          {
            if ( v8 < 2048 )
              return v9;
            do
              v14 = __ldrex(v11);
            while ( v14 == -1 && __strex(0, v11) );
            v12 = 0;
          }
          else if ( v12 >= 0x40 )
          {
            return v9;
          }
          if ( v8 > 1024 )
          {
            do
              v13 = __ldrex(v4);
            while ( v13 == v8 && __strex(v8 - (128 - v12), v4) );
            if ( v13 == v8 )
              MiReturnResidentAvailable(128 - v12);
          }
        }
        return v9;
      }
      v5 = v7;
      if ( v7 <= 0 )
      {
        if ( a3 == -1 )
          JUMPOUT(0x50ACE8);
        return 0;
      }
    }
  }
  return 0;
}
