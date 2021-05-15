// NtSetIoCompletion 
 
int __fastcall NtSetIoCompletion(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v8[0] = a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 2, IoCompletionObjectType, v5, v8);
  if ( v6 >= 0 )
  {
    v6 = IoSetIoCompletion(v8[0], a2);
    ObfDereferenceObject(v8[0]);
  }
  return v6;
}
