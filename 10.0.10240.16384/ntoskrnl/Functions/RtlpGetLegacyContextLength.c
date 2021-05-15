// RtlpGetLegacyContextLength 
 
int __fastcall RtlpGetLegacyContextLength(int result, int *a2, int *a3)
{
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = 0;
  if ( (result & 0x10000) != 0 )
    return sub_5479B4();
  if ( (result & 0x100000) != 0 )
  {
    v3 = 1232;
    goto LABEL_14;
  }
  if ( (result & 0x200000) == 0 )
  {
    if ( (result & 0x400000) == 0 )
      goto LABEL_6;
    v3 = 912;
LABEL_14:
    v4 = 16;
    goto LABEL_6;
  }
  v3 = 416;
  v4 = 8;
LABEL_6:
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = v4;
  return result;
}
