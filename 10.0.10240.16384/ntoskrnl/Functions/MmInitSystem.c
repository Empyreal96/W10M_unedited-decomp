// MmInitSystem 
 
int __fastcall MmInitSystem(int a1, int a2)
{
  int v3; // r0

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( (unsigned __int16)KeNumberNodes > 1u )
        return sub_96A0D0();
      MiFlags = MiFlags & 0xFFFFFFCF | 0x10;
      if ( MiInitSystem(1, a2) )
      {
        byte_634C8C = 1;
        return 1;
      }
    }
    else if ( a1 == 2 )
    {
      v3 = 2;
      MiFlags = MiFlags & 0xFFFFFFCF | 0x20;
      return MiInitSystem(v3, a2);
    }
  }
  else if ( MmInitNucleus(a2) )
  {
    v3 = 0;
    return MiInitSystem(v3, a2);
  }
  return 0;
}
