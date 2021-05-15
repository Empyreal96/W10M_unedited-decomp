// MmChargeResources 
 
int __fastcall MmChargeResources(int a1, char a2, int a3, char a4)
{
  int v4; // r5
  unsigned int v9; // r0
  int v10; // r4
  unsigned int v12; // r4

  v4 = 0;
  if ( (a2 & 2) != 0 )
  {
    if ( !MiChargeResident(&MiSystemPartition, a1, 0) )
      return 0;
    v4 = 2;
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        do
          v9 = __ldrex(&dword_634A2C[126]);
        while ( __strex(v9 + a1, &dword_634A2C[126]) );
      }
    }
    else
    {
      do
        v12 = __ldrex(&dword_634A2C[78]);
      while ( __strex(v12 + a1, &dword_634A2C[78]) );
    }
  }
  if ( (a2 & 1) != 0 && !MiChargeCommit(&MiSystemPartition, a1, (a4 & 1) != 0) )
  {
    v10 = 0;
  }
  else
  {
    v10 = 1;
    v4 = 0;
  }
  if ( v4 )
    return sub_5112B4();
  return v10;
}
