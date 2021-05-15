// PiPnpRtlObjectEventRelease 
 
unsigned int *__fastcall PiPnpRtlObjectEventRelease(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r2
  unsigned int v3; // r2
  unsigned int v4; // r0
  unsigned int v5; // r6
  unsigned int *v6; // r5
  unsigned int v7; // r0

  v1 = result;
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(result);
    v3 = v2 - 1;
  }
  while ( __strex(v3, result) );
  __dmb(0xBu);
  if ( !v3 )
  {
    v4 = result[2];
    if ( v4 )
      PiDmObjectRelease(v4);
    if ( v1[3] )
      ZwClose();
    if ( (v1[1] & 4) != 0 )
    {
      result = (unsigned int *)sub_7C5BC8();
    }
    else
    {
      v5 = 0;
      if ( v1[11] )
      {
        v6 = v1;
        do
        {
          v7 = v6[18];
          if ( v7 )
            ExFreePoolWithTag(v7);
          ++v5;
          v6 += 7;
        }
        while ( v5 < v1[11] );
      }
      result = (unsigned int *)ExFreePoolWithTag((unsigned int)v1);
    }
  }
  return result;
}
