// sub_818BD0 
 
void sub_818BD0()
{
  int v0; // r4
  __int64 v1; // kr00_8

  v1 = *(_QWORD *)&PopDiagHandle;
  if ( EtwEventEnabled(PopDiagHandle, dword_61E154, v0) )
    EtwWrite(v1, SHIDWORD(v1), v0, 0);
  JUMPOUT(0x7B3C96);
}
