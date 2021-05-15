// PopDiagTraceFxPerfRegistration 
 
int __fastcall PopDiagTraceFxPerfRegistration(int a1)
{
  return EtwWrite(PopDiagHandle, dword_61E154, a1, 0);
}
