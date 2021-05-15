// VfPnpAdvanceIrpStatus 
 
int __fastcall VfPnpAdvanceIrpStatus(int a1, unsigned int a2, int *a3)
{
  int v5; // r2

  if ( a2 >= 0x100 )
    return 0;
  v5 = *a3 + 1;
  *a3 = v5;
  if ( v5 == 259 )
    *a3 = 260;
  return 1;
}
