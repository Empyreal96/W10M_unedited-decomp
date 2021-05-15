// FsRtlpOplockUpperLowerCompatible 
 
int __fastcall FsRtlpOplockUpperLowerCompatible(int a1, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = 1;
  v3 = a1 & 0x1701E;
  if ( (a1 & 0x1701E) == 0 || v3 == 0x10000 )
    return 1;
  switch ( a2 )
  {
    case 0:
      return 0;
    case 4096:
LABEL_12:
      if ( v3 == 4096 || v3 == 16 )
        return v2;
      return 0;
    case 12288:
      if ( v3 == 12288 )
        return v2;
      goto LABEL_12;
    case 20480:
      return sub_7F3F58();
  }
  return v2;
}
