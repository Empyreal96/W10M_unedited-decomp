// DbgkpFreeDebugEvent 
 
unsigned int __fastcall DbgkpFreeDebugEvent(int *a1)
{
  int v2; // r3
  int v3; // r0

  v2 = a1[20];
  if ( v2 == 2 )
  {
    v3 = a1[23];
  }
  else
  {
    if ( v2 != 5 )
      goto LABEL_7;
    v3 = a1[22];
  }
  if ( v3 )
    ObCloseHandle(v3);
LABEL_7:
  ObfDereferenceObjectWithTag(a1[8]);
  ObfDereferenceObjectWithTag(a1[9]);
  return ExFreePoolWithTag((unsigned int)a1);
}
