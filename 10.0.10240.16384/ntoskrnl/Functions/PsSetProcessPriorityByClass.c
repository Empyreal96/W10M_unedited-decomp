// PsSetProcessPriorityByClass 
 
int __fastcall PsSetProcessPriorityByClass(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  char v7[4]; // [sp+0h] [bp-10h] BYREF
  int v8[3]; // [sp+4h] [bp-Ch] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = PspComputeQuantumAndPriority(a1, a2, v7, v8);
  return KeSetPriorityAndQuantumProcess(a1, v5, v7[0], v8[0]);
}
