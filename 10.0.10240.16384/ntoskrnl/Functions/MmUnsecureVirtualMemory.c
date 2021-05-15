// MmUnsecureVirtualMemory 
 
int __fastcall MmUnsecureVirtualMemory(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // r4
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  result = MiObtainReferencedSecureVad((int)a1, v7);
  v6 = result;
  if ( result )
  {
    MiRemoveSecureEntry(result, a1);
    result = MiUnlockAndDereferenceVad(v6);
  }
  return result;
}
