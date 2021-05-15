// RawComputeFileSystemInformationChecksum 
 
unsigned int __fastcall RawComputeFileSystemInformationChecksum(int a1)
{
  unsigned int v2; // r4
  unsigned int result; // r0
  unsigned int v4; // r3
  int v5; // r2
  __int16 v6; // r1

  v2 = *(unsigned __int16 *)(a1 + 20);
  result = 0;
  v4 = 3;
  if ( v2 > 3 )
  {
    v5 = 3;
    do
    {
      if ( v5 != 22 && v5 != 23 )
      {
        if ( (result & 1) != 0 )
          v6 = 0x8000;
        else
          v6 = 0;
        result = (unsigned __int16)(*(unsigned __int8 *)(v4 + a1) + (unsigned __int16)(result >> 1) + v6);
      }
      v4 = (unsigned __int16)(v5 + 1);
      v5 = v4;
    }
    while ( v4 < v2 );
  }
  return result;
}
