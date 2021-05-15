// MxGetNextLargePage 
 
int __fastcall MxGetNextLargePage(int a1)
{
  int result; // r0
  int *v3; // r5
  int *v4; // r2
  int v5; // r1

  result = -1;
  v3 = &MxFreeDescriptor[4 * a1];
  if ( !v3[1] || v3[3] == -1 )
    return sub_96B740(-1, 0, a1);
  if ( KeNumberNodes )
  {
    v4 = &MxFreeDescriptor[4 * a1];
    v5 = v4[3];
    if ( (unsigned int)(v5 - *v4) < 0x400 )
      v4[3] = -1;
    else
      v4[3] = v5 - 1024;
    result = v5;
  }
  else
  {
    byte_634429 = 16;
  }
  return result;
}
