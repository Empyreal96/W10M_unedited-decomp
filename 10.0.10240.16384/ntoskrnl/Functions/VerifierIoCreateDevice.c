// VerifierIoCreateDevice 
 
int __fastcall VerifierIoCreateDevice(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r4

  v7 = pXdvIoCreateDevice(a1, a2, a3, a4);
  if ( v7 >= 0 && (MmVerifierData & 0x10) != 0 )
    ViDevObjAdd(*a7);
  return v7;
}
