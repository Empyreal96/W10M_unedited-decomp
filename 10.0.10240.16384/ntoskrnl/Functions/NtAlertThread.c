// NtAlertThread 
 
int __fastcall NtAlertThread(int a1)
{
  int v1; // r4
  int result; // r0
  int v3[4]; // [sp+10h] [bp-10h] BYREF

  v1 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  result = ObReferenceObjectByHandleWithTag(a1, 4, PsThreadType, v1, 1968403280, v3, 0);
  if ( result >= 0 )
  {
    KeAlertThread(v3[0], v1);
    ObfDereferenceObjectWithTag(v3[0]);
    result = 0;
  }
  return result;
}
