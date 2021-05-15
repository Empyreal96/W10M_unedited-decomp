// PoEndPartitionReplace 
 
int __fastcall PoEndPartitionReplace(int a1, int a2)
{
  int v3; // [sp+Ch] [bp-4h] BYREF

  v3 = a2;
  *(_DWORD *)(a1 + 16) = 11;
  PopDispatchStateCallout(a1, (int)&v3);
  return PopSuspendResumePdc(0);
}
