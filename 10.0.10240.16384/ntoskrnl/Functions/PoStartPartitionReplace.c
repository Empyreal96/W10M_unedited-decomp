// PoStartPartitionReplace 
 
int __fastcall PoStartPartitionReplace(int a1, int a2)
{
  int _10; // [sp+10h] [bp+8h]
  int varsC; // [sp+14h] [bp+Ch] BYREF

  _10 = a1;
  varsC = a2;
  PopSuspendResumePdc(1);
  *(_DWORD *)(a1 + 16) = 10;
  PopDispatchStateCallout(a1, (int)&varsC);
  *(_DWORD *)(a1 + 16) = 9;
  return PopDispatchStateCallout(a1, 0);
}
