// IovInitializeIrp 
 
int __fastcall IovInitializeIrp(int result, int a2, int a3, int a4)
{
  int v4; // r2

  v4 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v4 )
    result = VfIoInitializeIrp(result, a4, 0);
  return result;
}
