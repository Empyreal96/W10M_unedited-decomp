// IopThreadStart 
 
int __fastcall IopThreadStart(int *a1)
{
  int v2; // [sp+0h] [bp-10h]
  void (__fastcall *v3)(int); // [sp+4h] [bp-Ch]
  int v4; // [sp+8h] [bp-8h]

  v2 = *a1;
  v3 = (void (__fastcall *)(int))a1[1];
  v4 = a1[2];
  ExFreePoolWithTag((unsigned int)a1);
  v3(v4);
  ObfDereferenceObject(v2);
  return PsTerminateSystemThread(0);
}
