// IovpCancelRoutine 
 
int __fastcall IovpCancelRoutine(int a1, int a2, int (*a3)(void))
{
  int result; // r0

  if ( (MmVerifierData & 0x7A0000) != 0
    && a1
    && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 24) + 32)
    && pXdvDRIVER_CANCEL )
  {
    result = pXdvDRIVER_CANCEL();
  }
  else
  {
    result = a3();
  }
  return result;
}
