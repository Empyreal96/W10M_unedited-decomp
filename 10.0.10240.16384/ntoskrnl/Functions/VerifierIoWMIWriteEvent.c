// VerifierIoWMIWriteEvent 
 
int __fastcall VerifierIoWMIWriteEvent(unsigned int *a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r6
  unsigned int v5; // r0

  if ( !WmiVerifierTakeEventOwnership((int)a1) )
    return pXdvIoWMIWriteEvent(a1);
  v3 = WmiVerifierCopyEvent(a1);
  v4 = v3;
  if ( !v3 )
    return -1073741670;
  v2 = pXdvIoWMIWriteEvent(v3);
  v5 = (unsigned int)a1;
  if ( v2 < 0 )
    v5 = v4;
  ExFreePoolWithTag(v5);
  return v2;
}
