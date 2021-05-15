// RtlpHeapExceptionFilter 
 
int __fastcall RtlpHeapExceptionFilter(int a1, int *a2)
{
  if ( a1 == -1073741571 || a1 == -1073741420 || a1 == -1073741801 )
    return 0;
  memmove((int)&byte_618338[132], *a2, 0x50u);
  memmove((int)&byte_618338[216], a2[1], 0x1A0u);
  return 1;
}
