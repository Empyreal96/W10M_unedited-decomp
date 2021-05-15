// MiPerformCombineScan 
 
int __fastcall MiPerformCombineScan(int a1, int a2, _QWORD *a3, int a4)
{
  *a3 = MiComputeHash64(*(_DWORD *)(a2 + 28) << 10);
  return 1;
}
