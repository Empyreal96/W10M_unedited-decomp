// PspWaitForUsermodeExit 
 
int __fastcall PspWaitForUsermodeExit(int a1)
{
  int i; // r1
  _DWORD *v3; // r0
  unsigned int v4; // r4

LABEL_1:
  for ( i = 0; ; i = (int)v3 )
  {
    v3 = PsGetNextProcessThread(a1, i);
    v4 = (unsigned int)v3;
    if ( !v3 )
      break;
    if ( (v3[19] & 0x400) == 0 && !*((_BYTE *)v3 + 4) )
    {
      ObfReferenceObject((int)v3);
      ObfDereferenceObjectWithTag(v4);
      KeWaitForSingleObject(v4, 0, 0, 0, 0);
      ObfDereferenceObject(v4);
      goto LABEL_1;
    }
  }
  return 0;
}
