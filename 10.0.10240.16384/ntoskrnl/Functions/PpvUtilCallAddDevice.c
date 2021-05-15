// PpvUtilCallAddDevice 
 
int __fastcall PpvUtilCallAddDevice(int a1, int a2, int (__fastcall *a3)(int, int))
{
  int result; // r0

  if ( PpvUtilVerifierEnabled )
    result = sub_518A38();
  else
    result = a3(a2, a1);
  return result;
}
