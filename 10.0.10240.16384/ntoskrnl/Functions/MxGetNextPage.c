// MxGetNextPage 
 
int __fastcall MxGetNextPage(int a1)
{
  unsigned int v1; // r1
  int result; // r0
  int *v4; // r5
  int *v5; // r2
  int v6; // r1
  int v7; // r4

  v1 = 0;
  result = -1;
  do
  {
    v4 = &MxFreeDescriptor[4 * a1];
    if ( v4[1] && v4[2] != -1 )
      break;
    if ( ++a1 == (unsigned __int16)KeNumberNodes )
      a1 = 0;
    ++v1;
  }
  while ( v1 < (unsigned __int16)KeNumberNodes );
  if ( v1 == (unsigned __int16)KeNumberNodes )
  {
    byte_634429 = 16;
  }
  else
  {
    v5 = &MxFreeDescriptor[4 * a1];
    v6 = v5[2];
    if ( v6 == (v6 & 0xFFFFFC00) )
    {
      v7 = v5[3];
      if ( v7 == -1 )
      {
        v5[2] = -1;
      }
      else
      {
        v5[2] = v7 + 1023;
        if ( (unsigned int)(v7 - *v5) < 0x400 )
          v5[3] = -1;
        else
          v5[3] = v7 - 1024;
      }
    }
    else
    {
      v5[2] = v6 - 1;
    }
    result = v6;
  }
  return result;
}
