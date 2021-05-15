// VerifierMmGetSystemRoutineAddress 
 
int __fastcall VerifierMmGetSystemRoutineAddress(int a1)
{
  int result; // r0

  result = pXdvMmGetSystemRoutineAddress();
  if ( result )
    VfThunkAdjustExportAddressIfHooked(result, a1);
  return result;
}
