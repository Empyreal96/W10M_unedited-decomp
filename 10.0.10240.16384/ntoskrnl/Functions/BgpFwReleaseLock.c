// BgpFwReleaseLock 
 
int BgpFwReleaseLock()
{
  unsigned int v0; // r4
  int result; // r0

  if ( (dword_619018 & 0xC00) != 3072 )
  {
    v0 = (unsigned __int8)byte_6416C4;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = sub_54D818();
    }
    else
    {
      __dmb(0xBu);
      dword_637098 = 0;
      if ( v0 <= 2 )
        result = KfLowerIrql(v0);
    }
  }
  return result;
}
