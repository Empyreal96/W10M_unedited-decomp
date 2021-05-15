// MiInitMachineDependent 
 
void MiInitMachineDependent()
{
  int v0; // r2
  __int64 v1; // r2
  int v2; // r1

  v0 = __mrc(15, 0, 2, 0, 0);
  LODWORD(v1) = v0 & 0xFFFFC000 | KiTbrConfiguration;
  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  HIDWORD(v1) = -65536;
  *(_QWORD *)(v2 + 28) = v1;
  *(_DWORD *)(v2 + 24) = MEMORY[0xC0300C00] & 0xFFFFF000;
}
