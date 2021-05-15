// NtResumeProcess 
 
int __fastcall NtResumeProcess(int a1)
{
  int v1; // r3
  int v2; // r4
  int v4[4]; // [sp+10h] [bp-10h] BYREF

  v1 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v2 = ObReferenceObjectByHandleWithTag(a1, 2048, PsProcessType, v1, 1968403280, v4, 0);
  if ( v2 >= 0 )
  {
    v2 = PsResumeProcess(v4[0]);
    ObfDereferenceObjectWithTag(v4[0]);
  }
  return v2;
}
