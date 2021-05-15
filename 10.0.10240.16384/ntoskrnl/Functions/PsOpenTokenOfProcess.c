// PsOpenTokenOfProcess 
 
int __fastcall PsOpenTokenOfProcess(int a1, _DWORD *a2)
{
  int v3; // r3
  int result; // r0
  int v5[4]; // [sp+10h] [bp-10h] BYREF

  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  result = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v3, 1699967824, v5, 0);
  if ( result >= 0 )
  {
    *a2 = PsReferencePrimaryToken(v5[0]);
    ObfDereferenceObjectWithTag(v5[0]);
    result = 0;
  }
  return result;
}
